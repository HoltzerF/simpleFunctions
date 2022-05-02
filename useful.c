#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

#define min3(a, b, c) (a < b ? min(a, c) : min(b, c))
#define max3(a, b, c) (a < b ? max(b, c) : max(a, c))

// getting the absolute value of an integer
int absolute(int n){
	if(n < 0)
		return -n;
	return n;
}

// returns the greates common divisor of two positive numbers
int gcdPos(int a, int b){
	while(a != b){
		if(a > b){
			a -= b;
		}else{
			b -= a;
		}
	}
	return a;
}

// returns the greatest common divisor
int gcd(int a, int b){
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	
	while(a != b){
		if(a > b){
			a -= b;
		}else{
			b -= a;
		}
	}
	return a;
}

// reverses an byte array
void bytesRev(void *mem, int len){
	char *beg = (char *)mem;
	char *end = beg + len - 1;
	
	while(beg < end){
		char temp = *end;
		*end-- = *beg;
		*beg++ = temp;
	}
}

// swapping two memory areas
void swapMem(void *a, void *b, int size){
	char *p_a = (char *)a;
	char *p_b = (char *)b;
	
	do{
		char temp = *p_a;
		*p_a++ = *p_b;
		*p_b++ = temp;
	}while(--size > 0);
}

// calculates the factorial, mind integer overflow
int factorial(int n){
	int i, faco;
	for(i = 1, faco = 1; i <= n; i++){
  		faco *= i;
	}
	return faco;
}

// checks if a number is prime
int isPrime(int n){
	int i;
	for(i = 2; i <= n / 2; ++i){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

// maps a range and a specific value in that range to another range, inclusive
float range(float value, float min, float max, float mmin, float mmax){
	return (mmax - mmin) * ((value - min) / (max - min)) + mmin;
}

// maps random values to a given range
float mrand(float min, float max){
	return range(rand(), 0, RAND_MAX, min, max);
}

// returns the fibonacci number for a specific position
// if h is smaller than zero, function returns -1
int fibonacci(int h){
	int l, n, f;	// last, new, fibo
	f = l = -1;
	n = 1;
	
	while(h-- > -1){
		f = l + n;
		l = n;
		n = f;
	}
	
	return f;
}

// same as n % 2
int mod2(int n){
	return (n & 1) * (1 - 2 * (n < 0));
}

// same as n % m
int mod(int n, int m){
    return (n - m * (n / m));
}

int main(){
	
	return 0;
}
