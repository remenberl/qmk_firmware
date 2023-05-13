A good amount of this configuration is forked from `crkbd:manna-harbour` or `crkbd:default`.

## Environment Setup
```
$ arch -x86_64 brew install qmk/qmk/qmk
$ arch -x86_64 brew install avr-gcc
```

## Build Keymap
Left: 
```
$ sudo make crkbd:jialu:avrdude BOOTLOADER=caterina MH_MODULE=no_oled
```
Right:
```
sudo make crkbd:jialu:dfu BOOTLOADER=qmk-dfu
```

Push the reset button
