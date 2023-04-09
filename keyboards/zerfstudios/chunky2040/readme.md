ZERF9

ARM split keyboard using an STM32F411.

* Keyboard Maintainer: [freznel10](https://github.com/freznel10)
* Hardware Supported: STM32F411 blackpill, Cirque trackpad, PIM374 OLED, SPI EEPROM
* Hardware Availability: Zerf9


Make example for this keyboard (after setting up your build environment):

    make freznel/zerf9/mx_track:default

Flashing example for this keyboard:

    make freznel/zerf9/mx_track:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset buttons**: Hold down the BOOT0 button and then briefly press the NRST button on the BlackPill PCB.
* **Keycode in layout**: Press the key mapped to `RESET` if it is availabe.

