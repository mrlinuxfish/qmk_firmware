OLED_DRIVER_ENABLE = no    # Enables the use of OLED displays
ENCODER_ENABLE = no        # ENables the use of one or more encoders
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes      # Audio control and System control
# BOOTMAGIC_ENABLE = lite    # Bootmagic lite (only reset)
WPM_ENABLE = no            # Allows the keyboard to display wpm
UNICODE_ENABLE = yes       # Add unicode support (emoji are currently not supported)
STENO_ENABLE = yes

# Autoshift and combos do not play nicely with homerow mods. Only one should be
# enabled at a time
# AUTO_SHIFT_ENABLE = yes    # Turn on autoshift

VPATH  +=  keyboards/gboards/
EXTRAFLAGS=-DCOMBO_VARIABLE_LEN
COMBO_ENABLE = yes
COMBO_ALLOW_ACTION_KEYS = yes
