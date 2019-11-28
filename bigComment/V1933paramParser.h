#ifndef __V1933PARAMPARSER
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

typedef struct params_s {
	int            arg;
	char           silent;
	char          *spacing;
	signed char    spaceSize;
	unsigned short maxLen;
	unsigned char  maxChars;
	unsigned char  charWidth;
} params_t;

char isLowerCase(char*);
char isLetter(char*);
char isNumber(char*);
char isSpace(char*);
void makeParams(params_t*, int*, char**);
void wrongParameterErr(char*);
void allreadySetErr(char*);
void numbersErr(char*);
void noNumbersErr(char*);
#define __V1933PARAMPARSER
#endif
