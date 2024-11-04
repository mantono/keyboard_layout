#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "../td.c"

#define NAV_KEY LT(NAV, KC_BSPC)
#define SYM_KEY LT(SYM, KC_SPC)
#define NUM_KEY LT(NUM, KC_ENT)
#define ESC_KEY KC_ESC

#define FLASH QK_BOOT

#define HR_A LSFT_T(KC_A)
#define HR_S LALT_T(KC_S)
#define HR_D LCTL_T(KC_D)
#define HR_F LCMD_T(KC_F)
#define HR_J LCMD_T(KC_J)
#define HR_K LCTL_T(KC_K)
#define HR_L LALT_T(KC_L)
#define HR_SCLN RSFT_T(SE_SCLN)

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
#define SE_UNDS S(KC_SLSH)
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

#define SWE_KEY LT(SWE, KC_Z)

const uint16_t PROGMEM switcher_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM launcher_combo[] = {KC_D, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(switcher_combo, LALT(KC_H)),
    COMBO(launcher_combo, LALT(KC_S)),
};

enum { QWERTY, NAV, SYM, NUM, SWE, WNAV } layers;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Letters and (home row) modifiers
    [QWERTY] = LAYOUT_split_3x5_2(
                            KC_Q, KC_W, KC_E, KC_R, KC_T,                  KC_Y, KC_U, KC_I, KC_O, KC_P,
                            HR_A, HR_S, HR_D, HR_F, KC_G,                  KC_H, HR_J, HR_K, HR_L, HR_SCLN,
                            SWE_KEY, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_TAB,
                                        ESC_KEY, SYM_KEY,                  NAV_KEY, NUM_KEY
                            ),

    // Arrows keys and navigation            
    [NAV] = LAYOUT_split_3x5_2(
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_LEFT, KC_RGHT, KC_HOME,       KC_END, KC_DOWN, KC_UP, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO,
                                                 KC_NO, MO(WNAV),          KC_NO, FLASH
                            ),

    // Symbols
    [SYM] = LAYOUT_split_3x5_2(
                         //  !           @         #           $          %               /           =          -           +           ? 
                           KC_EXLM,    SE_AT,    KC_HASH,    SE_DLR,    KC_PERC,        KC_PSLS,    SE_EQL,    KC_PMNS,    SE_PLUS,    SE_QUES,
                         //  <           [         {           (          '               "           )          }           ]           >
                           SE_LESS,    SE_LBRC,  SE_LCBR,    SE_LPRN,   SE_APOS,        SE_DQUO,    SE_RPRN,   SE_RCBR,    SE_RBRC,    SE_GRTR,
                         //  |           ^         *           §          `              \\           ~          ,           .           _
                           SE_PIPE,    SE_CIRC,  SE_ASTR,    SE_SECT,   SE_GRV,         SE_BSLS,    SE_TILD,   KC_TRNS,    KC_TRNS,    KC_UNDS,
                                                               FLASH,   KC_NO,          MO(WNAV),   KC_NO
                           ),

    // Numbers and function keys
    [NUM] = LAYOUT_split_3x5_2(
                           KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
                           KC_1,  KC_2,  KC_3,  KC_4,  KC_5,               KC_6,  KC_7,  KC_8,  KC_9,  KC_0,
                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                KC_NO, KC_NO,              KC_NO, KC_NO
                           ),

    // Swedish letters
    [SWE] = LAYOUT_split_3x5_2(
                           KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,
                           KC_NO, TD(TD_OE), TD(TD_AE), TD(TD_AA), KC_NO,        KC_NO, TD(TD_AA), TD(TD_AE), TD(TD_OE), KC_NO,
                           KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,
                                                        KC_NO,     KC_NO,        KC_NO, KC_NO
                           )

    // Window and workspace navigation
    [WNAV] = LAYOUT_split_3x5_2(
                           LSA(1), LSA(2), LSA(3), LSA(4), LSA(5),         LSA(6), LSA(7), LSA(8), LSA(9), LSA(0),
                           A(1),   A(2),   A(3),   A(4),   A(5),           A(6),   A(7),   A(8),   A(9),   A(0),
                           KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                                   KC_NO,  KC_NO,          KC_NO,  KC_NO
                           ),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
