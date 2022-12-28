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

void printShoppingCart(ShoppingCart* pShoppingCart)
{
	int i;
	for (i=0 ; i < pShoppingCart->difItemsInCart ; i++)
	{
		printShoppingItem(pShoppingCart->ItemArr[i]);
	}
}

void freeShoppingCart(ShoppingCart* pShoppingCart)
{
}

float totalPrice(ShoppingCart* pShoppingCart)
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


