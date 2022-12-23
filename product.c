#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "product.h"
#include "functions.h"
#include "superMarket.h"

const char* typeTitle[NofTypes] = { "Shelf", "Frozen", "Fridge","FruitVegtable" };


void initProduct(Product* pProduct)
{
	getProductBarcode(pProduct->barcode);
	getProductName(pProduct->name);
	pProduct->Type = getProductType();
	pProduct->price = getProductPrice();
	pProduct->unitsInStock = getUnitsInStock();
}





void printProduct(Product* pProduct)
{
	printf("%-15s\t%-15s\t%-15s\t%-15.2f\t%-15d\n", pProduct->name, pProduct->barcode, typeTitle[pProduct->Type], pProduct->price, pProduct->unitsInStock);
}

void getProductName(char* name)
{
	int len;
	char temp[MAX_STR_LEN]; 
	printf("Please Enter Product Name(max 20 chars): ");
	do {
		if (fgets(temp, MAX_STR_LEN, stdin))
		{
			temp[strcspn(temp, "\n")] = '\0';
			len = strlen(temp);
			

		}

	} while (len>20 || len==0);
	
	strcpy(name, temp);
	
}

void getProductBarcode(char* code)
{
	char temp[MAX_STR_LEN];
	do 
	{
		
			printf("Barcode Must follow this instructions:\n1.Barcode has only 7 characters in it(letters and numbers).\n2.First and last character must be letters (A-Z).\n3.There Must be at least 3,and not more than 5 numbers.\n4.All letters must be UpperCase.\n\n");

			printf("Enter Barcode: ");
			scanf("%s",&temp);

		
	} while (!isValid(temp));

	strcpy(code, temp);
}

ProductType getProductType()
{
	

	int option;
	printf("\n\n");
	do {
		printf("What is the Type of that Product? \n");
		for (int i = 0; i < NofTypes; i++)
			printf("%d for %s\n", i, typeTitle[i]);
		scanf("%d", &option);
	} while (option < 0 || option >= NofTypes);
	getchar();
	



	return (ProductType)option;
}

float getProductPrice()
{
	float price = 0;
	do 
	{
		printf("What is the Price of that Product? \n");
		scanf("%f", &price);
	} while (price<0);
	
	return price;
}

int getUnitsInStock()
{
	int stock=0;
	do 
	{
		printf("How Many Units in Stock? \n");
		scanf("%d",&stock);
	} while (stock < 0);
	return stock;
}

int isValid(char* check)
{

	if (check == NULL || strlen(check) != 7) return 0;

	int num_count = 0;

	// Check the first and last characters
	if (!isalpha(check[0]) || !isalpha(check[6])) return 0;

	// Check the middle characters
	for (int i = 1; i < 6; i++) {
		if (isdigit(check[i])) {
			num_count++;
		}
		else if (!isalpha(check[i])) {
			// Only letters and digits are allowed
			return 0;
		}
	}

	// Check if the number of digits is within the required range
	return num_count >= 3 && num_count <= 5;
}



void freeProduct(Product * pProduct)
{
	free(pProduct);
}
