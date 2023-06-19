#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Buyer.h"
#include "Address.h"
#include "O_shop.h"
#include "Person.h"

Buyer::Buyer(const Person& f_Person) : Person(f_Person)
{
	shoppingCart = new Product * [0];
}

void Buyer::printBuyerAndAddress() const
{
	cout << *this;
}
                                                   
bool Buyer::addShoppingCart(Seller* seller, int selectSeller ,int MainproductLocation)
{
		int priceOfProducts;
		int serialNumber;
		Category category;
		int m_category;
		char* NameOfProduct;

		NameOfProduct = new char[strlen(seller->getNameOfProductSelected(MainproductLocation) + 1)];
		strcpy(NameOfProduct, seller->getNameOfProductSelected(MainproductLocation));
		priceOfProducts = seller->getPriceOfProductSelected(MainproductLocation);
		category = seller->getCategorySelected(MainproductLocation);
		m_category = int(category);
		serialNumber = seller->getSerialNumberOfProductSelected(MainproductLocation);


		sumPriceOfProducts = sumPriceOfProducts + priceOfProducts;
		numberOfItemsInCart = numberOfItemsInCart + 1;

		if (numberOfItemsInCart == logicalNumberProduct)
		{ 
		    logicalNumberProduct *= 2;
			Product** ProductCopy = new Product * [logicalNumberProduct];

			for (int i = 0; i < numberOfItemsInCart - 1; i++)
			{
				ProductCopy[i] = shoppingCart[i];
			}
			delete[] shoppingCart;
			shoppingCart = ProductCopy;
        }

		shoppingCart[numberOfItemsInCart - 1]= new Product(NameOfProduct, priceOfProducts, m_category, serialNumber, selectSeller);
		cout << "Product added" << endl;
		cout << shoppingCart[numberOfItemsInCart - 1];

		return true;
}

void Buyer::printAllShoppingCartAndPrice() const
{
	for (int i = 0; i < numberOfItemsInCart; i++)
	{
		cout << shoppingCart[i];
	}

	cout << "Total Price: " << sumPriceOfProducts << "$" << endl;
}

bool Buyer::removeProductFromShoppingCart()
{
	cout << "Products bought:" << endl;
	printAllShoppingCartAndPrice();

	for (int i=0; i < numberOfItemsInCart; i++)
	{
		delete shoppingCart[i];
			
	}

	numberOfItemsInCart = 0;
	sumPriceOfProducts = 0;
	return true;
}

int Buyer::getNumOfProducts() const
{
	return numberOfItemsInCart;
}

bool Buyer::operator>(Buyer* buyer) const
{
	if (sumPriceOfProducts > buyer->sumPriceOfProducts)
		return true;
	else
		return false;
}
