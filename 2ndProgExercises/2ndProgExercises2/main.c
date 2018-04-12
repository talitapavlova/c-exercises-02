/*
 * 2ndProgExercises2.c
 *
 * Created: 4/12/2018 10:22:45 AM
 * Author : Talita
 */ 

#define F_CPU 10000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = 0xff;            // setting all I/O's in port A as outputs
	PORTA = 0xff;
	
    int s = 10;
	int arr[s];
	int arr1[s];
	for(int i = 0; i < s; i++) {
		arr[i] = i;				// numbers from 0 to 9
		arr1[i] = i;			// numbers from 0 to 9
	}
	
	for (int i = 0; i < s; i++) {
		PORTA = ~(arr[i]);		
		_delay_ms(1000);
	}
	
	int sum = sum_arrays(arr, arr1, s);		// the sum is equal to 90
	PORTA = ~sum;							// output bit pattern on the leds 0b0101_1010
	_delay_ms(1000);
}

int sum_arrays(int a[], int b[], int size) {
	int sum;
	int sum_a = sum_array(a, size);
	int sum_b = sum_array(b, size);
	sum = sum_a + sum_b;
	return sum;
}

int sum_array(int a[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return sum;
}
