/*
 * This configuration is not worked yet
 */
#include "i2c.h"
#include "types.h"
void delay(uint32 value) {
    while (value--) {}
}

void I2CMasterInit(uint8 slaveAddr) {
    SYSCTL_RCGCI2C_R |= SYSCTL_RCGCI2C_R0;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
    delay(10); // Delay to ensure the peripheral is ready

    GPIO_PORTB_AFSEL_R |= (0x02 | 0x04);
    GPIO_PORTB_DEN_R |= (0x02 | 0x04);
    GPIO_PORTB_ODR_R |= 0x04;

    GPIO_PORTB_PUR_R |= (0x02 | 0x04);

    GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB2_I2C0SCL | GPIO_PCTL_PB3_I2C0SDA; // Configure pins for I2C

    // Disable I2C0 during configuration
    I2C0_MCR_R = 0x00000000;
    I2C0_MTPR_R = 79;
    I2C0_MSA_R = (slaveAddr << 1);
    I2C0_MCR_R = 0x00000010;
}

void I2CMasterSend(uint8 data) {

    I2C0_MDR_R = data;
    I2C0_MCS_R = 0x00000007; // Start, Run, Stop
    while (I2C0_MCS_R & 0x00000001);
}

