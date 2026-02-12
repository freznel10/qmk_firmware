#include "i2c_master.h"
#    include "print.h"
#    include "debug.h"
#include <string.h>
#include "adps9660.h"
#include <stdio.h>


#define ADPS9660_ADDRESS (0x39 << 1)
#define ADPS9660_TIMEOUT 100

#define ADPS9660_REG_ENABLE 0x80
#define ADPS9660_REG_ENABLE_GEN (1 << 6) // Gesture enable
#define ADPS9660_REG_ENABLE_PIEN (1 << 5) // Proximity interrupt enable
#define ADPS9660_REG_ENABLE_AIEN (1 << 4) // ALS interrupe enable
#define ADPS9660_REG_ENABLE_WEN (1 << 3) // Wait enable
#define ADPS9660_REG_ENABLE_PEN (1 << 2) // Proximity detect enable
#define ADPS9660_REG_ENABLE_AEN (1 << 1) // ALS enable
#define ADPS9660_REG_ENABLE_PON 1 // Power on
#define ADPS9660_REG_CTRL1 0x8F
#define ADPS9660_REG_CTRL1_LDRIVE(__v__) ((__v__) << 6) // LED drive strength. 0: 100mA, 1: 50mA, 2: 25mA, 3: 12.5mA
#define ADPS9660_REG_CTRL1_PGAIN(__v__) ((__v__) << 2) // Proximity gain control. 0: 1x, 2: 2x, 3: 4x, 4: 8x
#define ADPS9660_REG_CTRL2 0x90
#define ADPS9660_REG_CTRL2_BASE (1u) // First bit is reserved, should be written as 1.
#define ADPS9660_REG_CTRL2_LED_BOOST(__v__) ((__v__) << 4) // Additional LDR current during proximity and gesture. 0: 100%, 1: 150%, 2: 200%, 3: 300%.

#define ADPS9660_REG_ID 0x92

#define ADPS9660_REG_PDATA 0x9C

void adps9660_id(uint8_t *id) {
i2c_read_register(ADPS9660_ADDRESS, ADPS9660_REG_ID, id, 1, ADPS9660_TIMEOUT);
//   if (stat) {
//     return stat;
//     dprintf("Success %d", stat);
//   }

}

void adps9660_init(void) {
  uint8_t data = ADPS9660_REG_ENABLE_PON | ADPS9660_REG_ENABLE_AEN | ADPS9660_REG_ENABLE_PEN;

  i2c_write_register(ADPS9660_ADDRESS, ADPS9660_REG_ENABLE, &data, 1, ADPS9660_TIMEOUT);

  data = ADPS9660_REG_CTRL1_LDRIVE(1) | ADPS9660_REG_CTRL1_PGAIN(4);
    i2c_write_register(ADPS9660_ADDRESS, ADPS9660_REG_CTRL1, &data, 1, ADPS9660_TIMEOUT);

  data = ADPS9660_REG_CTRL2_BASE | ADPS9660_REG_CTRL2_LED_BOOST(3);
    i2c_write_register(ADPS9660_ADDRESS, ADPS9660_REG_CTRL2, &data, 1, ADPS9660_TIMEOUT);

  dprintf("Success");

//   return 0;
}

void adps9660_proximity(uint8_t *data) {

i2c_read_register(ADPS9660_ADDRESS, ADPS9660_REG_PDATA, data, 1, ADPS9660_TIMEOUT);

//   if (stat) {
//     return stat;
//   }

  //i2c_stop();

//   return 0;
}

void adps9660_sleep(void) {


  uint8_t data;

 i2c_read_register(ADPS9660_ADDRESS, ADPS9660_REG_ENABLE, &data, 1, ADPS9660_TIMEOUT);

  data &= (~ADPS9660_REG_ENABLE_PON);
    i2c_write_register(ADPS9660_ADDRESS, ADPS9660_REG_ENABLE, &data, 1, ADPS9660_TIMEOUT);
//   if (stat) {
//     return stat;

//   }
  dprintf("sleep");
//   return 0;
}

void adps9660_wake(void) {

  uint8_t data;

i2c_read_register(ADPS9660_ADDRESS, ADPS9660_REG_ENABLE, &data, 1, ADPS9660_TIMEOUT);

  data |= ADPS9660_REG_ENABLE_PON;

i2c_write_register(ADPS9660_ADDRESS, ADPS9660_REG_ENABLE, &data, 1, ADPS9660_TIMEOUT);
//   if (stat) {
//     return stat;
//   }

//   return 0;
}
