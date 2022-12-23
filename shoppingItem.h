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
void printShoppingItem();
int getItemAmount(Product* p);

#endif


