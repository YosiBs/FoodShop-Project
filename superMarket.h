#ifndef _SUPER_MARKET_H
#define _SUPER_MARKET_H
#include "customer.h"
#include "product.h"
#include "address.h"

typedef struct
{
	char* name;
	Address address;
	Customer* customerArr;
	int numOfCustomers;
	Product** productArr;
	int numOfProducts;

} SuperMarket;

void initSuperMarket(SuperMarket* pSuperMarket);
void printSuperMarket(SuperMarket* pSuperMarket);//CONST?
void printAllCustomers(SuperMarket* pSuperMarket);//CONST?
void printAllProducts(SuperMarket* pSuperMarket);//CONST?
void getSuperMarketName(SuperMarket* pSuperMarket);

void getAddress(SuperMarket* pSuperMarket);

int isBarcodeTaken(char* temp,const SuperMarket* pSuperMarket);//CONST?
int addProduct(SuperMarket* pSuperMarket);
int addCustomer(SuperMarket* pSuperMarket);
int shop(SuperMarket* pSuperMarket);
void printProductsByType(SuperMarket* pSuperMarket);//CONST?
void freeSuperMarket(SuperMarket* pSuperMarket);// free customer and product and name
void askUserToAddProduct(SuperMarket* pSuperMarket);
void askUserToAddCustomer(SuperMarket* pSuperMarket);

Product* getProductByBarcode(char* reqBarcode,SuperMarket* pSuperMarket);
int isCustomerExist(char* temp, const SuperMarket* pSuperMarket);//CONST?
int updateStock(SuperMarket* pSuperMarket, int index);
int printCustomerShoppingCart(SuperMarket* pSuperMarket);//CONST?

#endif
