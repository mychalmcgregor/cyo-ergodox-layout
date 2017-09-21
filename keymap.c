#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers
#define ARRO 3 // arrow keys/keyboard movement
#define MOUS 4 // mouse/scroll functions & media keys
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   c  |   y  |   o  |   .  |      |      |           |      |   j  |   b  |   f  |   w  |   q  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   d  |   i  |   e  |   a  |   u  |------|           |------|   g  |   t  |   n  |   s  |   r  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   z  |   '  |   "  |   ,  |      |      |           |      |   k  |   p  |   m  |   v  |   x  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Cmd  |L4/Bsp|                                       |L3/Del|Meh/F11|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |Cl/Esc|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Shift/| L5/  |      |       |      | L2/  |Shift/|
 *                                 | Spc  |   h  |------|       |------|   l  | Spc  |
 *                                 |      |      |Alt/F9|       |Hyper/F5|    |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : base
    // left hand
    KC_ESC, _______,_______,_______,_______,_______,_______,
    _______,KC_C,   KC_Y,   KC_O,   KC_DOT, _______,_______,
    KC_TAB, KC_D,   KC_I,   KC_E,   KC_A,   KC_U,
    CTL_T(KC_ESC),KC_Z,   KC_QUOT,KC_DQUO,KC_COMM,_______,_______,
    _______,_______,_______,KC_LGUI,LT(3,KC_BSPC),
                                            _______,_______,
                                                    _______,
                      SFT_T(KC_SPC),LT(4,KC_H),ALT_T(KC_F9),
    // right hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,KC_J,   KC_B,   KC_F,   KC_W,   KC_Q,   _______,
            KC_G,   KC_T,   KC_N,   KC_S,   KC_R,   KC_ENT,
    _______,KC_K,   KC_P,   KC_M,   KC_V,   KC_X,   CTL_T(KC_ESC),
                    LT(2,KC_DEL),MEH_T(KC_F11),_______,_______,_______,
    CTL_T(KC_ESC),_______,
    _______,
    ALL_T(KC_F5),LT(1,KC_L),SFT_T(KC_SPC)
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Version|   ~  |   +  |   -  |   *  |   \  |      |           |      |   /  |   &  |   |  |   !  |   :  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   #  |   [  |   {  |   (  |   <  |------|           |------|   >  |   )  |   }  |   ]  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   $  |   ^  |   %  |   =  |   ,  |      |           |      |   `  |   @  |   _  |   ?  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Cmd  |L4/Bsp|                                       |L3/Del|Meh/F11|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |Cl/Esc|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Shift/| L5/  |      |       |      | L2/  |Shift/|
 *                                 | Spc  |   h  |------|       |------|   l  | Spc  |
 *                                 |      |      |Alt/F9|       |Hyper/F5|    |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = KEYMAP( // layer 1 : symbol
    // left hand
    _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
    M(0),   KC_TILD,KC_PLUS,KC_MINS,KC_ASTR,KC_BSLS,_______,
    _______,KC_HASH,KC_LBRC,KC_LCBR,KC_LPRN,KC_LABK,
    _______,KC_DLR, KC_CIRC,KC_PERC,KC_EQL, _______,_______,
    _______,_______,_______,_______,_______,
                                            _______,_______,
                                                    _______,
                                    _______,_______,_______,
    // right hand
    _______,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
    _______,KC_SLSH,KC_AMPR,KC_PIPE,KC_EXLM,KC_COLN,KC_F12,
            KC_RABK,KC_RPRN,KC_RCBR,KC_RBRC,KC_SCLN,_______,
    _______,KC_GRV, KC_AT,  KC_UNDS,KC_QUES,_______,_______,
                    _______,_______,_______,_______,_______,
    _______,_______,
    _______,
    _______,_______,_______
),

/* Keymap 2: Number Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |   1  |   2  |   3  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Version|   ~  |   +  |   -  |   *  |   \  |      |           |      |   /  |   4  |   5  |   6  |   :  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   #  |   [  |   {  |   (  |   <  |------|           |------|   >  |   7  |   8  |   9  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   $  |   ^  |   %  |   =  |   `  |      |           |      |      |   .  |   0  |   ,  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Cmd  |L4/Bsp|                                       |L3/Del|Meh/F11|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |Cl/Esc|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Shift/| L5/  |      |       |      | L2/  |Shift/|
 *                                 | Spc  |   h  |------|       |------|   l  | Spc  |
 *                                 |      |      |Alt/F9|       |Hyper/F5|    |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMB] = KEYMAP( // layer 2 : number
    // left hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,
                                            _______,_______,
                                                    _______,
                                    _______,_______,_______,
    // right hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,KC_1,   KC_2,   KC_3,   KC_4,   _______,
            _______,KC_5,   KC_6,   KC_7,   KC_8,   _______,
    _______,_______,KC_9,   KC_0,   KC_DOT, KC_COMM,_______,
                    _______,_______,_______,_______,_______,
    _______,_______,
    _______,
    _______,_______,_______
),

/* Keymap 3: Arrow keys layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | PgUp |      |      |      |           |      |      |      | Up   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |      | Home |PgDown| End  |      |------|           |------|      | Left | Down | Right|      | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Cmd  |L4/Bsp|                                       |L3/Del|Meh/F11|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |Cl/Esc|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Shift/| L5/  |      |       |      | L2/  |Shift/|
 *                                 | Spc  |   h  |------|       |------|   l  | Spc  |
 *                                 |      |      |Alt/F9|       |Hyper/F5|    |      |
 *                                 `--------------------'       `--------------------'
 */
[ARRO] = KEYMAP( // layer 3 : arrow
    // left hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,KC_PGUP,_______,_______,_______,
    _______,_______,KC_HOME,KC_PGDN,KC_END, _______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,
                                            _______,_______,
				                                            _______,
                                    _______,_______,_______,
    // right hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,KC_UP,  _______,_______,_______,
            _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
                    _______,_______,_______,_______,_______,
    _______,_______,
    _______,
    _______,_______,_______
),

/* Keymap 4: Mouse/media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |WhLeft| WhUp |WhRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Lclk |WhDown| Rclk |      | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Cmd  |L4/Bsp|                                       |L3/Del|Meh/F11|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |Cl/Esc|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Shift/| L5/  |      |       |      | L2/  |Shift/|
 *                                 | Spc  |   h  |------|       |------|   l  | Spc  |
 *                                 |      |      |Alt/F9|       |Hyper/F5|    |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MOUS] = KEYMAP( // layer 4 : mouse
    // left hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,KC_MS_U,_______,_______,_______,
    _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,
                                            _______,_______,
				                                            _______,
                                    _______,_______,_______,
    // right hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,KC_WH_L,KC_WH_U,KC_WH_R,_______,_______,
            _______,KC_BTN1,KC_WH_D,KC_BTN2,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
                    _______,_______,_______,_______,_______,
    _______,_______,
    _______,
    _______,_______,_______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
