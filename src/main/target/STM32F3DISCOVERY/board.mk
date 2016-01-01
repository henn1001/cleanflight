STM32F3DISCOVERY_SRC = \
                   $(STM32F3DISCOVERY_COMMON_SRC) \
                   drivers/accgyro_adxl345.c \
                   drivers/accgyro_bma280.c \
                   drivers/accgyro_mma845x.c \
                   drivers/accgyro_mpu.c \
                   drivers/accgyro_mpu3050.c \
                   drivers/accgyro_mpu6050.c \
                   drivers/accgyro_l3g4200d.c \
                   drivers/barometer_ms5611.c \
                   drivers/compass_ak8975.c \
                   $(HIGHEND_SRC) \
                   $(COMMON_SRC)
