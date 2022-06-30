#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* searches a file for an string starting at current file pointer
 * finally sets file pointer infront of string
 * returns 1 if string found, 0 if not
 * uses malloc
 */
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

/* sets the file pointer to the start of a specific line
 * starting from beginning of file within line 1
 * returns 1 if line exist's, 0 if not
 */
int fline(FILE *fptr, int linenumber){
	
	// sets the filepointer to beginning of file
	fseek(fptr, 0, SEEK_SET);
	
	// counts the newlines untile we hit linenumber
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

/* returns the filesize without changing the file pointer
 */
long fsize(FILE *fptr){
	long tmp = ftell(fptr); // saving file pointer
	
	fseek(fptr, 0, SEEK_END);
	long size = ftell(fptr); // getting filesize
	
	fseek(fptr, tmp, SEEK_SET); // restoring file pointer
	return size;
}

/* copies the content of a file into another file
 * for a specific size
 */
void fcpy(FILE *a, FILE *b, long length){
	char c;
	long i = 0;
	while((c = fgetc(a)) != EOF && i++ < length){
		fputc(c, b);
	}
}
