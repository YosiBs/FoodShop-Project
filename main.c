#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "address.h"
#include "product.h"




int main()
{
	//Product p;
	//initProduct(&p);
	//printProduct(&p);
	
	
	SuperMarket sm;
	initSuperMarket(&sm);

	
	
	//	addProduct(&sm);
//	addProduct(&sm);
	//printProductsByType(&sm);
	//addCustomer(&sm);
	printSuperMarket(&sm);
	
	

	//freeSuperMarket(&sm);
	chooseProgram(&sm);
	printf("@@@@@@END@@@@@@");


	
	
	
	return 0;
}

void chooseProgram(SuperMarket* pSuperMarket)
{
	int choose=0;
	while (choose != 8)
	{
		printf("Please choose one of the following options:\n\n--1-- Print SuperMarket Details\n--2-- Add Product to SuperMarket\n--3-- Add Customer to SuperMarket\n--4-- Start a customer shopping\n--5-- Print a Customer Shopping Cart\n--6-- Customer Payment\n--7-- Print all Products By Type\n\n");
		
		scanf("%d", &choose);
		
		switch (choose) 
		{
		
		case 1:
			printSuperMarket(pSuperMarket);
			break;
		
		case 2:
			askUserToAddProduct(pSuperMarket);
			break;
		
		case 3:
			askUserToAddCustomer(pSuperMarket);
			break;
		case 4:
			shop(pSuperMarket);
			break;
		case 5:
			printCustomerShoppingCart(pSuperMarket);
			break;
		case 6:
			printf("You Chose %d\n", choose);
			break;
		case 7:
			printProductsByType(pSuperMarket);
			break;
		case 8:
			printf("You Chose %d\n", choose);
			break;
		default:
			printf("Out of range\n\n");
			break;
		}
	}
}
