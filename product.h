#ifndef _PRODUCT_H
#define _PRODUCT_H
#define NAME_LEN 20
#define BARCODE_LEN 7
#define MAX_STR_LEN 255


typedef enum {eShelf,eFrozen,eFridge,eFruitVegtable, NofTypes } ProductType;
const char* typeTitle[NofTypes];

typedef struct
{
	char name[NAME_LEN];
	char barcode[BARCODE_LEN+1];
	ProductType Type;
	float price;
	int unitsInStock;

} Product;

void initProduct(Product* pProduct);
void printProduct(Product* pProduct);
void getProductName(char* name);
void getProductBarcode(char* code);
ProductType getProductType();
float getProductPrice();
int getUnitsInStock();
int isValid(char* check);

void freeProduct(Product* pProduct);
#endif