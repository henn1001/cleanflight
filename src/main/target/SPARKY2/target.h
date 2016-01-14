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
#define TARGET_BOARD_IDENTIFIER "SPK2"

#define LED0_GPIO   GPIOB
#define LED0_PIN    Pin_5 // Blue LED
#define LED0_PERIPHERAL RCC_AHB1Periph_GPIOB
#define LED1_GPIO   GPIOB
#define LED1_PIN    Pin_4  // Red LED
#define LED1_PERIPHERAL RCC_AHB1Periph_GPIOB
#define LED2_GPIO   GPIOB
#define LED2_PIN    Pin_6 // Blue LED
#define LED2_PERIPHERAL RCC_AHB1Periph_GPIOB

#define BEEP_GPIO   GPIOC
#define BEEP_PIN    Pin_9 // JST-SH Pin 3
#define BEEP_PERIPHERAL RCC_AHB1Periph_GPIOC
#define BEEPER_INVERTED

#define INVERTER_PIN Pin_6 // PC6 used as inverter select GPIO
#define INVERTER_GPIO GPIOC
#define INVERTER_PERIPHERAL RCC_AHB1Periph_GPIOC
#define INVERTER_USART USART6

#define MPU9250_CS_GPIO_CLK_PERIPHERAL   RCC_AHB1Periph_GPIOC
#define MPU9250_CS_GPIO       GPIOC
#define MPU9250_CS_PIN        GPIO_Pin_4
#define MPU9250_SPI_INSTANCE  SPI1

#define ACC
#define USE_ACC_MPU9250
#define USE_ACC_SPI_MPU9250
#define ACC_MPU9250_ALIGN CW270_DEG

#define GYRO
#define USE_GYRO_MPU9250
#define USE_GYRO_SPI_MPU9250
#define GYRO_MPU9250_ALIGN CW270_DEG

#define MAG
//#define USE_MAG_HMC5883

#define BARO
#define USE_BARO_MS5611

#define INVERTER
#define BEEPER
#define LED0
#define LED1
#define LED2

#define M25P16_CS_GPIO        GPIOB
#define M25P16_CS_PIN         GPIO_Pin_3
#define M25P16_SPI_INSTANCE   SPI3

#define RFM22B_CS_GPIO        GPIOA
#define RFM22B_CS_PIN         GPIO_Pin_15
#define RFM22B_SPI_INSTANCE   SPI3

#define USE_FLASHFS
#define USE_FLASH_M25P16

#define USABLE_TIMER_CHANNEL_COUNT 11

#define USE_SERIAL_1WIRE
#define S1W_TX_GPIO         GPIOB
#define S1W_TX_PIN          GPIO_Pin_10
#define S1W_RX_GPIO         GPIOB
#define S1W_RX_PIN          GPIO_Pin_11

// MPU9250 interrupt
//#define DEBUG_MPU_DATA_READY_INTERRUPT
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW
#define EXTI_CALLBACK_HANDLER_COUNT 1 // MPU data ready

#define USE_VCP

#define USE_USART1
#define USART1_RX_PIN Pin_10
#define USART1_TX_PIN Pin_9
#define USART1_GPIO GPIOA
#define USART1_APB2_PERIPHERALS RCC_APB2Periph_USART1
#define USART1_AHB1_PERIPHERALS RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_DMA2

#define USE_USART3
#define USART3_RX_PIN Pin_11
#define USART3_TX_PIN Pin_10
#define USART3_GPIO GPIOB
#define USART3_APB1_PERIPHERALS RCC_APB1Periph_USART3
#define USART3_AHB1_PERIPHERALS RCC_AHB1Periph_GPIOB

#define USE_USART6
#define USART6_RX_PIN Pin_7
#define USART6_TX_PIN Pin_6 //inverter
#define USART6_GPIO GPIOC
#define USART6_APB2_PERIPHERALS RCC_APB2Periph_USART6
#define USART6_AHB1_PERIPHERALS RCC_AHB1Periph_GPIOC

#define SERIAL_PORT_COUNT 4

#define USE_ESCSERIAL
#define ESCSERIAL_TIMER_TX_HARDWARE 0 // PWM 1

#define USE_SPI
#define USE_SPI_DEVICE_1 //MPU9250
#define USE_SPI_DEVICE_3 //dataflash

#define USE_FLASH_TOOLS

#define USE_I2C
#define I2C_DEVICE (I2CDEV_1)
//#define I2C_DEVICE_EXT (I2CDEV_2)

#define LED_STRIP
#define LED_STRIP_TIMER TIM5

#define GPS
#define BLACKBOX
#define TELEMETRY
#define SERIAL_RX
#define AUTOTUNE
#define USE_SERVOS
#define USE_CLI
