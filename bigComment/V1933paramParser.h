#define __V1933PARAMPARSER

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



void makeParams(params_t *param, int *argc, char **argv){
/* param list
	arg       | global
	silent    | read
	spacing   | calculate
	maxLen    | read
	maxChars  | calculate
	spaceSize | read
	charWidth | global
*/
	int i = 0;
	char silentString[]    = "--silent";
	char maxLenString[]    = "--maxLen";
	char spaceSizeString[] = "--spaceSize";

	param->arg       = 1;     // checking first param (start value)
	param->spaceSize = -1;    // unset value
	param->silent    = false; // defult value
	param->charWidth = 5;     // default charWidth constant;

	// configuring rest parameters depending on input
	// we await the parameters to be before the printable string
	// start values of the rest parameters are 0, so we are able to know,
	// whether they were set by the user or not, if not -- default values are used

	while (param->arg < *argc - 1){
		if (argv[param->arg] == strstr(argv[param->arg], silentString)){
			// checking for '\0' after --silent
			if (strlen(argv[param->arg]) != strlen(silentString)){
				wrongParameterErr(argv[param->arg]);
			}
			// checking for silent allready set
			if (param->silent){
				allreadySetErr(silentString);
			}
			param->silent = true;
		}else if (argv[param->arg] == strstr(argv[param->arg], maxLenString)){
			// checking for maxLen allready set
			if (param->maxLen){
				allreadySetErr(maxLenString);
			}
			// checking for having only numbers after --maxLen
			i = strlen(maxLenString);
			if (*(argv[param->arg] + i) == '\0'){
				noNumbersErr(maxLenString);
			}
			while (*(argv[param->arg] + i) != '\0'){
				if (!isNumber(argv[param->arg] + i)){
					noNumbersErr(maxLenString);
				}
				i++;
			}
			param->maxLen = atoi(argv[param->arg] + strlen(maxLenString));
		}else if (argv[param->arg] == strstr(argv[param->arg], spaceSizeString)){
			// checking for spaceSize allready set
			if (param->spaceSize != -1){
				allreadySetErr(spaceSizeString);
			}
			// checking for having only numbers after --spaceSize
			i = strlen("--spaceSize");
			if (*(argv[param->arg] + i) == '\0'){
				noNumbersErr(spaceSizeString);
			}
			while (*(argv[param->arg] + i) != '\0'){
				if (!isNumber(argv[param->arg] + i)){
					numbersErr(spaceSizeString);
				}
				i++;
			}
			param->spaceSize = atoi(argv[param->arg] + strlen(spaceSizeString));
		}else{
			wrongParameterErr(argv[param->arg]);
		}
		param->arg++;
	}
	if (!param->maxLen){
		param->maxLen = 80;
	}
	if (param->spaceSize == -1){
		param->spaceSize = 1;
	}
	// calculate maxChars and spacing
	param->maxChars = (param->maxLen - param->charWidth) / (param->charWidth + param->spaceSize) + 1;

	param->spacing = (char*)calloc(param->spaceSize + 1, sizeof(char));
	for (i = 0; i < param->spaceSize; i++){
		*(param->spacing + i) = ' ';
	}
	*(param->spacing + i) = '\0'; // setting last char to \0 to interrupt string printing
}

void wrongParameterErr(char *parName){
	fprintf(stderr, "ERROR: wrong parameter %s\n", parName);
	exit(EXIT_FAILURE);
}

void allreadySetErr(char *parName){
	fprintf(stderr, "ERROR: %s allready set\n", parName);
	exit(EXIT_FAILURE);
}

void numbersErr(char *parName){
	fprintf(stderr, "ERROR: only numbers are alloud after %s\n", parName);
	exit(EXIT_FAILURE);
}

void noNumbersErr(char *parName){
	fprintf(stderr, "ERROR: no numbers after %s\n", parName);
	exit(EXIT_FAILURE);
}
