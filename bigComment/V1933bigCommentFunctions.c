#include "V1933bigCommentFunctions.h"

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

