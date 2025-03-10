FOLDER_PATH=keyboards/crkbd/keymaps/jialu/
SRC += $(FOLDER_PATH)/jialu.c \
       $(FOLDER_PATH)/callbacks.c

# https://github.com/manna-harbour/qmk_firmware/blob/crkbd/keyboards/crkbd/keymaps/manna-harbour/readme.org

SPLIT_KEYBOARD=yes
BOOTLOADER=rp2040
# BOOTLOADER=atmel-dfu
# BOOTLOADER=caterina

### WPM config
WPM_ENABLE=yes
WPM_ALLOW_COUNT_REGRESSION=yes
WPM_SAMPLE_SECONDS=5
WPM_SAMPLE_PERIODS=5
WPM_LAUNCH_CONTROL=yes

#MH_MODULE=trackpoint
#MH_MODULE=oled
#MH_MODULE=oled_old
MH_MODULE=no

UNICODE_ENABLE=no

COMBO_ENABLE=yes

MH_AUTO_BUTTONS=no
OLED_ENABLE=yes

ifeq ($(strip $(MH_MODULE)), trackpoint)
  MH_AUTO_BUTTONS=yes
  OLED_ENABLE=no
endif

ifeq ($(strip $(MH_MODULE)), no_oled)
  OLED_ENABLE=no
endif

MH_RGB=matrix
#MH_RGB=backlight
#MH_RGB=underglow

DEBUG=no
MH_DEBUG=no
LTO_ENABLE=yes

MH_LOW_MOUSE=no
MH_OLED_MODE=no
MH_OLED_IMAGE=no

CUSTOM_SPLIT_TRANSPORT_SYNC=no


ifeq ($(strip $(MH_MODULE)), trackpoint)
  PS2_MOUSE_ENABLE = yes
  PS2_USE_INT = yes
  OPT_DEFS += -DMH_MODULE_TRACKPOINT
else ifeq ($(strip $(MH_MODULE)), oled)
  OLED_DRIVER_ENABLE = yes
else ifeq ($(strip $(MH_MODULE)), oled_old)
  SRC += ./lib/glcdfont.c
  SRC += ./lib/logo_reader.c
  OPT_DEFS += -DSSD1306OLED
endif

ifeq ($(strip $(MH_AUTO_BUTTONS)), yes)
  MOUSEKEY_ENABLE = yes
  OPT_DEFS += -DMH_AUTO_BUTTONS
endif

ifeq ($(strip $(MH_LOW_MOUSE)), yes)
  OPT_DEFS += -DMH_LOW_MOUSE
endif

ifeq ($(strip $(MH_OLED_MODE)), static)
  OPT_DEFS += -DMH_OLED_MODE_STATIC
else ifeq ($(strip $(MH_OLED_MODE)), caps)
  OPT_DEFS += -DMH_OLED_MODE_CAPS
endif


ifeq ($(strip $(MH_RGB)), matrix)
  RGB_MATRIX_ENABLE = yes
  RGB_MATRIX_DRIVER = ws2812
  SRC += $(FOLDER_PATH)/rgb_matrix_stuff.c
  OPT_DEFS += -DCUSTOM_RGB_MATRIX
else ifeq ($(strip $(MH_RGB)), light)
  RGBLIGHT_ENABLE = yes
else ifeq ($(strip $(MH_RGB)), underglow)
  RGBLIGHT_ENABLE = yes
  OPT_DEFS += -DMH_RGB_UNDERGLOW
endif

ifeq ($(strip $(MH_DEBUG)), yes)
  CONSOLE_ENABLE=yes
  OPT_DEFS += -DMH_DEBUG
endif

ifeq ($(strip $(CUSTOM_SPLIT_TRANSPORT_SYNC)), yes)
  SRC += $(FOLDER_PATH)/transport_sync.c
  OPT_DEFS += -DCUSTOM_SPLIT_TRANSPORT_SYNC
endif
