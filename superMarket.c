#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include "superMarket.h"
#include "functions.h"
#include "address.h"
#include "shoppingCart.h"

void initSuperMarket(SuperMarket* pSuperMarket)
{
	getSuperMarketName(pSuperMarket);
	pSuperMarket->customerArr = NULL;
	pSuperMarket->numOfCustomers = 0;
	pSuperMarket->productArr = NULL;
	pSuperMarket->numOfProducts = 0;
	getAddress(pSuperMarket);


}

void printSuperMarket(SuperMarket* pSuperMarket)
{
	printf("\nSuperMarket: %s\n", pSuperMarket->name);
	printf("\t~~Address~~ \n");
	printAddress(&pSuperMarket->address);
	printf("\n\t~~Customer List~~ \n");
	printAllCustomers(pSuperMarket);//print Customers
	printf("\nNumber of Customers: %d\n", pSuperMarket->numOfCustomers);
	printf("\n\t~~Product List~~ \n");
	printAllProducts(pSuperMarket);//print Products
	printf("\nNumber of Products: %d\n", pSuperMarket->numOfProducts);
}

void printAllCustomers(SuperMarket* pSuperMarket)
{
	int i;
	for (i = 0; i < pSuperMarket->numOfCustomers; i++)
	{
		printCustomer(pSuperMarket->customerArr[i]);

	}

}

void printAllProducts(SuperMarket* pSuperMarket)
{
	int i;
	char a1[20]="~Product Name~", a2[20] ="~Barcode~", a3[20] ="~Type~", a4[20] ="~Price~", a5[20] ="~Units in Stock~";
	printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t\n",a1,a2,a3,a4,a5);
	for (i = 0; i < pSuperMarket->numOfProducts; i++)
	{
		printProduct(pSuperMarket->productArr[i]);

	}
	
}

void getSuperMarketName(SuperMarket* pSuperMarket)
{
	pSuperMarket ->name= getStrExactName("Enter SuperMarket Name:");
}

void getAddress(SuperMarket* pSuperMarket)//????
{
	initAddress(&pSuperMarket->address);
	
}

int addProduct(SuperMarket* pSuperMarket)
{

	
	Product* pTemp= (Product*)calloc(1, sizeof(Product));
	
	if (!pTemp)
	{
		return 0;
	}
	initProduct(pTemp);
	if (isBarcodeTaken(pTemp->barcode, pSuperMarket))
	{
		printf("Product already has a barcode like this\n");
		free(pTemp);
		return;
	}
	

	pSuperMarket->productArr = (Product**)realloc(pSuperMarket->productArr,(pSuperMarket->numOfProducts+1) * sizeof(Product*));
	if (!pSuperMarket)
	{
		return 0;
	}
	pSuperMarket->productArr[pSuperMarket->numOfProducts] = pTemp;
	if (!pSuperMarket->productArr[pSuperMarket->numOfProducts])
	{
		return 0;
	}
	//initProduct(pSuperMarket->productArr[pSuperMarket->numOfProducts]);
	//check if product exist
	pSuperMarket->numOfProducts++;
	return 1;

	
}

int addCustomer(SuperMarket* pSuperMarket)
{
	pSuperMarket->customerArr = (Customer**)realloc(pSuperMarket->customerArr, (pSuperMarket->numOfCustomers + 1) * sizeof(Customer*));
	if (!pSuperMarket)
	{
		return 0;
	}
	pSuperMarket->customerArr[pSuperMarket->numOfCustomers] = (Customer*)calloc(1, sizeof(Customer));
	if (!pSuperMarket->customerArr[pSuperMarket->numOfCustomers])
	{
		return 0;
	}
	initCustomer(pSuperMarket->customerArr[pSuperMarket->numOfCustomers]);
	pSuperMarket->numOfCustomers++;
	return 1;
	
}

