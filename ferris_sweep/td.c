// ö
#define SE_OE KC_SCLN
// ä
#define SE_AE KC_QUOT
// å
#define SE_AA KC_LBRC

// https://docs.qmk.fm/features/tap_dance#example-3
enum {
  // å/Å
  TD_AA = 0,
  // ä/Ä
  TD_AE,
  // ö/Ö
  TD_OE,
  // q/tab
  TD_Q_TAB
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
  [TD_AA] = ACTION_TAP_DANCE_TAP_HOLD(SE_AA, S(SE_AA)),
  [TD_AE] = ACTION_TAP_DANCE_TAP_HOLD(SE_AE, S(SE_AE)),
  [TD_OE] = ACTION_TAP_DANCE_TAP_HOLD(SE_OE, S(SE_OE)),
  [TD_Q_TAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, KC_TAB);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_AA):
        case TD(TD_AE):
        case TD(TD_OE):
        case TD(TD_Q_TAB):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}
