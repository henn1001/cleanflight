COLIBRI_RACE_SRC = \
                   $(STM32F30x_COMMON_SRC) \
                   drivers/display_ug2864hsweg01.c \
                   drivers/accgyro_mpu.c \
                   drivers/accgyro_mpu6500.c \
                   drivers/accgyro_spi_mpu6500.c \
                   drivers/accgyro_mpu6500.c \
                   drivers/barometer_ms5611.c \
                   drivers/compass_ak8975.c \
                   drivers/compass_hmc5883l.c \
                   drivers/serial_usb_vcp.c \
                   $(HIGHEND_SRC) \
                   $(COMMON_SRC) \
                   $(VCP_SRC)
