OLED_ENABLE = yes
RGB_MATRIX_ENABLE = yes     # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
REPEAT_KEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
TRI_LAYER_ENABLE = yes

SRC += oneshot.c
SRC += swapper.c
