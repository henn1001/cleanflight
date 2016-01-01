SPARKY_SRC = \
                   $(STM32F30x_COMMON_SRC) \
                   drivers/display_ug2864hsweg01.c \
                   drivers/accgyro_mpu.c \
                   drivers/accgyro_mpu6050.c \
                   drivers/barometer_ms5611.c \
                   drivers/compass_ak8975.c \
                   drivers/serial_usb_vcp.c \
		   drivers/sonar_hcsr04.c \
                   $(HIGHEND_SRC) \
                   $(COMMON_SRC) \
                   $(VCP_SRC)
