#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "shoppingItem.h"
#include "product.h"

void initShoppingItem(ShoppingItem* pShoppingItem,Product* p)
{
	strcpy(pShoppingItem->barcode,p->barcode);
	pShoppingItem->price = p->price;
	pShoppingItem->itemAmount= getItemAmount(p);//how much of that item is in the shopping cart
}

void printShoppingItem()
{


}

int getItemAmount(Product* p)
{
	int amount;
	do
	{
		printf("How Many of that Item would You like?(1-%d): ",p->unitsInStock);
		scanf("%d",&amount);
	} while ((amount <= 0) || (amount > p->unitsInStock) || isspace(&amount));
	p->unitsInStock -= amount;
	return amount;
}
