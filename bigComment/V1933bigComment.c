#include "V1933bigComment.h"

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("usage: $%s [--maxLen\\d+|--silent|--spaceSize\\d+] \"wordsToConvert\"\n", argv[0]);
		return 0;
	}

	int            i = 0;
	int            j = 0;
	int            effectiveStrlen = 0;
	int            arg = 0;
	char          *inpText;
	char          *outString;
	char          *printString;
	char          *silent;
	char          *spacing;
	unsigned char *maxChars;
	params_t      *param;


	char space[] = "     ";
	char numbers[][5][6] = {
		{
			"#####",
			"#   #",
			"#   #",
			"#   #",
			"#####"
		},{
			"  #  ",
			" ##  ",
			"# #  ",
			"  #  ",
			"#####"
		},{
			" ### ",
			"#   #",
			"   # ",
			"  #  ",
			" ####"
		},{
			"#####",
			"    #",
			"#####",
			"    #",
			"#####"
		},{
			"#   #",
			"#   #",
			"#####",
			"    #",
			"    #"
		},{
			"#####",
			"#    ",
			"#####",
			"    #",
			"#####"
		},{
			"#####",
			"#    ",
			"#####",
			"#   #",
			"#####"
		},{
			"#####",
			"   # ",
			"  ###",
			"   # ",
			"   # "
		},{
			"#####",
			"#   #",
			"#####",
			"#   #",
			"#####",
		},{
			"#####",
			"#   #",
			"#####",
			"    #",
			"#####"
		}
	};
	char letters[][5][6] = {
		{
			" ### ",
			"#   #",
			"#####",
			"#   #",
			"#   #"
		},{
			"#### ",
			"#   #",
			"#####",
			"#   #",
			"#### "
		},{
			" ### ",
			"#   #",
			"#    ",
			"#   #",
			" ### "
		},{
			"#### ",
			"#   #",
			"#   #",
			"#   #",
			"#### "
		},{
			"#####",
			"#    ",
			"#####",
			"#    ",
			"#####"
		},{
			"#####",
			"#    ",
			"#### ",
			"#    ",
			"#    "
		},{
			" ####",
			"#    ",
			"#  ##",
			"#   #",
			" ####"
		},{
			"#   #",
			"#   #",
			"#####",
			"#   #",
			"#   #",
		},{
			" ### ",
			"  #  ",
			"  #  ",
			"  #  ",
			" ### "
		},{
			"  ###",
			"   # ",
			"   # ",
			"#  # ",
			" ##  "
		},{
			"#   #",
			"# ## ",
			"##   ",
			"# ## ",
			"#   #"
		},{
			"#    ",
			"#    ",
			"#    ",
			"#   #",
			"#####"
		},{
			"#   #",
			"## ##",
			"# # #",
			"#   #",
			"#   #"
		},{
			"#   #",
			"##  #",
			"# # #",
			"#  ##",
			"#   #",
		},{
			" ### ",
			"#   #",
			"#   #",
			"#   #",
			" ### "
		},{
			"#### ",
			"#   #",
			"#### ",
			"#    ",
			"#    "
		},{
			" ### ",
			"#   #",
			"#   #",
			"# ###",
			" ####"
		},{
			"#### ",
			"#   #",
			"#### ",
			"# ## ",
			"#   #"
		},{
			" ####",
			"#    ",
			" ### ",
			"    #",
			"#### "
		},{
			"#####",
			"  #  ",
			"  #  ",
			"  #  ",
			"  #  "
		},{
			"#   #",
			"#   #",
			"#   #",
			"#   #",
			" ### "
		},{
			"#   #",
			"#   #",
			" # # ",
			" # # ",
			"  #  "
		},{
			"#   #",
			"#   #",
			"# # #",
			"## ##",
			"#   #"
		},{
			"#   #",
			" # # ",
			"  #  ",
			" # # ",
			"#   #"
		},{
			"#   #",
			" # # ",
			"  #  ",
			"  #  ",
			"  #  "
		},{
			"#####",
			"   # ",
			"  #  ",
			" #   ",
			"#####"
		}
	};

	// set default values
	param     = (params_t*)calloc(1, sizeof(params_t)); // zero'ing all params
	// printString = (char*)malloc(sizeof(char));
	
	makeParams(param, &argc, argv);
	arg       =   param->arg;
	spacing   =   param->spacing;
	silent    = &(param->silent);
	maxChars  = &(param->maxChars);
	inpText   = argv[arg];
	
	// counting printable characters
	i = 0;
	effectiveStrlen = 0;
	while (*(inpText + i) != '\0'){
		if (isPrintable(inpText + i)){
			effectiveStrlen++;
		}
		i++;
	}
	// copying needed chars into outString
	outString = (char*)calloc(effectiveStrlen + 1, sizeof(char));
	i = 0;
	j = 0;
	while (*(inpText + i) != '\0'){
		if (isPrintable(inpText + i)){
			if (isLowerCase(inpText + i)){
				*(outString + j) = *(inpText + i) - 'a' + 'A';
			}else{
				*(outString + j) = *(inpText + i);
			}
			j++;
		}
		i++;
	}

	if (!*silent && effectiveStrlen > *maxChars){
		fprintf(stderr,
		        "WARNING: string length exceeds max length\n"
		        "         max length is %d\n"
		        "         printing only the first %d chars of the string\n",
		        *maxChars, *maxChars);
	}

	// choosing the length = min(j, maxChars)
	if (effectiveStrlen < *maxChars){
		*maxChars = effectiveStrlen;
	}

	// printing!
	i = 0;
	while (i < 5){ // 5 charHeight
		j = 0;
		while (j < *maxChars){
			if (isLetter(outString + j)){
				printString = letters[convertLetter(outString + j)][i];
			}else if (isNumber(outString + j)){
				printString = numbers[convertNumber(outString + j)][i];
			}else if (isSpace(outString + j)){
				printString = space;
			}
			printf("%s", printString);
			if (j < *maxChars - 1){
				printf("%s", spacing);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	exit(EXIT_SUCCESS);
}

