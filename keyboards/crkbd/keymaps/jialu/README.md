A good amount of this configuration is forked from `crkbd:manna-harbour` or `crkbd:default`.

## Environment Setup
```
$ arch -x86_64 brew install qmk/qmk/qmk
$ arch -x86_64 brew install avr-gcc
```

## Build Keymap
Left: 
```
$ qmk flash -kb crkbd -km jialu -e CONVERT_TO=kb2040 -j 0
```
Right:
```
$ qmk flash -kb crkbd -km jialu -e CONVERT_TO=blok -j 0
```

Push the reset button
