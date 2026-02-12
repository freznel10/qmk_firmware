/* Copyright 2023 Freznel B. Sta. Ana <freznel@gmail.com> (@freznel10)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define STUSB4500_ADDRESS (0x28 << 1)



void i2c_init(void)

typedef struct {
  uint16_t v1; // Voltage for first preference - mapping in read_config()
  uint8_t i1; // Current for first preference - mapping in current lookup table of STUSB4500 datasheet
  uint16_t v2; // Voltage for second preference - mapping in read_config()
  uint8_t i2; // Current for second preference - mapping in current lookup table of STUSB4500 datasheet
  bool req_pd; // If true, requires source to be PD capable before enabling output
} stusb4500_config;


//  read_config blocks until a successful configuration is read from the
// light sensor and returns it.
stusb4500_config read_config() {
  uint16_t voltage_map[] = {5 * 20, 9 * 20, 12 * 20, 15 * 20, 20 * 20};
  enum { packet_len = 4 };
  uint8_t packet[packet_len];
  static uint16_t ptp_buffer[packet_len * 8];
  static uint8_t ptp_next_bit_pos;
  while (1) {
    read_packet(packet, ptp_buffer, &ptp_next_bit_pos, packet_len);
    if (packet[0] & 0b10000000) {
      continue;
    }
    stusb4500_config c;
    c.v1 = (packet[0] >> 4) & 0b111;
    c.v2 = (packet[1] >> 4) & 0b111;
    if (c.v1 > 4 || c.v2 > 4) {
      continue;
    }
    c.v1 = voltage_map[c.v1];
    c.v2 = voltage_map[c.v2];
    c.i1 = packet[0] & 0xf;
    c.i2 = packet[1] & 0xf;
    if (c.i1 == 0 || c.i2 == 0) {
      continue;
    }
    c.req_pd = packet[1] >> 7;
    return c;
  }
}

// stusb4500_flash flashes the given configuration onto STUSB4500 NVRAM
// and returns true if successful, false otherwise.
bool stusb4500_flash(stusb4500_config cfg) {
  uint8_t nvm[] = {
    0x00, 0x00, 0xB0, 0xAA, 0x00, 0x45, 0x00, 0x00,
    0x10, 0x40, 0x9C, 0x1C, 0xFF, 0x01, 0x3C, 0xDF,
    0x02, 0x40, 0x0F, 0x00, 0x32, 0x00, 0xFC, 0xF1,
    // default: 0x00, 0x19, 0x56, 0xAF, 0xF5, 0x35, 0x5F, 0x00
    // changed to 15% lower voltage threshold from 20% for PDO2 & PDO3
    0x00, 0x19, 0x56, 0xAF, 0xA5, 0x35, 0x5A, 0x00,
    0x00, 0x4B, 0x90, 0x21, 0x43, 0x00, 0x40, 0xFB
  };
  nvm[0x1D] = (nvm[0x1D] & 0x0F) | cfg.i1 << 4;
  nvm[0x1C] = (nvm[0x1C] & 0xF0) | cfg.i2;
  nvm[0x22] = cfg.v1 & 0xFF;
  nvm[0x23] = (nvm[0x23] & 0b11111100) | (cfg.v1 >> 8);
  nvm[0x20] = (nvm[0x20] & 0b11000000) | ((cfg.v2 & 0b11) << 6);
  nvm[0x21] = cfg.v2 >> 2;
  if (cfg.req_pd) {
    nvm[0x26] |= 0b1000;
  }

  // STUSB4500 seems to pull down the SDA on reset and that messes
  // with internal state of the TWI. Therefore explicitly put the bus
  // into idle state.
  TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc;

  enum { addr = 0x28 };
  // Flash
  if (!i2c_reg_write(addr, 0x95, 0x47)) return false;
  if (!i2c_reg_write(addr, 0x53, 0x00)) return false;
  if (!i2c_reg_write(addr, 0x96, 0x40)) return false;
  if (!i2c_reg_write(addr, 0x96, 0x00)) return false;
  delay(4);
  if (!i2c_reg_write(addr, 0x96, 0x40)) return false;
  if (!i2c_reg_write(addr, 0x97, 0xFA)) return false;
  if (!i2c_reg_write(addr, 0x96, 0x50)) return false;
  delay(4);
  if (!i2c_reg_write(addr, 0x97, 0x07)) return false;
  if (!i2c_reg_write(addr, 0x96, 0x50)) return false;
  delay(20);
  if (!i2c_reg_write(addr, 0x97, 0x05)) return false;
  if (!i2c_reg_write(addr, 0x96, 0x50)) return false;
  delay(20);
  for (uint8_t i = 0; i < 5; i++) {
    uint8_t buf[9] = {0x53};
    memcpy(buf + 1, nvm + (i * 8), 8);
    if (!i2c_tx(addr, buf, 9, NULL, 0)) return false;
    delay(4);
    if (!i2c_reg_write(addr, 0x97, 0x01)) return false;
    if (!i2c_reg_write(addr, 0x96, 0x50)) return false;
    delay(4);
    if (!i2c_reg_write(addr, 0x97, 0x06)) return false;
    if (!i2c_reg_write(addr, 0x96, 0x50 + i)) return false;
    delay(8);
  }
  uint8_t buf[3] = {0x96, 0x40, 0x00};
  if (!i2c_tx(addr, buf, 3, NULL, 0)) return false;
  if (!i2c_reg_write(addr, 0x95, 0x00)) return false;

  return true;
}

// stusb4500_reset resets the STUSB4500. This also results in loss of
// power to the entire board while STUSB4500 boots up again, effectively
// resetting the uC as well.
bool stusb4500_reset() {
  enum { addr = 0x28 };
  return i2c_reg_write(addr, 0x23, 0x01);
}

void setup() {
  // Disable clock pre-scaler
  CPU_CCP = CCP_IOREG_gc;
  CLKCTRL.MCLKCTRLB = 0;

  // Configure a timer to overflow 10K times per second
  TCA0.SINGLE.PER = 2000;
  TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1_gc | TCA_SINGLE_ENABLE_bm;

  // Configure ADC
  ADC0.CTRLC = ADC_REFSEL_VDDREF_gc | ADC_PRESC_DIV32_gc;
  ADC0.MUXPOS = SENSOR_ADC_MUXPOS;
  ADC0.CTRLA = ADC_ENABLE_bm;

  // Configure notification pin
  NOTIFY_PORT.DIRSET = NOTIFY_PIN_BM;
  NOTIFY_PORT.OUTCLR = NOTIFY_PIN_BM;

  // Configure I2C pull-up sources
  SCL_PULLUP_SRC_PORT.DIRSET = SCL_PULLUP_SRC_PIN_BM;
  SCL_PULLUP_SRC_PORT.OUTSET = SCL_PULLUP_SRC_PIN_BM;
  SDA_PULLUP_SRC_PORT.DIRSET = SDA_PULLUP_SRC_PIN_BM;
  SDA_PULLUP_SRC_PORT.OUTSET = SDA_PULLUP_SRC_PIN_BM;

  // Configure light sensor pull-up source
  SENSOR_PULLUP_SRC_PORT.DIRSET = SENSOR_PULLUP_SRC_PIN_BM;
  SENSOR_PULLUP_SRC_PORT.OUTSET = SENSOR_PULLUP_SRC_PIN_BM;

  i2c_init();
}

// notify notifies the user that programming is successfully completed
// by flashing the green light on the top side of the board.
void notify() {
  for (uint8_t i = 0; i < 10; i++) {
    NOTIFY_PORT.OUTSET = NOTIFY_PIN_BM;
    delay(100);
    NOTIFY_PORT.OUTCLR = NOTIFY_PIN_BM;
    delay(100);
  }
}

int main(void) {
  setup();
  // Sync to peak
  wait_on_edge();
  while (1) {
    stusb4500_config cfg = read_config();
    bool flash_success = stusb4500_flash(cfg);
    if (flash_success) {
      notify();
      stusb4500_reset();
    }
  }
}


