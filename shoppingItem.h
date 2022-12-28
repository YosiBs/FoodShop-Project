#ifndef _SHOPPING_ITEM_H
#define _SHOPPING_ITEM_H
#include "product.h"

typedef struct
{
	char barcode[BARCODE_LEN+1];
	float price;
	int itemAmount;
} ShoppingItem;

void initShoppingItem(ShoppingItem* pShoppingItem, Product* p);
void printShoppingItem(const ShoppingItem* pShoppingItem);
int getItemAmount(Product* p);
int updateItemAmount(ShoppingItem* pShoppingItem, Product* p);
int freeShoppingItem(ShoppingItem* pShoppingItem);
#endif


