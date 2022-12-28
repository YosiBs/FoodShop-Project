#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "shoppingCart.h"



typedef struct
{
	char* name;
	ShoppingCart* Cart;// array of shopping items

} Customer;

int initCustomer(Customer* pCustomer);
void printCustomer(Customer* pCustomer);//CONST?
int PrintAllShoppingItems(Customer* pCustomer);//CONST?
int getCustomerName(Customer* pCustomer);
void freeCustomer(Customer* pCustomer);

#endif