#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "shoppingCart.h"
#include "functions.h"

void initShoppingCart(ShoppingCart* pShoppingCart)
{
	pShoppingCart->ItemArr = NULL;
	pShoppingCart->difItemsInCart = 0;
}

void printShoppingCart(ShoppingCart* pShoppingCart)
{
}

void freeShoppingCart(ShoppingCart* pShoppingCart)
{
}

float totalPrice()
{
	return 0.0f;
}

int addItemToCart(ShoppingCart* pShoppingCart, Product* reqP)
{
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
	pShoppingCart->ItemArr[pShoppingCart->difItemsInCart] = (ShoppingItem*)calloc(1, sizeof(ShoppingItem));
	if (!pShoppingCart->ItemArr[pShoppingCart->difItemsInCart])
	{
		return 0;
	}
	initShoppingItem(pShoppingCart->ItemArr[pShoppingCart->difItemsInCart],reqP);
	pShoppingCart->difItemsInCart++;
	
	return 1;
}
