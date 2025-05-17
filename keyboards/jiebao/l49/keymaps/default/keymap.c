// Copyright 2024 SDK (@sdk66)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_record/rgb_record.h"
#include "control/control.h"
#include "rgb_record/rgb_rgblight.h"

#define  win(kc) (QK_LGUI | (KC_##kc))
#define  my_win MY_LAY1
#define  my_fn  MY_LAY2
#define  my_space TD(TD_SPACE_LAYER)
#define  my_num   TD(TD_NUM_LAYER)



enum layers {
    _BL = 0,
    _FBL,
    _FL,
    // _FFL,
    _MBL,
    // _MFL,
    _DEFA
};

enum {
    TD_SPACE_LAYER,
    TD_NUM_LAYER,
};

void td_space_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_SPACE);
    } else if (state->count == 2) {
        layer_invert(_FBL);
    }
}

bool td_layer_fn_is_hold = false;
void td_num_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        td_layer_fn_is_hold = true;
        layer_on(1);
    } else {
        if (state->count == 2) {
            layer_invert(_FBL);
        }
    }
}


void td_space_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_SPACE);  // Release space after single tap
    }
}

void td_num_reset(tap_dance_state_t *state, void *user_data) {
    if (td_layer_fn_is_hold) {
        layer_off(_FBL);  // 放開 → 關閉 momentary Layer 1
        td_layer_fn_is_hold = false;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPACE_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_space_finished, td_space_reset),
    [TD_NUM_LAYER]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_finished, td_num_reset),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
        KC_ESC,   KC_Q,      KC_W,      KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_LBRC,  KC_RBRC, KC_BSPC,
        KC_TAB,   KC_A,      KC_S,      KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,           KC_ENT,
        KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,                     KC_RSFT,
        KC_LCTL,  my_win,    KC_LALT,   KC_SPC,   KC_SPC,   my_fn,              KC_SPC,   my_num,   MO(_FBL),  KC_RCTL,                     KC_DEL
        ),

    [_FBL] = LAYOUT(
        KC_ESC ,  KC_1,      KC_2,      KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_UP,    _______, KC_BSPC,
        KC_TAB,   KC_A,      KC_S,      KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_HOME,  KC_PGUP,   KC_LEFT,  KC_RIGHT,          KC_ENT,
        KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_END,   KC_PGDN,   KC_DOWN,                     KC_RSFT,
        KC_LCTL,  MO(_MBL),  KC_LALT,   KC_SPC,   KC_SPC,   KC_SPC,             KC_SPC,   my_num,   _______,   KC_RCTL,                     KC_DEL
        ),

    [_FL] = LAYOUT(
        KC_GRV,   KC_1,      KC_2,      KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
        KC_USB,   KC_BT1,    KC_BT2,    KC_BT3,   KC_2G4,   KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_BSLS,           RGB_TOG,
        _______,  LED_TOG,   HS_BATQ,   KC_CAPS,  KC_V,     KC_B,     KC_N,     KC_M,     RGB_HUI,  RGB_MOD,   RGB_VAI,                     MO(_DEFA),
        KC_FTOG,  GU_TOGG,   _______,   _______,  _______,  _______,            _______,  RGB_SPD,  RGB_VAD,   RGB_SPI,                     KC_DEL
        ),

    // [_FFL] = LAYOUT(
    //     KC_ESC,   KC_Q,      KC_W,      KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_LBRC,  KC_RBRC, KC_BSPC,
    //     KC_TAB,   KC_A,      KC_S,      KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,           KC_ENT,
    //     KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_UP,                       KC_RSFT,
    //     KC_LCTL,  MO(_MFL),  KC_LALT,   KC_SPC,   KC_SPC,   KC_SPC,             KC_SPACE , KC_LEFT,  KC_DOWN,   KC_RIGHT,                    KC_DEL
    //     ),

    [_MBL] = LAYOUT(
        KC_GRV ,  KC_F1,     KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_PGUP,  _______, KC_BSPC,
        KC_TAB,   win(A),    win(S),    win(D),   win(F),   win(G),   win(H),   win(J),   win(K),   win(L),    KC_HOME,  KC_END,            KC_ENT,
        KC_LSFT,  win(Z),    win(X),    win(C),   win(V),   win(B),   win(N),   win(M),   KC_COMM,  KC_DOT,    KC_PGDN,                     KC_RSFT,
        KC_LCTL,  _______,   KC_LALT,   win(SPC), win(SPC), win(SPC),           win(SPC), MO(_FBL), MO(_FBL),  KC_RCTL,                     KC_DEL
        ),

    // [_MFL] = LAYOUT(
    //     KC_ESC,   KC_Q,      KC_W,      KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_LBRC,  KC_RBRC, KC_BSPC,
    //     KC_TAB,   KC_A,      KC_S,      KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,           KC_ENT,
    //     KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_PGUP,                     KC_RSFT,
    //     KC_LCTL,  _______,   KC_LALT,   KC_SPC,   KC_SPC,   KC_SPC,             my_space, KC_HOME,  KC_PGDN,   KC_END,                      KC_DEL
    //     ),

    [_DEFA] = LAYOUT(
        KC_TILD,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  KC_TEST,   _______,   _______,  _______, QK_BOOT,
        _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  KC_TEST,   _______,   _______,           EE_CLR,
        _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,                      _______,
        _______,  _______,   _______,   _______,  _______,  KC_PGUP,            _______,  _______,  _______,   _______,                      _______
        ),
};

