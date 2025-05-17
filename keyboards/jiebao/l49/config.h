// Copyright 2024 SDK (@sdk66)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #define CONSOLE_ENABLE

#define USB_POWER_EN_PIN                    B1 // USB ENABLE pin
#define LED_POWER_EN_PIN                    A5 // LED ENABLE pin
#define HS_BAT_CABLE_PIN                    A7 // USB insertion detection pin
#define HS_LED_BOOSTING_PIN                 B0 // LED BOOSTING,Power boost pin

#define BAT_FULL_PIN                        A15
#define BAT_FULL_STATE                      1

#define HS_RGB_INDICATOR_COUNT              50
#define HS_RGB_BAT_COUNT                    1

/* Device Name Definition */
#define MD_BT1_NAME "EPOMAKER TIDE 75"
#define MD_BT2_NAME "EPOMAKER TIDE 75"
#define MD_BT3_NAME "EPOMAKER TIDE 75"
#define MD_DONGLE_MANUFACTURER "EPOMAKER TIDE 75"

/* Device Connection RGB Indicator Light Index And Color */
#define HS_RGB_BLINK_INDEX_BT1 24
#define HS_RGB_BLINK_INDEX_BT2 25
#define HS_RGB_BLINK_INDEX_BT3 26
#define HS_RGB_BLINK_INDEX_2G4 27
#define HS_RGB_BLINK_INDEX_USB 23

#define RGBLIGHT_LAYERS

#define HS_LBACK_COLOR_BT1 RGB_BLUE
#define HS_LBACK_COLOR_BT2 RGB_BLUE
#define HS_LBACK_COLOR_BT3 RGB_BLUE
#define HS_LBACK_COLOR_2G4 RGB_GREEN
#define HS_LBACK_COLOR_USB RGB_WHITE

#define HS_PAIR_COLOR_BT1 RGB_BLUE
#define HS_PAIR_COLOR_BT2 RGB_BLUE
#define HS_PAIR_COLOR_BT3 RGB_BLUE
#define HS_PAIR_COLOR_2G4 RGB_GREEN

#define WIITE_B 0X6e

/* Battery */
#define BATTERY_CAPACITY_LOW 15
#define BATTERY_CAPACITY_STOP 0
#define RGB_MATRIX_BAT_INDEX_MAP {48, 47, 46, 45, 44, 43, 42, 41, 40, 39}

/* Status Indicator Lamp */
#define HS_MATRIX_BLINK_INDEX_BAT           10
#define HS_RGB_INDEX_CAPS                   19
#define HS_RGB_INDEX_WIN_LOCK               1
#define HS_RGB_BLINK_INDEX_VAI              12
#define HS_RGB_BLINK_INDEX_VAD              8
#define HS_RGB_BLINK_INDEX_SPI              9
#define HS_RGB_BLINK_INDEX_SPD              7

#define HS_RGB_BLINK_INDEX_WIN              16
#define HS_RGB_BLINK_INDEX_MAC              15

/* UART */
#define SERIAL_DRIVER SD3
#define SD1_TX_PIN C10
#define SD1_RX_PIN C11

/* Encoder */
#define ENCODER_MAP_KEY_DELAY               1
#define ENCODER_RESOLUTION                  2

/* SPI */
#define SPI_DRIVER                          SPIDQ
#define SPI_SCK_PIN                         B3
#define SPI_MOSI_PIN                        B5
#define SPI_MISO_PIN                        B4

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12
#define WEAR_LEVELING_LOGICAL_SIZE          (WEAR_LEVELING_BACKING_SIZE / 2)

/* RGB Matrix */
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* RGB Light */
#define RGBLED_NUM 50
// #define RGBLIGHT_CUSTOM_DRIVER
#define RGBLIGHT_DISABLE_KEYCODES
#define BREATHING_VAL           40
#define RAINBOW_MOOD            40
#define LED_TYPE                RGB

#define RGBLIGHT_LED_MAP {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49}

#define RGBLIGHT_DEFAULT_ON     false

/* WS2812 */
#define WS2812_SPI_DRIVER       SPIDM2
#define WS2812_SPI_DIVISOR      32

/* rgb_record */
#define ENABLE_RGB_MATRIX_RGBR_PLAY
#define RGBREC_CHANNEL_NUM         4
#define EECONFIG_CONFINFO_USE_SIZE (4 + 16)
#define EECONFIG_RGBREC_USE_SIZE   (RGBREC_CHANNEL_NUM * MATRIX_ROWS * MATRIX_COLS * 2)
#define EECONFIG_USER_DATA_SIZE    (EECONFIG_RGBREC_USE_SIZE + EECONFIG_CONFINFO_USE_SIZE)
#define RGBREC_EECONFIG_ADDR       (uint8_t *)(EECONFIG_USER_DATABLOCK)
#define CONFINFO_EECONFIG_ADDR     (uint32_t *)((uint32_t)RGBREC_EECONFIG_ADDR + (uint32_t)EECONFIG_RGBREC_USE_SIZE)
