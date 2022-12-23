#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "functions.h"



char* getStrExactName(const char* msg)
{
	char* str;
	char temp[MAX_STR_LEN];
	printf("%s\t", msg);
	myGets(temp, MAX_STR_LEN);

	str = getDynStr(temp);
	return str;
}

char* getDynStr(char* str)
{
	char* theStr;
	theStr = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (!theStr)
		return NULL;

	strcpy(theStr, str);
	return theStr;
}



char*  myGets(char* buffer, int size)
{
	int len;
	if (buffer != NULL && size > 0)
	{
		do {


			if (fgets(buffer, size, stdin))
			{
				buffer[strcspn(buffer, "\n")] = '\0';
				len = strlen(buffer);


			}
			else {
				*buffer = '\0';
				return NULL;
			}
		} while (len==0);
		return buffer;
	}
	return NULL;
}

char**	splitCharsToWords(char* str, int* pCount, int* pTotalLength)
{
	char temp[255];
	char* delimiters = DELEMETER;
	char* word;
	int count = 0;

	strcpy(temp, str);
	char** wordsArray = NULL;
	*pTotalLength = 0;

	word = strtok(temp, delimiters);
	while (word != NULL)
	{
		wordsArray = (char**)realloc(wordsArray, (count + 1) * sizeof(char*));
		if (!wordsArray)
			return 0;
		wordsArray[count] = getDynStr(word);
		count++;
		*pTotalLength += (int)strlen(word);
		word = strtok(NULL, delimiters);
	}
	*pCount = count;
	return wordsArray;
}