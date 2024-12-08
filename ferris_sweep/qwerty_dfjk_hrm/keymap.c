#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "../td.c"

#define NAV_KEY LT(NAV, KC_BSPC)
#define SYM_KEY LT(SYM, KC_ESC)
#define NUM_KEY LT(NUM, KC_ENT)
#define ALT_KEY LALT_T(KC_SPC)

#define FLASH QK_BOOT

#define HR_A LCTL_T(KC_A)
#define HR_S LSFT_T(KC_S)

#define HR_L RSFT_T(KC_L)
#define HR_SCLN LCTL_T(SE_SCLN)

// Define keycodes for symbols with Swedish layout
// ;
#define SE_SCLN S(KC_COMM)
// /
#define SE_SLSH S(KC_7)
// +
#define SE_PLUS KC_MINS
// -
#define SE_MINS KC_SLSH
#define SE_AT ALGR(KC_2)
// @
#define SE_DLR ALGR(KC_4)
// :
#define SE_COLN S(KC_DOT)
// (
#define SE_LPRN S(KC_8)
// [
#define SE_LBRC ALGR(KC_8)
// )
#define SE_RPRN S(KC_9)
// ]
#define SE_RBRC ALGR(KC_9)
// =
#define SE_EQL S(KC_0)
// `
#define SE_GRV S(KC_EQL)
// ^
#define SE_CIRC S(KC_RBRC)
// &
#define SE_AMPR S(KC_6)
// *
#define SE_ASTR S(KC_NUHS)
// ~
#define SE_TILD ALGR(KC_RBRC)
// Backslash
#define SE_BSLS ALGR(KC_MINS)
// "
#define SE_DQUO S(KC_2)
// '
#define SE_APOS KC_NUHS
// {
#define SE_LCBR ALGR(KC_7)
// }
#define SE_RCBR ALGR(KC_0)
// ?
#define SE_QUES S(KC_MINS)
// |
#define SE_PIPE ALGR(KC_NUBS)
// <
#define SE_LESS KC_NUBS
// >
#define SE_GRTR S(KC_NUBS)
// §
#define SE_SECT KC_GRV
// _
#define SE_UNDS S(KC_SLASH)

#define SWE_KEY LT(SWE, KC_Z)

const uint16_t PROGMEM switcher_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM launcher_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM term_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    COMBO(switcher_combo, LALT(KC_H)),
    COMBO(launcher_combo, LALT(KC_S)),
    COMBO(term_combo, KC_LGUI),
};

enum { QWERTY, NAV, SYM, NUM, SWE, WNAV } layers;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Letters and (home row) modifiers
    [QWERTY] = LAYOUT_split_3x5_2(
                            TD(TD_Q_TAB),    KC_W, KC_E, KC_R,    KC_T,           KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,
                            HR_A,    HR_S, KC_D, KC_F,    KC_G,           KC_H,    KC_J,   KC_K,    HR_L,   SE_SCLN,
                            SWE_KEY, KC_X, KC_C, KC_V,    KC_B,           KC_N,    KC_M,   KC_COMM, KC_DOT, KC_PSLS,
                                                 SYM_KEY, ALT_KEY,        NAV_KEY, NUM_KEY
                            ),

    // Arrows keys and navigation            
    [NAV] = LAYOUT_split_3x5_2(
                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
                            KC_LCTL, KC_LSFT, KC_LEFT, KC_RGHT, KC_HOME,           KC_END, KC_DOWN, KC_UP,   KC_LSFT, KC_LCTL,
                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,  KC_PGDN, KC_PGUP, KC_NO,   KC_NO,
                                                       KC_NO,   MO(WNAV),          KC_NO,  KC_NO
                            ),

    // Symbols
    [SYM] = LAYOUT_split_3x5_2(
                         //  !           @         #           $          %               /           =          -           +           ? 
                           KC_EXLM,    SE_AT,    KC_HASH,    SE_DLR,    KC_PERC,        KC_PSLS,    SE_EQL,    KC_PMNS,    SE_PLUS,    SE_QUES,
                         //  <           [         {           (          '               "           )          }           ]           >
                           SE_LESS,    SE_LBRC,  SE_LCBR,    SE_LPRN,   SE_APOS,        SE_DQUO,    SE_RPRN,   SE_RCBR,    SE_RBRC,    SE_GRTR,
                         //  |           ^         *           §          `              \\           ~          ,           .           _
                           SE_PIPE,    SE_CIRC,  SE_ASTR,    SE_SECT,   SE_GRV,         SE_BSLS,    SE_TILD,   KC_TRNS,    KC_TRNS,    SE_UNDS,
                                                             KC_NO,     FLASH,          MO(WNAV),   KC_NO
                           ),

    // Numbers and function keys
    [NUM] = LAYOUT_split_3x5_2(
                           KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
                           KC_1,  KC_2,  KC_3,  KC_4,  KC_5,               KC_6,  KC_7,  KC_8,  KC_9,  KC_0,
                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                KC_NO, KC_NO,              FLASH, KC_NO
                           ),

    // Swedish letters
    [SWE] = LAYOUT_split_3x5_2(
                           KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,
                           KC_NO, TD(TD_OE), TD(TD_AE), TD(TD_AA), KC_NO,        KC_NO, TD(TD_AA), TD(TD_AE), TD(TD_OE), KC_NO,
                           KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,
                                                        KC_NO,     KC_NO,        KC_NO, KC_NO
                           ),

    // Window and workspace navigation
    [WNAV] = LAYOUT_split_3x5_2(
                           LSA(KC_1), LSA(KC_2), LSA(KC_3), LSA(KC_4), LSA(KC_5),         LSA(KC_6), LSA(KC_7), LSA(KC_8), LSA(KC_9), LSA(KC_0),
                           A(KC_1),   A(KC_2),   A(KC_3),   A(KC_4),   A(KC_5),           A(KC_6),   A(KC_7),   A(KC_8),   A(KC_9),   A(KC_0),
                           KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,             KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
                                                            KC_NO,     KC_NO,             KC_NO,     KC_NO
                           )

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