const uint16_t PROGMEM rgbrec_default_effects[RGBREC_CHANNEL_NUM][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        ________, ________,  HS_GREEN,  ________, ________, ________, ________, ________, ________, ________,  ________,  ________, ________,________,
        ________, HS_GREEN,  HS_GREEN,  HS_GREEN, ________, ________, ________, ________, ________, ________,  ________,  ________,          ________,
        ________, ________,  ________,  ________, ________, ________, ________, ________, ________, ________,  HS_GREEN,                     ________,
        ________, ________,  ________,  ________, ________, ________,           ________, HS_GREEN, HS_GREEN,  HS_GREEN,                     ________
        ),

    [1] = LAYOUT(
        ________, ________,  HS_RED,    ________, ________, ________, ________, ________, ________, ________,  ________,  ________, ________,________,
        ________, HS_RED,    HS_RED,    HS_RED,   ________, ________, ________, ________, ________, ________,  ________,  ________,          ________,
        ________, ________,  ________,  ________, ________, ________, ________, ________, ________, ________,  HS_RED,                       ________,
        ________, ________,  ________,  ________, ________, ________,           ________, HS_RED,   HS_RED,    HS_RED,                       ________
        ),

    [2] = LAYOUT(
        ________, ________,  HS_BLUE,   ________, ________, ________, ________, ________, ________, ________,  ________,  ________, ________,________,
        ________, HS_BLUE,   HS_BLUE,   HS_BLUE,  ________, ________, ________, ________, ________, ________,  ________,  ________,          ________,
        ________, ________,  ________,  ________, ________, ________, ________, ________, ________, ________,  HS_BLUE,                      ________,
        ________, ________,  ________,  ________, ________, ________,           ________, HS_BLUE,  HS_BLUE,   HS_BLUE,                      ________
        ),
};

#include QMK_KEYBOARD_H

const key_override_t esc_key_override       = ko_make_basic(MOD_MASK_CTRL, KC_ESC, LCTL(KC_GRV));
const key_override_t gesc_key_override      = ko_make_basic(MOD_MASK_SHIFT,KC_ESC, KC_TILD);
const key_override_t rctl_lbrc_key_override = ko_make_basic(MOD_BIT_RCTRL, KC_LBRC, KC_MINS);
const key_override_t rctl_rbrc_key_override = ko_make_basic(MOD_BIT_RCTRL, KC_RBRC, KC_EQL);
const key_override_t lctl_lbrc_key_override = ko_make_basic(MOD_BIT_LCTRL, KC_LBRC, LCTL(KC_MINS));
const key_override_t lctl_rbrc_key_override = ko_make_basic(MOD_BIT_LCTRL, KC_RBRC, LCTL(KC_EQL));

const key_override_t rctl_delete_key_override = ko_make_basic(MOD_BIT_LCTRL, KC_BSPC, KC_DEL);
const key_override_t rshit_mins_key_override  = ko_make_basic(MOD_BIT_RSHIFT, KC_BSPC, LSFT(KC_MINS));
const key_override_t rshit_bspc_key_override  = ko_make_basic(MOD_BIT_RSHIFT, KC_ENT, LSFT(KC_BSLS));
const key_override_t bspc_key_override        = ko_make_basic(MOD_BIT_RCTRL, KC_ENT, KC_BSLS);
const key_override_t rctl_bspc_key_override   = ko_make_basic(MOD_BIT_RCTRL, KC_BSPC, KC_MINS);

