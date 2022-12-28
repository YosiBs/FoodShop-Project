#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include "customer.h"
#include "functions.h"
#include "shoppingItem.h"



int initCustomer(Customer* pCustomer)
{
	getCustomerName(pCustomer);
	pCustomer->Cart = (ShoppingCart*)calloc(1, sizeof(ShoppingCart));
	if (!pCustomer->Cart)
	{
		free(pCustomer->name);
		return 0;
	}
	return 1;
}

void printCustomer(const Customer* pCustomer)
{
	printf("\nCustomer Name: %s\n", pCustomer->name);
	if (pCustomer->Cart->difItemsInCart>0)
	{
		printf("Customer in Shopping Progrress\n");
	}
	else {
		printf("Cart is Empty..\n");
	}
}

int PrintAllShoppingItems(const Customer* pCustomer)
{
	int i;
	if (pCustomer->Cart->difItemsInCart != 0)
	{
		for (i = 0; i < pCustomer->Cart->difItemsInCart; i++)
		{
			printf("item %d: %s\n",i+1, pCustomer->Cart->ItemArr[i]->barcode);
			return 1;
		}
	}
	else {
		printf("Cart is Empty..\n");
		return 1;
	}
	return 1;
}

int getCustomerName(Customer* pCustomer)
{
	pCustomer->name= getStrExactName("Enter Customer Name: ");
	if (!pCustomer->name)
	{
		free(pCustomer->name);
		return 0;
	}
	return 1;
}



void freeCustomer(Customer* pCustomer)
{
	freeShoppingCart(pCustomer->Cart);
	free(pCustomer->Cart->ItemArr);
	free(pCustomer->Cart);
	free(pCustomer->name);
	//free(pCustomer);
}
