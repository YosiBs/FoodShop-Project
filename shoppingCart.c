#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shoppingCart.h"
#include "functions.h"

void initShoppingCart(ShoppingCart* pShoppingCart)
{
	if (pShoppingCart->ItemArr != NULL)
	{
		return;
	}
	else {
		pShoppingCart->ItemArr = NULL;
		pShoppingCart->difItemsInCart = 0;
	}
	
}

int printShoppingCart(const ShoppingCart* pShoppingCart)
{
	int i;
	if (pShoppingCart->difItemsInCart == 0)
	{
		printf("Customer Cart is Empty..\n");
		return 0;
	}
	for (i=0 ; i < pShoppingCart->difItemsInCart ; i++)
	{
		printShoppingItem(pShoppingCart->ItemArr[i]);
	}
	return 1;
}

void freeShoppingCart(ShoppingCart* pShoppingCart)
{
	int i;
	if (pShoppingCart->difItemsInCart > 0)
	{
		for (i=0 ; i < pShoppingCart->difItemsInCart ; i++)
		{
			freeShoppingItem(pShoppingCart->ItemArr[i]);
		}
		printf("SYSTEM: Freed Customer's Cart..\n");
	}
	pShoppingCart->ItemArr = NULL;
	pShoppingCart->difItemsInCart = 0;
	

}

float totalPrice(const ShoppingCart* pShoppingCart)
{
	float sum = 0;
	int i;
	for (i = 0; i < pShoppingCart->difItemsInCart ; i++) 
	{
		sum += (pShoppingCart->ItemArr[i]->price*pShoppingCart->ItemArr[i]->itemAmount);
			
	}
	printf("Total Payment: %.2f\n",sum);
	return sum;
}

int addItemToCart(ShoppingCart* pShoppingCart, Product* reqP)
{
	int i;
	if (pShoppingCart->difItemsInCart > 0)
	{
		for (i = 0; i < pShoppingCart->difItemsInCart; i++)
		{
			if (strcmp(pShoppingCart->ItemArr[i]->barcode,reqP->barcode)==0)
			{
				pShoppingCart->ItemArr[i]->itemAmount += updateItemAmount(pShoppingCart->ItemArr[i], reqP);
				return 1;
			}
			
		}
	}
	
		ShoppingItem* pTemp= (ShoppingItem*)calloc(1, sizeof(ShoppingItem));
		if (!pTemp)
		{
			return 0;
		}
		initShoppingItem(pTemp, reqP);
	
		pShoppingCart->ItemArr = (ShoppingItem**)realloc(pShoppingCart->ItemArr, (pShoppingCart->difItemsInCart + 1) * sizeof(ShoppingItem*));
		if (!pShoppingCart)
		{
			return 0;
		}
		pShoppingCart->ItemArr[pShoppingCart->difItemsInCart] = pTemp;
		pShoppingCart->difItemsInCart++;
		return 1;
	
	
}