const key_override_t alt_c_key_override = ko_make_basic(MOD_BIT_LALT, KC_C, LCTL(KC_C));
const key_override_t alt_v_key_override = ko_make_basic(MOD_BIT_LALT, KC_V, LCTL(KC_V));
const key_override_t alt_x_key_override = ko_make_basic(MOD_BIT_LALT, KC_X, LCTL(KC_X));
const key_override_t alt_z_key_override = ko_make_basic(MOD_BIT_LALT, KC_Z, LCTL(KC_Z));
const key_override_t alt_s_key_override = ko_make_basic(MOD_BIT_LALT, KC_S, LCTL(KC_S));
const key_override_t alt_o_key_override = ko_make_basic(MOD_BIT_LALT, KC_O, LCTL(KC_O));
const key_override_t alt_k_key_override = ko_make_basic(MOD_BIT_LALT, KC_K, LCTL(KC_K));
const key_override_t alt_f_key_override = ko_make_basic(MOD_BIT_LALT, KC_F, LCTL(KC_F));
const key_override_t alt_g_key_override = ko_make_basic(MOD_BIT_LALT, KC_G, LCTL(KC_G));
const key_override_t alt_p_key_override = ko_make_basic(MOD_BIT_LALT, KC_P, LCTL(KC_P));
const key_override_t alt_t_key_override = ko_make_basic(MOD_BIT_LALT, KC_T, LCTL(KC_T));
const key_override_t alt_slash_key_override = ko_make_basic(MOD_BIT_LALT, KC_SLSH, LCTL(KC_SLSH));
const key_override_t alt_lbrc_key_override = ko_make_basic(MOD_BIT_LALT, KC_LBRC, KC_MINS);
const key_override_t alt_rbrc_key_override = ko_make_basic(MOD_BIT_LALT, KC_RBRC, KC_EQL);
const key_override_t alt_bspc_key_override  = ko_make_basic(MOD_BIT_LALT, KC_ENT, KC_BSLS);
const key_override_t alt_rctl_bspc_key_override = ko_make_basic(MOD_BIT_LALT, KC_BSPC, KC_MINS);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
        &esc_key_override,
        &gesc_key_override,
        &rctl_lbrc_key_override,
        &rctl_rbrc_key_override,
        &lctl_lbrc_key_override,
        &lctl_rbrc_key_override,
        &bspc_key_override,
        &rctl_delete_key_override,
        &rshit_mins_key_override,
        &rshit_bspc_key_override,
        &rctl_bspc_key_override,

        &alt_c_key_override,
        &alt_v_key_override,
        &alt_x_key_override,
        &alt_z_key_override,
        &alt_s_key_override,
        &alt_o_key_override,
        &alt_k_key_override,
        &alt_f_key_override,
        &alt_g_key_override,
        &alt_p_key_override,
        &alt_t_key_override,
        &alt_slash_key_override,
        &alt_lbrc_key_override,
        &alt_rbrc_key_override,
        &alt_bspc_key_override,
        &alt_rctl_bspc_key_override
};

#define HSV_V 20
/*Default layer is white.*/
/*Remember to also change the color in keyboard_post_init_kb in boston.c to make the startup color match the layer 0 color */
const rgblight_segment_t PROGMEM layer_0[] = RGBLIGHT_LAYER_SEGMENTS(
    {49, 1, 190, 255, 10*HSV_V} /*Magenta*/
);

const rgblight_segment_t PROGMEM layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, 0,   255,   HSV_V},  /*Red*/
    {7, 1, 0,   255,   HSV_V},  /*Red*/
    {8, 1, 0,   255,   HSV_V},  /*Red*/
    {9, 1, 0,   255,   HSV_V},  /*Red*/
    {40,1, 160, 255, 2*HSV_V},  /*Blue*/
    {42,1, 160, 255, 2*HSV_V},  /*Blue*/
    {44,1, 160, 255, 2*HSV_V},  /*Blue*/
    {46,1, 160, 255, 2*HSV_V},  /*Blue*/
    {48,1, 160, 255, 2*HSV_V},  /*Blue*/

    {38,1, 36, 255, 2*HSV_V},  /*Gold*/
    {12,1, 36, 255, 2*HSV_V},  /*Gold*/
    {33,1, 36, 255, 2*HSV_V},  /*Gold*/
    {34,1, 36, 255, 2*HSV_V},  /*Gold*/

    {31,1, 75, 255, 2*HSV_V},  /*Green*/
    {32,1, 75, 255, 2*HSV_V},  /*Green*/
    {13,1, 75, 255, 2*HSV_V},  /*Green*/
    {14,1, 75, 255, 2*HSV_V}   /*Green*/

);

