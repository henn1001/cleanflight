OLIMEXINO_SRC = startup_stm32f10x_md_gcc.S \
                   drivers/accgyro_mpu.c \
                   drivers/accgyro_mpu6050.c \
                   drivers/adc.c \
                   drivers/adc_stm32f10x.c \
                   drivers/barometer_bmp085.c \
                   drivers/bus_i2c_stm32f10x.c \
                   drivers/bus_spi.c \
                   drivers/compass_hmc5883l.c \
                   drivers/gpio_stm32f10x.c \
                   drivers/light_led_stm32f10x.c \
                   drivers/light_ws2811strip.c \
                   drivers/light_ws2811strip_stm32f10x.c \
                   drivers/pwm_mapping.c \
                   drivers/pwm_output.c \
                   drivers/pwm_rx.c \
                   drivers/serial_softserial.c \
                   drivers/serial_uart.c \
                   drivers/serial_uart_stm32f10x.c \
                   drivers/sonar_hcsr04.c \
                   drivers/sound_beeper_stm32f10x.c \
                   drivers/system_stm32f10x.c \
                   drivers/timer.c \
                   drivers/timer_stm32f10x.c \
                   $(HIGHEND_SRC) \
                   $(COMMON_SRC)
