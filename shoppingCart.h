#ifndef _SHOPPING_CART_H
#define _SHOPPING_CART_H
#include "shoppingItem.h"

typedef struct
{
	ShoppingItem** ItemArr;
	int difItemsInCart;

} ShoppingCart;

void initShoppingCart(ShoppingCart* pShoppingCart);
int printShoppingCart(const ShoppingCart* pShoppingCart);
void freeShoppingCart(ShoppingCart* pShoppingCart);
float totalPrice(const ShoppingCart* pShoppingCart);
int addItemToCart(ShoppingCart* pShoppingCart,Product* p);
#endif

