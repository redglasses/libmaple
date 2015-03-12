/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   wirish/boards/maple_mini/board.cpp
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Maple Mini board file.
 */

#include <board/board.h>

#include <libmaple/gpio.h>
#include <libmaple/timer.h>

#include <wirish/wirish_debug.h>
#include <wirish/wirish_types.h>

/* Since we want the Serial Wire/JTAG pins as GPIOs, disable both SW
 * and JTAG debug support, unless configured otherwise. */
void boardInit(void) {
#ifndef CONFIG_MAPLE_MINI_NO_DISABLE_DEBUG
    disableDebugPorts();
#endif
}

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {
    /* Top header */
    {GPIOC,   NULL, NULL, 13, 0, ADCx}, /* D0/PC13 */
    {GPIOC,   NULL, NULL, 14, 0, ADCx}, /* D1/PC14 */
    {GPIOC,   NULL, NULL, 15, 0, ADCx}, /* D2/PC15 */
    {GPIOA, TIMER2, ADC1,  0, 1,    0}, /* D3/PA0 */
    {GPIOA, TIMER2, ADC1,  1, 2,    1}, /* D4/PA1 */
    {GPIOA, TIMER2, ADC1,  2, 3,    2}, /* D5/PA2 */
    {GPIOA, TIMER2, ADC1,  3, 4,    3}, /* D6/PA3 */
    {GPIOA,   NULL, ADC1,  4, 0,    4}, /* D7/PA4 */
    {GPIOA,   NULL, ADC1,  5, 0,    5}, /* D8/PA5 */
    {GPIOA, TIMER3, ADC1,  6, 1,    6}, /* D9/PA6 */
    {GPIOA, TIMER3, ADC1,  7, 2,    7}, /* D10/PA7 */
    {GPIOB, TIMER3, ADC1,  0, 3,    8}, /* D11/PB0 */
    {GPIOB, TIMER3, ADC1,  1, 4,    9}, /* D12/PB1 */
    {GPIOB,   NULL, NULL, 10, 0, ADCx}, /* D13/PB10 */
    {GPIOB,   NULL, NULL, 11, 0, ADCx}, /* D14/PB11 */
    /* Bottom header */
    {GPIOB,   NULL, NULL, 12, 0, ADCx}, /* D15/PB12 */
    {GPIOB,   NULL, NULL, 13, 0, ADCx}, /* D16/PB13 */
    {GPIOB,   NULL, NULL, 14, 0, ADCx}, /* D17/PB14 */
    {GPIOB,   NULL, NULL, 15, 0, ADCx}, /* D18/PB15 */
    {GPIOA, TIMER1, NULL,  8, 1, ADCx}, /* D19/PA8 */
    {GPIOA, TIMER1, NULL,  9, 2, ADCx}, /* D20/PA9 */
    {GPIOA, TIMER1, NULL, 10, 3, ADCx}, /* D21/PA10 */
    {GPIOA, TIMER1, NULL, 11, 4, ADCx}, /* D22/PA11 */
    {GPIOA,   NULL, NULL, 12, 0, ADCx}, /* D23/PA12 */
    {GPIOA,   NULL, NULL, 15, 0, ADCx}, /* D24/PA15 */
    {GPIOB,   NULL, NULL,  3, 0, ADCx}, /* D25/PB3 */
    {GPIOB,   NULL, NULL,  4, 0, ADCx}, /* D26/PB4 */
    {GPIOB,   NULL, NULL,  5, 0, ADCx}, /* D27/PB5 */
    {GPIOB, TIMER4, NULL,  6, 1, ADCx}, /* D28/PB6 */
    {GPIOB, TIMER4, NULL,  7, 2, ADCx}, /* D29/PB7 */
    {GPIOB, TIMER4, NULL,  8, 3, ADCx}, /* D30/PB8 */
    {GPIOB, TIMER4, NULL,  9, 4, ADCx}, /* D31/PB9 */
    {GPIOA,   NULL, NULL, 13, 0, ADCx}, /* D32/PA13 */
    {GPIOA,   NULL, NULL, 14, 0, ADCx}, /* D33/PA14 */
};

extern const uint8 boardPWMPins[BOARD_NR_PWM_PINS] __FLASH__ = {
    3, 4, 5, 6, 9, 10, 11, 12, 19, 20, 21, 22, 28, 29, 30, 31
};

extern const uint8 boardADCPins[BOARD_NR_ADC_PINS] __FLASH__ = {
    3, 4, 5, 6, 7, 8, 9, 10, 11, 12
};

#define USB_DP 23
#define USB_DM 22

extern const uint8 boardUsedPins[BOARD_NR_USED_PINS] __FLASH__ = {
    USB_DP, USB_DM
};
