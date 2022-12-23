#ifndef _SUPER_MARKET_H
#define _SUPER_MARKET_H
#include "customer.h"
#include "product.h"
#include "address.h"

typedef struct
{
	char* name;
	Address address;
	Customer** customerArr;
	int numOfCustomers;
	Product** productArr;
	int numOfProducts;

} SuperMarket;

void initSuperMarket(SuperMarket* pSuperMarket);
void printSuperMarket(SuperMarket* pSuperMarket);
void printAllCustomers(SuperMarket* pSuperMarket);
void printAllProducts(SuperMarket* pSuperMarket);
void getSuperMarketName(SuperMarket* pSuperMarket);

void getAddress(SuperMarket* pSuperMarket);

int isBarcodeTaken(char* temp,const SuperMarket* pSuperMarket);
int addProduct(SuperMarket* pSuperMarket);
int addCustomer(SuperMarket* pSuperMarket);
int shop(SuperMarket* pSuperMarket);
void printProductsByType(SuperMarket* pSuperMarket);
void freeSuperMarket(SuperMarket* pSuperMarket);// free customer and product and name
void askUserToAddProduct(SuperMarket* pSuperMarket);
void askUserToAddCustomer(SuperMarket* pSuperMarket);
int checkIfCustomerExist(char* reqCustomer,SuperMarket* pSuperMarket);
Product* getProductByBarcode(char* reqBarcode,SuperMarket* pSuperMarket);
#endif
