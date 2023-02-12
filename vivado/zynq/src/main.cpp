#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <xparameters.h>
#include <xgpio.h>
XGpio gpio;

int main()
{
    init_platform();

    print("Hello! World!\n\r");
    int status ;

      status = XGpio_Initialize(&gpio, XPAR_GPIO_0_DEVICE_ID);
      if (status != XST_SUCCESS) {
    	  print("Fail to init!\n\r");
        return 1;
      }

    XGpio_SetDataDirection(&gpio, 1, 0);
    XGpio_DiscreteWrite(&gpio, 1, 0xFF);
    print("Successfully ran Hello World application");
    cleanup_platform();
    return 0;
}
