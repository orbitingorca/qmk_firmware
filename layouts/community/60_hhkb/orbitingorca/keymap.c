#include QMK_KEYBOARD_H
#include "version.h"

enum layer_names {
  _BASE,
  _NUMBER,
  _MOVE ,
  _SPACE,
  _FUN,
  _ADJUST
};

// keys
#define SPACEFN LT(_SPACE, KC_SPACE)
#define GUI_DEL RGUI_T(KC_DEL)
#define ALT_MPLY RALT_T(KC_MPLY)
#define LOCK_NUM TG(_NUMBER)
#define LOCK_MOV TG(_MOVE)

enum custom_keycodes {
    FUN_SIN = SAFE_RANGE,
    QMK_VER,
    M_LOCAL,
    M_RANDOM
};

/*
 *                                   ******** BASE ********
 * .-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * +-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
 * +-----------------------------------------------------------------------------------------+
 * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * +-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RShift    |FN/SI|
 * +-----------------------------------------------------------------------------------------+
 *         |LGUI | LAlt  |                 SpaceFn                  | RAlt |GUI/DEL|
 *         `-----------------------------------------------------------------------'
 *
 *                                   ******** NUMBER PAD ********
 * .-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |  7  |  8  |  9  |  /  |     |     |     |     |
 * +-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |  4  |  5  |  6  |  *  |  (  |  )  |        |
 * +-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |  1  |  2  |  3  |  -  |     |   KP_Enter  |
 * +-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     | NLK |  0  |     |  .  |  +  |           |     |
 * +-----------------------------------------------------------------------------------------+
 *         |     |       |                                          |        |     |
 *         `-----------------------------------------------------------------------'
 *
 *                                   ******** MOVEMENT ********
 * .-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * +-----------------------------------------------------------------------------------------+
 * |        |     |BTN 1|MS UP|BTN 2|     | Home| PgDn| PgUp| End |     |     |     |        |
 * +-----------------------------------------------------------------------------------------+
 * |         |     |MS LE|MS DN|MS RI|     |Right| Down| Up  | Left|     |     |             |
 * +-----------------------------------------------------------------------------------------+
 * |           |     |BTN 4|BTN 3|BTN 5|     |MW LE|MW DN|MW UP|MW RI|     |           |     |
 * +-----------------------------------------------------------------------------------------+
 *         |     |       |                                          |        |     |
 *         `-----------------------------------------------------------------------'
 *
 *                                   ******** SPACEFN ********
 * .-----------------------------------------------------------------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | INS | DEL |
 * +-----------------------------------------------------------------------------------------+
 * |        |     |BTN 1|MS UP|BTN 2|     | Home| PgDn| PgUp| End |     |     |     |        |
 * +-----------------------------------------------------------------------------------------+
 * |         |     |MS LE|MS DN|MS RI|     |Right| Down| Up  | Left|     |     |             |
 * +-----------------------------------------------------------------------------------------+
 * |           |     |BTN 4|BTN 3|BTN 5|     |MW LE|MW DN|MW UP|MW RI|     |           |     |
 * +-----------------------------------------------------------------------------------------+
 *         |     |       |                                          |        |     |
 *         `-----------------------------------------------------------------------'
 *
 *                                   ******** FUN ********
 * .-----------------------------------------------------------------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | INS | DEL |
 * +-----------------------------------------------------------------------------------------+
 * | CAPS   |     |MACL0|MACL1|MACL2|     |CALC |     |PRTSC│SCLCK│PAUSE|     |     |        |
 * +-----------------------------------------------------------------------------------------+
 * |         |APP  |     |     |     |     |WHOM |     |MPRV |MPLAY|MNXT |     |             |
 * +-----------------------------------------------------------------------------------------+
 * |           |NUBS |     |     |     |     | NUM | MOV |VOLUP|VOLDN|MUTE |           |     |
 * +-----------------------------------------------------------------------------------------+
 *         |     |       |                                          |        |     |
 *         `-----------------------------------------------------------------------'
 *
 *                                   ******** ADJUST ********
 * .-----------------------------------------------------------------------------------------.
 * |PWR  |     |     |     |     |     |6/NRO|     |     |     |BG_TG|BG_DN|BG_UP|Q_VER|RESET|
 * +-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * +-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * +-----------------------------------------------------------------------------------------+
 * |           |     |RGBTG|     |     |     |     |     |     |     |     |           |     |
 * +-----------------------------------------------------------------------------------------+
 *         |     |       |                                          |        |     |
 *         `-----------------------------------------------------------------------'
 */
