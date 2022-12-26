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

void printCustomer(Customer* pCustomer)
{
	printf("\nCustomer Name: %s\n", pCustomer->name);
	printf("Items in Cart: \n");
	PrintAllShoppingItems(pCustomer);
}

int PrintAllShoppingItems(Customer* pCustomer)
{
	int i;
	if (pCustomer->Cart->difItemsInCart != 0)
	{
		for (i = 0; i < pCustomer->Cart->difItemsInCart; i++)
		{
			printf("item %d: %s\n",i+1, pCustomer->Cart->ItemArr[i]);
			return 1;
		}
	}
	else {
		printf("Cart is Empty..\n");
		return 1;
	}
	
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
	free(pCustomer->name);
}
