#pragma once

#include QMK_KEYBOARD_H

#include "keymap_swedish.h"
#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"
#include "oneshot.h"

enum layers {
    _BASE = 0,
    _NUM,
    _NAV,
    _WNAV,
    _WIN,
    _SYM,
    _MODS,
    _SHRT,
    _SPEC,
    _FUN,
};

enum custom_keycodes {
    // Direct dead keys ~`^
    TILD = QK_USER,
    GRV,
    CIRC,

    // Vim
    SAVE_VIM,
    VIM_VS,
    VIM_SP,
    CLOSE_WIN,

    // Multiple chars
    QU,
    SC,

    // É
    E_ACUT,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // Custom Win + Alt for window toggling on Windows
    WIN_ALT,

    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,

    // Layer management
    CANCEL, // Cancel SYMWORD and NUMWORD
    CLEAR,  // Clear all WORD, one-shots and reset to BASE

    // Instant leader key
    LEADER,

    // Repeat keys
    REPEAT,
    REV_REP,

    // Workspace layer keys
    NV_LBRC,
    NV_RBRC,
    NV_R,
    NV_LEFT,
    NV_DOWN,
    NV_UP,

    // Custom punctuation keys
    SKC_QUESTION_EXCLAMATION,
    SKC_DOT_COLON,
    SKC_COMMA_SEMICOLON,
};

#define xxxxxxx KC_NO

#define MT_SPC LT(_NAV, KC_SPC)
#define MY_RALT OSM(MOD_RALT)
#define DN_CTRL LCTL_T(KC_DOWN)

#define ESC_SYM LT(_SYM, KC_ESC)
#define TAB_MOD LT(_MODS, KC_TAB)

#define COLN_SYM LT(_SYM, SE_COLN)

#define C_TAB C(KC_TAB)
#define S_TAB S(KC_TAB)
#define SC_TAB S(C(KC_TAB))

#define MY_LALT OSM(MOD_LALT)

#define SHRT OSL(_SHRT)
#define WNAV MO(_WNAV)
#define TG_WNAV TG(_WNAV)
#define OPT OSL(_OPT)
#define SPEC OSL(_SPEC)
#define FUN OSL(_FUN)

#define GAME2 OSL(_GAME2)

#define SYM_LFT ALGR(KC_Y)    // ← y
#define SYM_DWN ALGR(KC_U)    // ↓ u
#define SYM_RHT ALGR(KC_I)    // → i
#define SYM_UP ALGR(S(KC_U))  // ↑ U
#define SYM_LDQ ALGR(KC_V)    // “ v
#define SYM_RDQ ALGR(KC_B)    // ” b
#define SYM_LQO ALGR(S(KC_V)) // ‘ V
#define SYM_RQO ALGR(S(KC_B)) // ’ B

#define NV_ESC G(KC_ESC)
#define NV_P G(KC_P)
#define NV_F G(KC_F)
#define NV_EQL G(KC_EQL)
#define NV_MINS G(KC_MINS)
#define NV_DOT G(KC_DOT)
#define NV_COMM G(KC_COMM)
#define NV_V G(KC_V)
#define NV_C G(KC_C)
#define NV_HOME G(KC_HOME)
#define NV_O G(KC_O)
#define NV_END G(KC_END)
#define NV_RGHT G(KC_RGHT)
#define NV_Q G(KC_Q)
#define NV_W G(KC_W)
#define NV_SPC G(KC_SPC)

#define DOT_CN SKC_DOT_COLON
#define COMM_SC SKC_COMMA_SEMICOLON
#define QN_EXCM SKC_QUESTION_EXCLAMATION
