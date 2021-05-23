//#include "stddefs.h"
#include <stdint-gcc.h>

#include "murax.h"

void print(const char*str){
	while(*str){
		uart_write(UART,*str);
		str++;
	}
}
void println(const char*str){
	print(str);
	uart_write(UART,'\r');
	uart_write(UART,'\n');
}

void delay(uint32_t loops){
	for(int i=0;i<loops;i++){
		int tmp = GPIO_A->OUTPUT;
	}
}

void main() {
    GPIO_A->OUTPUT_ENABLE = 0x0000000F;
	GPIO_A->OUTPUT = 0x00000001;
    println("hello world from murax soc on spartan 3E starter");
    const int nleds = 8;
	const int nloops = 2000000;
    while(1){
        if (GPIO_A->INPUT & (1 << 8)) {
            for(unsigned int i=0;i<nleds-1;i++){
                GPIO_A->OUTPUT = 1<<i;
                delay(nloops);
                println("up");
            }
        } else {
            for(unsigned int i=0;i<nleds-1;i++){
                GPIO_A->OUTPUT = (1<<(nleds-1))>>i;
                delay(nloops);
                println("down");
            }
        }
    }
}

void irqCallback(){
}
