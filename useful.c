#include <stdlib.h>
#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

#define min3(a, b, c) (a < b ? min(a, c) : min(b, c))
#define max3(a, b, c) (a < b ? max(b, c) : max(a, c))

//copy memory
void _memcpy(void *dest, void *src, int n){
	char *p_src = (char *)src;
	char *p_dest = (char *)dest;
	
	int i;
	for(i = 0; i < n; ++i){
		p_dest[i] = p_src[i];
	}
}

//finding the greates common divisor of two positiv integers
int _gcd(int a, int b){
	while(a != b){
        if(a > b)
            a -= b;
        else
            b -= a;
	}
	return a;
}

//getting the absolute value of number
int _absolute(int n){
	if(n < 0){
		return -n;
	}
	return n;
}

//calculates the factorial at position n
int _factorial(int n){
	int i, facu;
	for(i = 1, facu = 1; i <= n; i++){
  		facu *= i;
	}
	return facu;
}

//checks if number is prime
int _isPrime(int n){
	int i;
	for(i = 2; i <= n / 2; ++i){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

//tries to find two numbers p and q which are prime factors of n
//if algorithm can find two numbers it returns 1 and both numbers as p and q
//if algorithm cannot find two numbers it returns 0
int getPrimeProduct(int n, int *p, int *q){
    int i, j;
    
    //running through every number smaller than n, from top to bottom
    for(i = n - 1; i > 0; --i){

        //i is factor of n and a prime number
        if((n % i == 0) && _isPrime(i)){
            
            //checking every prime smaller equal to i
            for(j = i; j > 0; --j){
                
                //j is factor of n and a prime number
                if(n % i == 0 && _isPrime(j)){
                    
                    //if product of the two calculated number is n return i and j
                    if(i * j == n){
                        *p = j;
                        *q = i;
                        return 1;
                    }
                    
                    //if product smaller, there is no number left
                    if(i * j < n){
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

//swapping two memory areas
void _swapAny(void *a, void *b, int size){
	char *p_a = (char *)a;
	char *p_b = (char *)b;
	
	do{
		char temp = *p_a;
		*p_a++ = *p_b;
		*p_b++ = temp;
	}while(--size > 0);
}

//swap two integers -> more time less memory
void _s_swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

//swap two integers -> more memory less time
void _swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//random using a minimum and maximum value
int _random(int min, int max){
	return min + rand() % (max - min);
}

//destination buffer, source buffer, destination buffer size
int _strcpy(char *dest, char *src, int b_size){
	int i;
	char *temp;
	for(i = 0, temp = src, --b_size; i < (b_size) && (*src); ++i)
		*dest++ = *src++;
	*dest = '\0';
	return (src - temp);
}

//string to count, buffer size of s
int _strlen(char *s, int b_size){
	int i;
	for(i = 0; i < b_size; ++i)
		if(s[i] == '\0')
    		break;
	return i;
}

//test if two strings are equal
int _streql(char *s0, char *s1){
	while(*s0){
		if(*s1 == 0 || *s1++ != *s0++){
			return 1;
		}
	}
	if(*s1 != 0){
		return 1;
	}
	return 0;
}

int main(){
	return 0;
}
