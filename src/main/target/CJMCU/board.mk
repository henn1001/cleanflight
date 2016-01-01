CJMCU_SRC = \
                   startup_stm32f10x_md_gcc.S \
                   drivers/adc.c \
                   drivers/adc_stm32f10x.c \
                   drivers/accgyro_mpu.c \
                   drivers/accgyro_mpu6050.c \
                   drivers/bus_i2c_stm32f10x.c \
                   drivers/compass_hmc5883l.c \
                   drivers/gpio_stm32f10x.c \
                   drivers/light_led_stm32f10x.c \
                   drivers/pwm_mapping.c \
                   drivers/pwm_output.c \
                   drivers/pwm_rx.c \
                   drivers/serial_uart.c \
                   drivers/serial_uart_stm32f10x.c \
                   drivers/sound_beeper_stm32f10x.c \
                   drivers/system_stm32f10x.c \
                   drivers/timer.c \
                   drivers/timer_stm32f10x.c \
                   hardware_revision.c \
                   flight/gtune.c \
                   blackbox/blackbox.c \
                   blackbox/blackbox_io.c \
                   $(COMMON_SRC)