const rgblight_segment_t PROGMEM layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 21, 255, HSV_V}, /*Orange*/
    {1, 1, 21, 255, HSV_V}, /*Orange*/
    {2, 1, 21, 255, HSV_V}, /*Orange*/
    {3, 1, 21, 255, HSV_V}, /*Orange*/
    {4, 1, 21, 255, HSV_V}, /*Orange*/
    {5, 1, 21, 255, HSV_V}, /*Orange*/
    {6, 1, 21, 255, HSV_V}, /*Orange*/
    {7, 1, 21, 255, HSV_V}, /*Orange*/
    {8, 1, 21, 255, HSV_V}, /*Orange*/
    {9, 1, 21, 255, HSV_V}, /*Orange*/
    {10,1, 21, 255, HSV_V}  /*Orange*/
);

const rgblight_segment_t PROGMEM layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 43,  255,   HSV_V}, /*Yellow*/
    {1, 1, 43,  255,   HSV_V}, /*Yellow*/
    {2, 1, 43,  255,   HSV_V}, /*Yellow*/
    {39,1, 190, 255, 2*HSV_V}, /*Magenta*/
    {41,1, 190, 255, 2*HSV_V}, /*Magenta*/
    {43,1, 190, 255, 2*HSV_V}, /*Magenta*/
    {45,1, 190, 255, 2*HSV_V}, /*Magenta*/
    {47,1, 190, 255, 2*HSV_V}, /*Magenta*/
    {38,1, 128, 255, 2*HSV_V},  /*CYAN*/
    {12,1, 128, 255, 2*HSV_V},  /*CYAN*/
    {33,1, 128, 255, 2*HSV_V},  /*CYAN*/
    {34,1, 128, 255, 2*HSV_V},  /*CYAN*/
    {49,1, 128, 255, 4*HSV_V}   /*CYAN*/
);

const rgblight_segment_t PROGMEM layer_4[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 1, 75, 255, HSV_V}, /*Green*/
    {12, 1, 75, 255, HSV_V}, /*Green*/
    {13, 1, 75, 255, HSV_V}  /*Green*/
);

const rgblight_segment_t PROGMEM layer_5[] = RGBLIGHT_LAYER_SEGMENTS(
    {35, 1, 234, 255, 4*HSV_V}, /*Pink*/
    {36, 1, 234, 255, 4*HSV_V}, /*Pink*/
    {37, 1, 234, 255, 2*HSV_V}, /*Pink*/
    {38, 1, 234, 255, 2*HSV_V}  /*Pink*/
);

const rgblight_segment_t PROGMEM layer_6[] = RGBLIGHT_LAYER_SEGMENTS(
    {35, 1, 234, 255, 4*HSV_V}, /*Pink*/
    {36, 1, 234, 255, 4*HSV_V}  /*Pink*/
);

const rgblight_segment_t PROGMEM layer_7[] = RGBLIGHT_LAYER_SEGMENTS(
    {37, 1, 106, 255, 2*HSV_V}, /*Spring Green*/
    {38, 1, 106, 255, 2*HSV_V}  /*Spring Green*/
);

const rgblight_segment_t PROGMEM layer_8[] = RGBLIGHT_LAYER_SEGMENTS(
    {25, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, S*/
    {27, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, F*/
    {28, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, G*/
    {30, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, J*/
    {31, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, K*/
    {39, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, P*/
    {40, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, O*/
    {44, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, T*/
    {21, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, Z*/
    {20, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, X*/
    {19, 1, 123, 255, 2*HSV_V}, /*TURQUOISE, C*/
    {18, 1, 123, 255, 2*HSV_V}  /*TURQUOISE, V*/
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_0,
    layer_1,
    layer_2,
    layer_3,
    layer_4,
    layer_5,
    layer_6,
    layer_7,
    layer_8
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(_______, _______)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
    [4] = {ENCODER_CCW_CW(_______, _______)},
    [5] = {ENCODER_CCW_CW(_______, _______)},
    [6] = {ENCODER_CCW_CW(_______, _______)}
};
#endif
// clang-format on
