#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "shoppingItem.h"
#include "product.h"
#include "shoppingCart.h"

void initShoppingItem(ShoppingItem* pShoppingItem,Product* p)
{
	strcpy(pShoppingItem->barcode,p->barcode);
	pShoppingItem->price = p->price;
	pShoppingItem->itemAmount += updateItemAmount(pShoppingItem,p);//PROBLEM, item Overriding the last value...
	
}

void printShoppingItem(const ShoppingItem* pShoppingItem)
{
	printf("Barcode: %s\t Price per item: %.2f\t item Amount: %d\n", pShoppingItem->barcode, pShoppingItem->price, pShoppingItem->itemAmount);

}

int getItemAmount(Product* p)
{
	int amount=0;
	do
	{
		printf("How Many of that Item would You like?(1-%d): ",p->unitsInStock);

		scanf("%d",&amount);
	} while (amount <= 0 || amount > p->unitsInStock );
	p->unitsInStock -= amount;
	return amount;
}
int updateItemAmount(ShoppingItem* pShoppingItem, Product* p)
{
	return getItemAmount(p);
}

int freeShoppingItem(ShoppingItem * pShoppingItem)
{
	free(pShoppingItem);
	return 1;
}
