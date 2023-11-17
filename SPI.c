#include "inc/tm4c123gh6pm.h"
#include "types.h"
#include "SPI0.h"
#define GET_BIT(REG,BIT) (((REG)&(1<<(BIT)))>>(BIT))
#define CLOCK_FREQ 16000000 // Assuming a system clock of 16MHz
#define DESIRED_SPI_CLK_SPEED 1000000 // Desired SPI clock speed (1MHz in this case)

volatile int x;
void init_SPI0MASTER() {
  
     // Enable the SSI0 module clock

    SYSCTL_RCGCSSI_R |= SYSCTL_RCGCSSI_R0;
    // Enable the GPIO port that is used for the SSI0 function (e.g., Port A)
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; // Replace 0 with the appropriate value for the GPIO port

    // Configure the appropriate pins for the SSI0 function
    
    GPIO_PORTA_AFSEL_R |= ((1<<2) | (1<<3) | (1<<4) | (1<<5)); // Replace X with the GPIO port letter and define the pins for CLK, FSS, RX, TX
    GPIO_PORTA_PCTL_R =  0x00222200; // Replace X with the GPIO port letter and configure the pins for SSI function
    GPIO_PORTA_DEN_R |= ((1<<2) | (1<<3) | (1<<4) | (1<<5)); // Replace X with the GPIO port letter and enable the pins for digital I/O
    

    // Disable SSI0 module before configuring it AS MASTER
    
    SSI0_CR1_R = 0X00;
    

    // Configure SSI0 operation mode, clock frequency, and data frame format
    SSI0_CC_R = 0x0; // Use system clock
    SSI0_CPSR_R =  0x10  ; // Set clock prescaler
    SSI0_CR0_R = 0x07;// Set clock rate
    
    //Enable master
    
    SSI0_CR1_R |= 0x02;
    
    
    
}
void init_SPI0SLAVE() {
  
     // Enable the SSI0 module clock

    SYSCTL_RCGCSSI_R |= SYSCTL_RCGCSSI_R0;
    // Enable the GPIO port that is used for the SSI0 function (e.g., Port A)
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; // Replace 0 with the appropriate value for the GPIO port

    // Configure the appropriate pins for the SSI0 function
    
    GPIO_PORTA_AFSEL_R |= ((1<<2) | (1<<3) | (1<<4) | (1<<5)); // Replace X with the GPIO port letter and define the pins for CLK, FSS, RX, TX
    GPIO_PORTA_PCTL_R =  0x00222200; // Replace X with the GPIO port letter and configure the pins for SSI function
    GPIO_PORTA_DEN_R |= ((1<<2) | (1<<3) | (1<<4) | (1<<5)); // Replace X with the GPIO port letter and enable the pins for digital I/O
    

    // Disable SSI0 module before configuring it
    
    SSI0_CR1_R = 0X00;
    
    // Enable SST0 as slave
    
    SSI0_CR1_R = 0X04;

    // Configure SSI0 operation mode, clock frequency, and data frame format
    SSI0_CC_R = 0x0; // Use system clock
    SSI0_CPSR_R =  0x10  ; // Set clock prescaler
    SSI0_CR0_R = 0x07;// Set clock rate
    
    // Enable SSI0 module and interrupts
    
    SSI0_IM_R |= SSI_IM_RXIM; // Enable receive FIFO interrupt
    NVIC_EN0_R |= (1 << 7); // Enable SSI0 interrupt in NVIC
    
    SSI0_CR1_R |= 0x02;
    
    
    
}
void SSI0_Handler() {

  
  x=SPI0_receive(15);
}
uint16 SPI0_receive(uint16 DATA){
    // Wait until receive FIFO is not empty
  while ((SSI0_SR_R & 1)==0);
    
    // send data
    SSI0_DR_R=DATA;
    
    // Read received data from the data register
    return (uint16)(SSI0_DR_R & 0xFF);
}
uint16 SPI0_send(uint16 msg){
    // Wait until receive FIFO is not empty
  while ((SSI0_SR_R & 1)==0);
    
    // send data
    SSI0_DR_R=msg;
    
    // Read received data from the data register
    return (uint16)(SSI0_DR_R & 0xFF);
}