int shop(SuperMarket* pSuperMarket)
{
	if (pSuperMarket->numOfProducts == 0)
	{
		printf("There is No Products in The SuperMarket for you to Shop..\n");
		return 0;
	}
	int e;//customer index if he exist
	char op;
	char* reqCustomer,*reqBarcode;
	printf("\t~~~~Start Shopping~~~~~\n");
	do 
	{
		//printf("Enter Customer Name: \n");
		reqCustomer = getStrExactName("Enter Customer Name: \n");
		e= checkIfCustomerExist(reqCustomer, pSuperMarket);//Not Working
		if (e==-1)
		{
			printf("Customer Doesn't Exist, try again \n");
		}
	} while (e==-1);
	printAllProducts(pSuperMarket);
	do
	{
		printf("Would You like to Continue Shopping?\ny/Y (Yes)\nAnything else (No)\n");
		do
		{
			scanf("%c", &op);

		} while (isspace(op));
		if (op != 'y' && op != 'Y')
		{
			return 0;
		}
		else {
			//printf("Please Enter the Barcode of the Product you want to purchase:\n");
			reqBarcode = getStrExactName("Please Enter the Barcode of the Product you want to purchase:\n");
			Product* reqP=getProductByBarcode(reqBarcode,pSuperMarket);
			addItemToCart(pSuperMarket->customerArr[e]->Cart,reqP);
		}
	} while (op == 'y' || op == 'Y');
	printf("Done Shopping...");
	return 0;
}

void printProductsByType(SuperMarket* pSuperMarket)
{
	int i, requestedType;
	printf("\nYou Chose to see all products by Type.");
	requestedType = getProductType();
	char a1[20] = "~Product Name~", a2[20] = "~Barcode~", a3[20] = "~Type~", a4[20] = "~Price~", a5[20] = "~Units in Stock~";
	printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t\n", a1, a2, a3, a4, a5);
	for (i = 0; i < pSuperMarket->numOfProducts; i++)
	{
		if (pSuperMarket->productArr[i]->Type == requestedType)
		{
			printProduct(pSuperMarket->productArr[i]);
		}

	}
}
int isBarcodeTaken(char* temp ,const SuperMarket* pSuperMarket)
{
	int i;
	for (i=0;i<pSuperMarket->numOfProducts;i++)
	{
		if (strcmp(pSuperMarket->productArr[i]->barcode ,temp) == 0 )
		{
			return 1;
		}

	}
	return 0;

}

void freeSuperMarket(SuperMarket* pSuperMarket)
{
	int i;
	for (i = 0; i < pSuperMarket->numOfProducts; i++)// free all products
	{
		freeProduct(pSuperMarket->productArr[i]);
	}
	for (i = 0; i < pSuperMarket->numOfCustomers; i++)// free all customers
	{
		freeCustomer(pSuperMarket->customerArr[i]);
	}
	freeAddress(&pSuperMarket->address);
	free(pSuperMarket);// free super market
}

void askUserToAddProduct(SuperMarket* pSuperMarket)
{
	char op = ' ';
	do
	{
		printf("Would you like to add a Product to the SuperMarket?\ny/Y (Yes)\nAnything else (No)\n");
		do
		{
			scanf("%c", &op);

		} while (isspace(op));
		if (op != 'y' && op != 'Y')
		{
			return;
		}
		else {
			addProduct(pSuperMarket);
		}
	} while (op == 'y' || op == 'Y');
}
void askUserToAddCustomer(SuperMarket* pSuperMarket)
{
	char op = ' ';
	printf("Would you like to add a Customer to the SuperMarket?\ny/Y (Yes)\nAnything else (No)\n");
	do
	{
		scanf("%c", &op);

	} while (isspace(op));
	if (op != 'y' && op != 'Y')
	{
		return;
	}
	else {
		addCustomer(pSuperMarket);
	}
}

int checkIfCustomerExist(char* reqCustomer,SuperMarket* pSuperMarket)
{
	int i;
	for (i=0 ;i< pSuperMarket->numOfCustomers;i++)
	{
		if (strcmp(pSuperMarket->customerArr[i]->name , reqCustomer))
			return i;
	}
	return -1;
}
Product* getProductByBarcode(char* reqBarcode, SuperMarket* pSuperMarket)
{
	int i;
	for (i = 0; i < pSuperMarket->numOfProducts; i++)
	{
		if (pSuperMarket->productArr[i]->barcode == reqBarcode)
			return pSuperMarket->productArr[i];
	}
	return NULL;
	
}





