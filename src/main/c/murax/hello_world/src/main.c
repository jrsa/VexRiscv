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
    println("hello world from murax soc on colorlight");
    const int nleds = 8;
	const int nloops = 200000;

    // lol
    // WAVEGEN->FREQUENCY = ...;
    int start_freq = 0x24dd2f;
    *((int*) 0xf0030000) = start_freq;

    while (1) {
        for (char c = 'a'; c <= 'z'; ++c) {
            GPIO_A->OUTPUT ^= 1;
            delay(nloops);
            uart_write(UART, c);
            *((int*) 0xf0030000) = (start_freq * (GPIO_A->OUTPUT + 1));

        }
        uart_write(UART, '\r');
        uart_write(UART, '\n');
    }

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
