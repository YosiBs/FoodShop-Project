#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "shoppingCart.h"



typedef struct
{
	char* name;
	ShoppingCart* Cart;// array of shopping items

} Customer;

void initCustomer(Customer* pCustomer);
void printCustomer(Customer* pCustomer);


void PrintAllShoppingItems(Customer* pCustomer);

void getCustomerName(Customer* pCustomer);



void freeCustomer();// free name



#endif