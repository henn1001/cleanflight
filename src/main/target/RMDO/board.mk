RMDO_SRC = \
                   $(STM32F30x_COMMON_SRC) \
                   drivers/accgyro_mpu.c \
                   drivers/accgyro_mpu6050.c \
                   drivers/barometer_bmp280.c \
                   drivers/display_ug2864hsweg01.h \
                   drivers/flash_m25p16.c \
                   drivers/serial_softserial.c \
                   drivers/sonar_hcsr04.c \
                   io/flashfs.c \
                   $(HIGHEND_SRC) \
                   $(COMMON_SRC)
