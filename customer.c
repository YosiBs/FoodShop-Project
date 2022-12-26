#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include "customer.h"
#include "functions.h"
#include "shoppingItem.h"



void initCustomer(Customer* pCustomer)
{
	getCustomerName(pCustomer);
	pCustomer->Cart = (Customer*)calloc(1, sizeof(Customer));
	if (!pCustomer->Cart)
	{
		return 0;
	}
}

void printCustomer(Customer* pCustomer)
{
	printf("Customer Name: %s\n", pCustomer->name);
	printf("Items in Cart: \n");
	PrintAllShoppingItems(pCustomer);
}

void PrintAllShoppingItems(Customer * pCustomer)
{

	
}

void getCustomerName(Customer* pCustomer)
{
	pCustomer->name= getStrExactName("Enter Customer Name: ");
}



void freeCustomer(Customer* pCustomer)
{
	free(pCustomer);
}
