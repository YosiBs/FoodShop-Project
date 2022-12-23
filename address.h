#ifndef _ADDRESS_H
#define _ADDRESS_H



typedef struct
{
	char* street;
	char* houseNumber;
	char* city;
} Address;

void initAddress(Address* pAddress);
void printAddress(Address* pAddress);
void freeAddress(Address* pAddress);//free street, city,house number
void fixAd(char *str);
int find_last_word(char *str);
void remove_extra_spaces(char *str);
#endif