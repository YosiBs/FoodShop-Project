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
	printf("\n@@---------------------SuperMarket Details---------------------@@\n");
	printf("\nSuperMarket: %s\n", pSuperMarket->name);
	printf("\t~~Address~~ \n");
	printAddress(&pSuperMarket->address);
	printf("\n\t~~Customer List~~ \n");
	printAllCustomers(pSuperMarket);//print Customers
	printf("\nNumber of Customers: %d\n", pSuperMarket->numOfCustomers);
	printf("\n\t~~Product List~~\n");
	printAllProducts(pSuperMarket);//print Products
	printf("\nNumber of Products: %d\n", pSuperMarket->numOfProducts);
}

void printAllCustomers(SuperMarket* pSuperMarket)
{
	int i;
	if (pSuperMarket->numOfCustomers != 0)
	{
		for (i = 0; i < pSuperMarket->numOfCustomers; i++)
		{
			printCustomer(&pSuperMarket->customerArr[i]);
		}
	}
	else {
		printf("~~There is no Customers Yet...\n");
	}
}

void printAllProducts(SuperMarket* pSuperMarket)
{
	int i;
	char a1[20]="~Product Name~", a2[20] ="~Barcode~", a3[20] ="~Type~", a4[20] ="~Price~", a5[20] ="~Units in Stock~";
	if (pSuperMarket->numOfProducts != 0)
	{
		printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t\n",a1,a2,a3,a4,a5);
		for (i = 0; i < pSuperMarket->numOfProducts; i++)
		{
			printProduct(pSuperMarket->productArr[i]);
		}
	}
	else {
		printf("~~There is no Products Yet...\n");
	}
}

void getSuperMarketName(SuperMarket* pSuperMarket)
{
	pSuperMarket ->name= getStrExactName("Enter SuperMarket Name:");
}

void getAddress(SuperMarket* pSuperMarket)
{
	initAddress(&pSuperMarket->address);
	
}

int addProduct(SuperMarket* pSuperMarket)
{
	int index;
	Product* pTemp= (Product*)calloc(1, sizeof(Product));
	if (!pTemp)
	{
		return 0;
	}
	initProduct(pTemp);
	if (index=isBarcodeTaken(pTemp->barcode, pSuperMarket))
	{
		index--;
		printf("~~Product already has a barcode like this!!\n");
		updateStock(pSuperMarket,index);
		free(pTemp);
		return 0;
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
	pSuperMarket->numOfProducts++;
	return 1;	
}
int addCustomer(SuperMarket* pSuperMarket)
{
	int index;
	Customer* pTemp = (Customer*)calloc(1, sizeof(Customer));
	if (!pTemp)
	{
		return 0;
	}
	initCustomer(pTemp);
	if (index = isCustomerExist(pTemp->name, pSuperMarket))
	{
		index--;
		printf("~~Customer already exist!!-a new Customer HASN'T created.\n");
		free(pTemp);
		return 0;
	}

	pSuperMarket->customerArr = (Customer*)realloc(pSuperMarket->customerArr, (pSuperMarket->numOfCustomers + 1) * sizeof(Customer));
	if (!pSuperMarket->customerArr)
	{
		return 0;
	}
	pSuperMarket->customerArr[pSuperMarket->numOfCustomers] = *pTemp;
	pSuperMarket->numOfCustomers++;
	return 1;
	
	
	
}

int shop(SuperMarket* pSuperMarket)
{
	if (pSuperMarket->numOfProducts == 0)
	{
		printf("~~There is No Products in The SuperMarket for you to Shop..\n");
		return 0;
	}
	if (pSuperMarket->numOfCustomers==0)
	{
		printf("~~There is No Products in The SuperMarket for you to Shop..\n");
		return 0;
	}
	int e;//customer index in CustomerArr
	char op;
	char* reqCustomer,*reqBarcode;
	printf("---------------------START SHOPPING---------------------\n");
	
	reqCustomer = getStrExactName("Enter Customer Name: \n");
	e = isCustomerExist(reqCustomer, pSuperMarket);//Not Working
	if (e==0)
	{
		printf("~~Customer Doesn't Exist!!\n");
		return 0;
	}
	e-=1;
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
			
			reqBarcode = getStrExactName("Please Enter the Barcode of the Product you want to purchase:\n");
			Product* reqP=getProductByBarcode(reqBarcode,pSuperMarket);
			if (reqP==NULL)
			{
				printf("~~Product Doesn't Exist\n");
				return 0;
			}

			initShoppingCart(pSuperMarket->customerArr[e].Cart);
			addItemToCart(pSuperMarket->customerArr[e].Cart,reqP);
			
			return 1;
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
			return i+1;
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
		freeCustomer(&pSuperMarket->customerArr[i]);
	}
	freeAddress(&pSuperMarket->address);
	free(pSuperMarket);// free super market
}

void askUserToAddProduct(SuperMarket* pSuperMarket)
{
	char op = ' ';
	printf("---------------------ADD PRODUCT---------------------\n");
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
	
	printf("---------------------ADD CUSTOMER---------------------\n");
	
		addCustomer(pSuperMarket);
	
}

Product* getProductByBarcode(char* reqBarcode, SuperMarket* pSuperMarket)
{
	int i;
	//int size = strlen(reqBarcode)+1;
	//char* fixedBarcode=myGets(reqBarcode, size);
	for (i = 0; i < pSuperMarket->numOfProducts; i++)
	{
		if (strcmp(pSuperMarket->productArr[i]->barcode, reqBarcode)==0)// problem
		{
			return pSuperMarket->productArr[i];
		}
			
	}
	
	return NULL;
	
}
int updateStock(SuperMarket* pSuperMarket, int productIndex)
{
	int newAmount;
	printf("Update Units in stock-\nOld Amount:%d\n", pSuperMarket->productArr[productIndex]->unitsInStock);
	do {
		printf("New Stock Must be bigger than [%d]\nEnter New Amount:\n", pSuperMarket->productArr[productIndex]->unitsInStock);
		scanf("%d", &newAmount);
	} while (newAmount<= pSuperMarket->productArr[productIndex]->unitsInStock);
	
	pSuperMarket->productArr[productIndex]->unitsInStock = newAmount;
	
	return 0;
}
int isCustomerExist(char* temp, const SuperMarket* pSuperMarket)
{
	int i;
	for (i = 0; i < pSuperMarket->numOfCustomers; i++)
	{
		if (strcmp((char*)pSuperMarket->customerArr[i].name, temp) == 0)
		{
			return i + 1;
		}

	}
	return 0;
}




