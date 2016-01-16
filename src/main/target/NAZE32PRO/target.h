/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "AFF3" // AFro F3

/* LED defines */
#define LED0
#define LED0_GPIO   GPIOB
#define LED0_PIN    Pin_12
#define LED0_PERIPHERAL RCC_AHBPeriph_GPIOB

/* Buzzer defines */
#define BEEPER
#define BEEP_GPIO   GPIOB
#define BEEP_PIN    Pin_10
#define BEEP_PERIPHERAL RCC_AHBPeriph_GPIOB

/* Hardware inverter defines */

/* Serial port defines */
#define USE_VCP
#define USE_USART1
#define USE_USART2
#define SERIAL_PORT_COUNT 3

#define UART1_TX_PIN        GPIO_Pin_9  // PA9
#define UART1_RX_PIN        GPIO_Pin_10 // PA10
#define UART1_GPIO          GPIOA
#define UART1_GPIO_AF       GPIO_AF_7
#define UART1_TX_PINSOURCE  GPIO_PinSource9
#define UART1_RX_PINSOURCE  GPIO_PinSource10

#define UART2_TX_PIN        GPIO_Pin_5 // PD5
#define UART2_RX_PIN        GPIO_Pin_6 // PD6
#define UART2_GPIO          GPIOD
#define UART2_GPIO_AF       GPIO_AF_7
#define UART2_TX_PINSOURCE  GPIO_PinSource5
#define UART2_RX_PINSOURCE  GPIO_PinSource6

/* I2C port defines */
#define USE_I2C
#define I2C_DEVICE (I2CDEV_1)

/* SPI port defines */

/* ADC port defines */

/* Peripheral defines */
#define GYRO

#define ACC

/* Feature defines */
//#define SONAR
#define BLACKBOX
//#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
//#define DISPLAY
#define GPS
#define GTUNE
#define SERIAL_RX
#define TELEMETRY
#define USE_SERVOS
#define USE_CLI
//#define BRUSHED_MOTORS

/* Blheli Serial1Wire defines */

/* LED Strip defines */

/* Spektrum defines */
#define SPEKTRUM_BIND
// USART2, PA3
#define BIND_PORT  GPIOA
#define BIND_PIN   Pin_3
