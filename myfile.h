#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// searches a file for an string and sets file pointer infront of string
// returns 1 if string found, 0 if not
int fsearch(FILE *fptr, char *str){
	
	// allocate memory to hold null terminated str
	int len = strlen(str);
	char *buff = malloc(len + 1);
	if(buff == 0){
		return 0;
	}
	
	// search through the file for beginning character of str
	while((buff[0] = fgetc(fptr)) != EOF){
		
		// found
		if(buff[0] == *str){
			
			// save file pointer
			long pos = ftell(fptr);
			
			// read the next chars and null terminate the buffer
			if(fread(buff + 1, len - 1, 1, fptr) == 0){
				return 0; // we are at the end of the file
			}
			buff[len] = 0;
			
			// checks for equality with search string
			if(strcmp(buff, str) == 0){
				fseek(fptr, pos - 1, SEEK_SET);	// repositioning of file pointer and exit
				free(buff);
				return 1;
			}
		}
	}
	free(buff);
	return 0;
}

// sets the file pointer to the start of a specific line
// starting with 1
int fline(FILE *fptr, int linenumber){
	char c;
	int i = 1;
	while((c = fgetc(fptr)) != EOF){
		if(c == '\n'){
			if(++i == linenumber){
				return 1;
			}
		}
	}
	return 0;
}

// copies the content of a file into another file#
// for a specific size
void fcpy(FILE *a, FILE *b, long length){
	char c;
	long i = 0;
	while((c = fgetc(a)) != EOF && i <= length){
		fputc(c, b);
		++i;
		
	}
}
