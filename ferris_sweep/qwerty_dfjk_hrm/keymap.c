#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#define NAV_KEY LT(NAV, KC_BSPC)
#define SYM_KEY LT(SYM, KC_SPC)
#define NUM_KEY LT(NUM, KC_ENT)
#define ESC_KEY KC_ESC

#define HR_A LSFT_T(KC_A)
#define HR_S LALT_T(KC_S)
#define HR_D LCTL_T(KC_D)
#define HR_F LCMD_T(KC_F)
#define HR_J LCMD_T(KC_J)
#define HR_K LCTL_T(KC_K)
#define HR_L LALT_T(KC_L)
#define HR_ESC LSFT_T(KC_ESC),

enum { QWERTY, NAV, SYM, NUM } layers;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Letters and (home row) modifiers
    [QWERTY] = LAYOUT_split_3x5_2(
                            KC_Q, KC_W, KC_E, KC_R, KC_T,                  KC_Y, KC_U, KC_I, KC_O, KC_P,
                            HR_A, HR_S, HR_D, HR_F, KC_G,                  KC_H, HR_J, HR_K, HR_L, HR_ESC,
                            KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                                        ESC_KEY, SYM_KEY,                  NAV_KEY, NUM_KEY
                            ),

    // Arrows keys and navigation            
    [NAV] = LAYOUT_split_3x5_2(
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_LEFT, KC_RGHT, KC_HOME,       KC_END, KC_DOWN, KC_UP, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO,
                                                 KC_NO, KC_NO,             KC_NO, KC_NO
                            ),

    // Symbols
    [SYM] = LAYOUT_split_3x5_2(
                           KC_EXLM, KC_AT, KC_HASH, KC_UNDS, KC_PMNS,      KC_PPLS, KC_PSLS, KC_PAST, KC_PEQL, KC_QUES,
                           KC_LT, KC_NO, KC_LCBR, KC_LPRN, KC_AT,          KC_BSLS, KC_RPRN, KC_RCBR, KC_NO, KC_GT,
                           KC_PLUS, KC_NO, KC_PERC, KC_CIRC, KC_NO,        KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,
                                                      KC_NO, KC_NO,        KC_NO, KC_NO
                           ),

    // Numbers and function keys
    [NUM] = LAYOUT_split_3x5_2(
                           KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
                           KC_P1, KC_P2, KC_P3, KC_P4, KC_P5,              KC_P6, KC_P7, KC_P8, KC_P9, KC_P0,
                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                KC_NO, KC_NO,              KC_NO, KC_NO
                           )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
