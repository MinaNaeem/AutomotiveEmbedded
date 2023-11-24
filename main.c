#include "i2c.h"

int main(void)
{
I2CMasterInit(20);

uint8 i = 0 ;
for(i = 0; i < 21 ;i++ )
{
    I2CMasterSend(0x30);
    delay(2000);

}

return 0;
}
