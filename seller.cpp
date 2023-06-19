#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Seller.h"
#include "Address.h"
#include "O_shop.h"
#include "Person.h"

Seller::Seller(const Person& f_Person) : Person(f_Person)
{
	allProduct = new Product * [0];
}

void Seller::printSellerAndAddress() const
{
	cout << *this;
}

bool Seller::addProduct(Product* p_temp)
{
	numOfProducts = numOfProducts + 1;

	if (numOfProducts == logicalNumberProduct)
	{ 
		logicalNumberProduct *= 2;
		Product** ProductCopy = new Product * [logicalNumberProduct];

		for (int i = 0; i < numOfProducts - 1; i++)
		{
			ProductCopy[i] = allProduct[i];
		}
		delete[] allProduct;
		allProduct = ProductCopy;
    }
		allProduct[numOfProducts - 1] = p_temp;
		cout << "Product added" << endl;
		cout << allProduct[numOfProducts - 1];

		return true;	
}

char* Seller::getNameOfProductSelected(int MainproductLocation) const
{
	return allProduct[MainproductLocation - 1]->getNameOfProduct();
}

int Seller::getPriceOfProductSelected(int MainproductLocation) const
{
	return allProduct[MainproductLocation - 1]->getPriceOfProduct();
}

Category Seller::getCategorySelected(int MainproductLocation) const
{
	return allProduct[MainproductLocation - 1]->getCategory();
}

int Seller::getSerialNumberOfProductSelected(int MainproductLocation) const
{
	return allProduct[MainproductLocation - 1]->getSerialNumber();
}

int Seller::getNumOfProducts() const
{
	return numOfProducts;
}
