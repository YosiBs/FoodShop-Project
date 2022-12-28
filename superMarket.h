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
void printSuperMarket(const SuperMarket* pSuperMarket);
int printAllCustomers(const SuperMarket* pSuperMarket);
void printAllProducts(const SuperMarket* pSuperMarket);
void getSuperMarketName(SuperMarket* pSuperMarket);
void getAddress(SuperMarket* pSuperMarket);
int isBarcodeTaken(const char* temp,const SuperMarket* pSuperMarket);
int addProduct(SuperMarket* pSuperMarket);
int addCustomer(SuperMarket* pSuperMarket);
int shop(SuperMarket* pSuperMarket);
void printProductsByType(const SuperMarket* pSuperMarket);
int freeSuperMarket(SuperMarket* pSuperMarket);
void askUserToAddProduct(SuperMarket* pSuperMarket);
void askUserToAddCustomer(SuperMarket* pSuperMarket);
Product* getProductByBarcode(const char* reqBarcode, const SuperMarket* pSuperMarket);
int isCustomerExist(const char* temp, const SuperMarket* pSuperMarket);
int updateStock(SuperMarket* pSuperMarket, const int index);
int printCustomerShoppingCart(const SuperMarket* pSuperMarket);
int paymentProcess(SuperMarket* pSuperMarket);
int exitProgram(SuperMarket* pSuperMarket);
#endif
