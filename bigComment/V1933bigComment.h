#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "V1933paramParser.h"
#define __V1933BIGCOMMENT

char isPrintable(char*);
char isLowerCase(char*);
char isLetter(char*);
char isNumber(char*);
char isSpace(char*);
int  convertLetter(char*);
int  convertNumber(char*);

char isPrintable(char *c){
	return (isNumber(c)    ||
		    isLetter(c)    ||
		    isLowerCase(c) ||
		    isSpace(c));
}

char isLowerCase(char *c){
	return (*c >= 'a' && *c <= 'z');
}

char isLetter(char *c){
	return (*c >= 'A' && *c <= 'Z');
}

char isNumber(char *c){
	return (*c >= '0' && *c <= '9');
}

char isSpace(char *c){
	return (*c == ' ');
}

int convertLetter(char *c){
	return (int)(*c - 'A');
}

int convertNumber(char *c){
	return (int)(*c - '0');
}
