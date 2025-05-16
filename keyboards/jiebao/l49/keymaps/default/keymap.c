// Copyright 2024 SDK (@sdk66)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_record/rgb_record.h"

#define  win(kc) (QK_LGUI | (KC_##kc))

enum layers {
    _BL = 0,
    _FBL,
    _FL,
    _MBL,
    _FFL,
    _MFL,
    _DEFA
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT( 
        KC_ESC,   KC_Q,      KC_W,      KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_LBRC,  KC_RBRC, KC_BSPC,
        KC_TAB,   KC_A,      KC_S,      KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,           KC_ENT,
        KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,                     KC_RSFT,
        KC_LCTL,  MO(_MBL),  KC_LALT,   KC_SPC,   KC_SPC,   MO(_FL),            KC_SPC,   MO(_FBL), MO(_FBL),  KC_RCTL,                     KC_DEL
        ),  

    [_FBL] = LAYOUT( 
        KC_ESC ,  KC_1,      KC_2,      KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_UP,    _______, KC_BSPC,
        KC_TAB,   KC_A,      KC_S,      KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_LEFT,  KC_RIGHT,          KC_ENT,
        KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_DOWN,                     KC_RSFT,
        KC_LCTL,  MO(_MBL),  KC_LALT,  KC_SPC,   KC_SPC,    KC_SPC,             KC_SPC,   KC_RALT,  _______,   KC_RCTL,                     MO(_FL)
        ), 

    [_FL] = LAYOUT( 
        KC_GRV,   KC_1,      KC_2,      KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
        KC_USB,   KC_BT1,    KC_BT2,    KC_BT3,   KC_2G4,   KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_BSLS,           RGB_TOG,
        _______,  LED_TOG,   HS_BATQ,   KC_CAPS,  KC_V,     KC_B,     KC_N,     KC_M,     RGB_HUI,  RGB_MOD,   RGB_VAI,                     MO(_DEFA),
        KC_FTOG,  GU_TOGG,   _______,   _______,  _______,  _______,            _______,  RGB_SPD,  RGB_VAD,   RGB_SPI,                     KC_DEL
        ),

    [_MBL] = LAYOUT( 
        KC_GRV ,  KC_F1,     KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_PGUP,  _______, KC_BSPC,
        KC_TAB,   win(A),    win(S),    win(D),   win(F),   win(G),   win(H),   win(J),   win(K),   win(L),    KC_HOME,  KC_END,            KC_ENT,
        KC_LSFT,  win(Z),    win(X),    win(C),   win(V),   win(B),   win(N),   win(M),   KC_COMM,  KC_DOT,    KC_PGDN,                     KC_RSFT,
        KC_LCTL,  _______,   KC_LCMD,   win(SPC), win(SPC), win(SPC),           win(SPC), KC_RCMD,  KC_RALT,   KC_RCTL,                     KC_DEL
        ),  

    [_FFL] = LAYOUT(  
        KC_ESC ,  KC_F1,     KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,  KC_BSPC, 
        KC_TAB,   KC_A,      KC_S,      KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,           KC_ENT,                           
        KC_LSFT,  KC_Z,      KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,                     KC_RSFT,      
        KC_LCTL,  KC_LALT,   KC_LCMD,   KC_SPC,   KC_SPC,   KC_SPC,             KC_SPC,   KC_RCMD,  KC_RALT,   KC_RCTL,                     KC_DEL
        ),   

    [_MFL] = LAYOUT( 
        KC_GRV,   KC_1,      KC_2,      KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_MINS,  KC_EQL,  KC_DEL,
        KC_USB,   KC_BT1,    KC_BT2,    KC_BT3,   KC_2G4,   KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_BSLS,           EE_CLR,
        _______,  LED_TOG,   HS_BATQ,   KC_CAPS,  RP_P0,    RP_END,   TO(_BL),  KC_NO,    RGB_HUI,  RGB_MOD,   RGB_VAI,                     MO(_DEFA),
        KC_FTOG,  GU_TOGG,   _______,   _______,  _______,  _______,            _______,  RGB_SPD,  RGB_VAD,   RGB_SPI,                     _______
        ),

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
const key_override_t bspc_key_override      = ko_make_basic(MOD_MASK_CTRL, KC_ENT, KC_BSLS);

const key_override_t rctl_delete_key_override = ko_make_basic(MOD_BIT_LCTRL, KC_BSPC, KC_DEL);
const key_override_t rshit_mins_key_override  = ko_make_basic(MOD_BIT_RSHIFT, KC_BSPC, LSFT(KC_MINS));
const key_override_t rshit_bspc_key_override  = ko_make_basic(MOD_BIT_RSHIFT, KC_ENT, LSFT(KC_BSLS));
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
        &alt_slash_key_override
};

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
