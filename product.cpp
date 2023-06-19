#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Product.h"

Product::Product(const char* nameOfProduct, const int priceOfProduct, const int category, const int serialNumber, const int ownerNumber)
{
	m_nameOfProduct = new char[strlen(nameOfProduct) + 1];
	strcpy(m_nameOfProduct, nameOfProduct);

	m_ownerNumber = ownerNumber;

	switch (category)
	{
	case 1:
		type = Category::Kids;
		break;
	case 2:
		type = Category::Electronics;
		break;
	case 3:
		type = Category::Office;
		break;
	case 4:
		type = Category::Clothing;
		break;
	}

	m_priceOfProduct = priceOfProduct;
	m_serialNumber = serialNumber;
}

char* Product::getNameOfProduct() const
{
	return m_nameOfProduct;
}

Category Product::getCategory() const
{
	return type;
}

int Product::getPriceOfProduct() const
{
	return m_priceOfProduct;
}

int Product::getSerialNumber() const
{
	return m_serialNumber;
}

int Product::getOwnerNumber() const
{
	return m_ownerNumber;
}
