#include <stdio.h>

int bitTest(char byte, int n){
	return (byte & (1 << n)) > 0;
}

void bitSet(char *byte, int n){
	*byte |= (1 << n);
}

void bitDel(char *byte, int n){
	*byte &= ~(1 << n);
}

void bitTgl(char *byte, int n){
	*byte ^= (1 << n);
}

void printByte(char byte){
	int i = 7;
	while(i >= 0){
		printf("%c ", '0' + bitTest(byte, i--));
	}
}

void printBytes(void *bytes, int n){
	char *ptr = (char *)bytes;
	while(n > 0){
		printByte(ptr[--n]);
		putchar(' ');
	}
}