// 6kro/nkro
#define TG_NKRO MAGIC_TOGGLE_NKRO

// macro wrapper
#define LAYOUT_60_hhkb_wrapper(...) LAYOUT_60_hhkb (__VA_ARGS__)

/* Base Layer */
#define G_BASE_R1     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV
#define G_BASE_R2     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC
#define G_BASE_R3     KC_LCTRL,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT
#define G_BASE_R4     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, FUN_SIN
#define G_BASE_R5              KC_LGUI, KC_LALT,                     SPACEFN,                         ALT_MPLY, GUI_DEL

/* Used on multiple layers */
#define G_FUNKEY_R1    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL
#define G_HHKB_TRANS_R5        _______, _______,                     _______,                         _______,  _______

/* Number pad Layer */
#define G_NUMBER_R1   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define G_NUMBER_R2   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_LPRN, KC_RPRN, _______
#define G_NUMBER_R3   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, KC_PENT
#define G_NUMBER_R4   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_P0,   XXXXXXX, KC_PDOT, KC_PPLS, _______, _______

/* move and spacefn layers */
#define G_MOVE_R1     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define G_MOV_SPAC_R2 _______, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, KC_HOME, KC_PGDN ,KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, _______
#define G_MOV_SPAC_R3 _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX, XXXXXXX, _______
#define G_MOV_SPAC_R4 _______, XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, KC_SPC,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______, _______

/* function Layer */
#define G_FUN_R2      KC_CAPS, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_CALC, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______
#define G_FUN_R3      _______, KC_APP,  _______, _______, _______, _______, KC_WHOM, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______
#define G_FUN_R4      _______, KC_NUBS, _______, _______, _______, _______, LOCK_NUM,LOCK_MOV,KC_VOLD, KC_VOLU, KC_MUTE, _______, _______

/* space + function (adjust) layer */
#define G_ADJUST_R1   KC_PWR,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  XXXXXXX, TG_NKRO, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  QMK_VER, RESET
#define G_ADJUST_R2   _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
#define G_ADJUST_R3   _______, M_RANDOM,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_LOCAL, XXXXXXX, XXXXXXX, _______
#define G_ADJUST_R4   _______, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, _______, _______


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_hhkb_wrapper( \
    G_BASE_R1, \
    G_BASE_R2, \
    G_BASE_R3, \
    G_BASE_R4, \
    G_BASE_R5 \
  ),

  [_NUMBER] = LAYOUT_60_hhkb_wrapper( \
    G_NUMBER_R1, \
    G_NUMBER_R2, \
    G_NUMBER_R3, \
    G_NUMBER_R4, \
    G_HHKB_TRANS_R5 \
  ),

  [_MOVE] = LAYOUT_60_hhkb_wrapper( \
    G_MOVE_R1,
    G_MOV_SPAC_R2, \
    G_MOV_SPAC_R3, \
    G_MOV_SPAC_R4, \
    G_HHKB_TRANS_R5 \
  ),

  [_SPACE] = LAYOUT_60_hhkb_wrapper( \
    G_FUNKEY_R1, \
    G_MOV_SPAC_R2, \
    G_MOV_SPAC_R3, \
    G_MOV_SPAC_R4, \
    G_HHKB_TRANS_R5 \
  ),

  [_FUN] = LAYOUT_60_hhkb_wrapper( \
    G_FUNKEY_R1, \
    G_FUN_R2, \
    G_FUN_R3, \
    G_FUN_R4, \
    G_HHKB_TRANS_R5 \
  ),

  [_ADJUST] = LAYOUT_60_hhkb_wrapper( \
    G_ADJUST_R1, \
    G_ADJUST_R2, \
    G_ADJUST_R3, \
    G_ADJUST_R4, \
    G_HHKB_TRANS_R5 \
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t key_timer;
  switch (keycode) {
    case FUN_SIN:
      if (record->event.pressed) {
        layer_on(_FUN);
        key_timer = timer_read();
      } else {
        layer_off(_FUN);
        if (timer_elapsed(key_timer) < 200) {
          if (get_mods()) {
            tap_code16(KC_INS);
          } else {
            tap_code16(LSFT(KC_INS));
          }
        }
        return false;
      }
      break;
    case M_LOCAL:
      if (record->event.pressed) {
        send_string("http://localhost");
      }
      return false;
      break;
    case M_RANDOM:
      if (record->event.pressed) {
        tap_random_base64();
      }
      return false;
      break;
    case QMK_VER:
      if (record->event.pressed) {
        send_string(QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _FUN, _SPACE, _ADJUST);
}

