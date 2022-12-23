#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#define MAX_STR_LEN 255
#define DELEMETER "#"

char*	getStrExactName(const char* msg);
char*	myGets(char* buffer, int size);
char*	getDynStr(char* str);
char**	splitCharsToWords(char* str, int* pCount, int* pTotalLength);


#endif