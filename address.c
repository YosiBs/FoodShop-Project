#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "address.h"
#include "functions.h"


void initAddress(Address* pAddress)
{
	int i;
	char* addressInput;
	addressInput = getStrExactName("Please Enter an address for the SuperMarket.\nThe address need's to be as follow:\nStreet#House Number#City\n\nFor Example: Alenbi#20#Tel Aviv\nYou can use up to 254 chars.\n\n");
	int wordCount = 0;
	int totalLength=0;
	char** addressArr=NULL;
	addressArr=splitCharsToWords(addressInput, &wordCount, &totalLength);
	//need to fix the address before applying it.
	for (i=0;i<3; i++)
	{
		fixAd(addressArr[i]);

	}
	pAddress->street = addressArr[0];
	pAddress->houseNumber = addressArr[1];
	pAddress->city = addressArr[2];
	
	
	
	
	free(addressInput);
	free(addressArr);


}

void printAddress(Address* pAddress)
{
	printf("Address: %s %s,%s \n", pAddress->street, pAddress->houseNumber, pAddress->city);
	
}
void fixAd(char *str) {
	int i, j, len,lastWordIndex;
	int last_word_start = 0;

	// Convert the first letter of the string to uppercase
	if (str[0] >= 'a' && str[0] <= 'z') {
		str[0] -= 32;
	}

	// Find the length of the string
	len = strlen(str);

	// Loop through the string
	for (i = 0; i < len; i++) {
		// If we find a space, check the next character
		if (str[i] == ' ') {
			// If the next character is a letter, convert it to uppercase
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
				str[i + 1] -= 32;
			}
			str = (char*)realloc(str, (len + 2) * sizeof(char));
			str[len + 2] = 0;
			str[len + 1] = 0;
			// Insert two spaces after the current space
			for (j = len + 1; j > i + 1; j--) {
				
				str[j] = str[j - 2];
			}
			str[i + 1] = ' ';
			str[i + 2] = ' ';
			len += 2;
			i += 2;
		}
		remove_extra_spaces(str);
		lastWordIndex=find_last_word(str);
		if (str[lastWordIndex] >= 'A' && str[lastWordIndex] <= 'Z' && lastWordIndex != 0) {
			str[lastWordIndex] += 32;
		}

	}

	
}
int find_last_word(char *str) {
	int i, len;

	// Find the length of the string
	len = strlen(str);

	// Find the index of the first letter in the last word
	for (i = len - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			return i + 1;
		}
	}

	// If there are no spaces in the string, the last word starts at the beginning
	return 0;
}
void remove_extra_spaces(char *str) {
	int i, j, len;

	// Find the length of the string
	len = strlen(str);

	// Loop through the string
	for (i = 0; i < len; i++) {
		// If we find three spaces in a row, remove one of them
		if (str[i] == ' ' && str[i + 1] == ' ' && str[i + 2] == ' ') {
			for (j = i + 1; j < len; j++) {
				str[j] = str[j + 1];
			}
			len--;
			i--;
		}
	}
}





void freeAddress(Address* pAddress)
{
	free(pAddress->city);
	free(pAddress->houseNumber);
	free(pAddress->street);

}
