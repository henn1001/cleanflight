MOTOLAB_SRC = \
                   $(STM32F30x_COMMON_SRC) \
                   drivers/accgyro_mpu.c \
                   drivers/accgyro_mpu6050.c \
                   drivers/barometer_ms5611.c \
                   drivers/compass_hmc5883l.c \
                   drivers/display_ug2864hsweg01.c \
                   drivers/serial_usb_vcp.c \
                   drivers/flash_m25p16.c \
                   io/flashfs.c \
                   $(HIGHEND_SRC) \
                   $(COMMON_SRC) \
                   $(VCP_SRC)
