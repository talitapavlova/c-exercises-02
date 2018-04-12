/*
 * 2ndProgExercises.c
 *
 * Created: 4/12/2018 9:44:16 AM
 * Author : Talita
 */ 

#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = 0xff;            // setting all I/O's in port A as outputs
	PORTA = 0xff;
	
	int a = 2;
	int b = 7;
    int c = power(&a, &b);
	PORTA = ~c;
	
	int ms1 = 1;
	int ms2 = 2;
	int ms3 = 3;
	multySwap(&ms1, &ms2, &ms3);
	
	PORTA = ~ms1;
	_delay_ms(1000);
	PORTA = ~ms2;
	_delay_ms(1000);
	PORTA = ~ms3;
	_delay_ms(1000);
}

int power(int *x, int *y) {
	int result = 1;
	for (int i = 1; i <=*y; i++) {
		result = result * *x;
	}
	return result;
}

void multySwap(int *x, int *y, int *z) {
	int temp = *x;
	*x = *y;
	*y = *z;
	*z = temp;
}

