// /*
//  * ----------------------------------------------------------------------------
//  * "THE BEER-WARE LICENSE" (Revision 42):
//  * <https://github.com/KarlK90> wrote this file.  As long as you retain this
//  * notice you can do whatever you want with this stuff. If we meet some day, and
//  * you think this stuff is worth it, you can buy me a beer in return. KarlK90
//  * ----------------------------------------------------------------------------
//  */

// #include "matrix.h"
// #include "atomic_util.h"
// #include "gpio.h"

// #define ROWS_PER_HAND (MATRIX_ROWS / 2)
// static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
// static const pin_t col_pins[MATRIX_COLS]   = MATRIX_COL_PINS;

// void matrix_init_pins(void) {
//     for (size_t i = 0; i < MATRIX_COLS; i++) {
//         setPinInputHigh(col_pins[i]);
//     }
//     for (size_t i = 0; i < ROWS_PER_HAND; i++) {
//         setPinOutput(row_pins[i]);
//         writePinHigh(row_pins[i]);
//     }
// }

// void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
//     /* Drive row pin low. */
//     ATOMIC_BLOCK_FORCEON { writePinLow(row_pins[current_row]); }
//     matrix_output_select_delay();

//     /* Read all columns in one go, aka port scanning. */
//     uint16_t porta = palReadPort(GPIOA);

// // clang-format off
//     /* Order of pins on the mun is: A0, B11, B0, B10, B12, B2, A8
//         Pin is active low, therefore we have to invert the result. */

//     matrix_row_t cols = ~(((porta & (0x1 << 8)) >> 8)   // B13 (0)
//                         | ((porta & (0x1 << 7)) >> 6)   // B14 (1)
//                         | ((porta & (0x1 << 5)) >> 3)   // B15 (2)
//                         | ((porta & (0x1 << 22)) >> 19)   // A8  (3)
//                         | ((porta & (0x1 << 23)) >> 19)   // A10 (4)
//                         | ((porta & (0x1 << 26)) >>  21));   // A13 (5)
//                         // | ((porta & (0x1 << 13)) >>  7)   // C13 (6)
//                         // | ((porta & (0x1 << 14)) >>  7)); // C14 (7)

//     current_matrix[current_row] = cols;

//     /* Drive row pin high again. */
//     ATOMIC_BLOCK_FORCEON { writePinHigh(row_pins[current_row]); }
//     matrix_output_unselect_delay(current_row, cols != 0);
// }

// #if defined(BUSY_WAIT)
void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    for (int32_t i = 0; i < 40; i++) {
        __asm__ volatile("nop" ::: "memory");
    }
}
// #endif



void matrix_io_delay(void) {
    __asm__ volatile("nop\nnop\nnop\n");
}

// void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
//     for (int32_t i = 0; i < 40; i++) {
//         __asm__ volatile("nop" ::: "memory");
//     }
