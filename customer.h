#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "shoppingCart.h"

typedef struct
{
	char* name;
	ShoppingCart* Cart;

} Customer;

int initCustomer(Customer* pCustomer);
void printCustomer(const Customer* pCustomer);
int PrintAllShoppingItems(const Customer* pCustomer);
int getCustomerName(Customer* pCustomer);
void freeCustomer(Customer* pCustomer);
#endif