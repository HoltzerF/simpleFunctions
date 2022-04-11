// -----------------------------------------------
// - dest is always the destination buffer
// - src is always the source buffer
// - b_size is always the destination buffer size,
// char buf[10]; the b_size is 10
// - algorithms dont operate above the b_size of a
// destination buffer
// - algorithms always null terminate strings
// -----------------------------------------------


int charToInt(char c){
	return c - '0';
}

int strlen_s(char *s, int b_size){
	int i;
	for(i = 0; i < b_size; ++i)
		if(s[i] == '\0')
    		break;
	return i;
}

int strcpy_s(char *dest, char *src, int b_size){
	int i;
	for(i = 1; *src && i < b_size; ++i)
		*dest++ = *src++;
		
	*dest = '\0';
	return i - 1;
}

void strcat_s(char *dest, char *src, int b_size){
	
	int len = strlen_s(dest, b_size);
	char *ptr = dest + len;
	
	while(*src != '\0' && ++len < b_size)
		*ptr++ = *src++;
		
	*ptr = '\0';
}

char *strchr_s(char *str, char c, int b_size){
	int i = 0;
	while(*str != 0 && ++i < b_size){
		if(*str == c)
			return str;
		str++;
	}
	return 0;
}
