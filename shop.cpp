#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Buyer.h"
#include "Seller.h"
#include "O_shop.h"
                  
bool O_shop::operator+=(Seller* b_temp)
{
	numberOfSellers++;

	if (numberOfSellers == logicalNumberSeller)
	{
		logicalNumberSeller *= 2;
		Seller** allSellersCopy = new Seller * [logicalNumberSeller];
		

		for (int i = 0; i < numberOfSellers - 1; i++)
		{
			allSellersCopy[i] = allSellers[i];
		}

		delete[]allSellers;
		allSellers = allSellersCopy;
	}
	allSellers[numberOfSellers - 1] = b_temp;

	return true;
}
bool O_shop::setNumberOfSellers()
{
	numberOfSellers = 0;
	return true;
}

int O_shop::getNumberOfSellers() const
{
	return numberOfSellers;
}

void O_shop::printAllSellers() const
{
	cout << "Sellers List:" << endl;
	cout << "------" << endl;

	for (int i = 0; i < numberOfSellers; i++)
	{
		allSellers[i]->printSellerAndAddress();
	}
}

bool O_shop::setProductToSeller(Product* p_temp)
{
	numberOfProducts++;

	if (numberOfProducts == logicalNumberProduct)
	{
		logicalNumberProduct *= 2;
		Product** allProductsCopy = new Product * [logicalNumberProduct];

		for (int i = 0; i < numberOfProducts - 1; i++)
		{
			allProductsCopy[i] = allProducts[i];
		}

		delete[]allProducts;
		allProducts = allProductsCopy;
	}
	allProducts[numberOfProducts - 1] = p_temp;
	allSellers[p_temp->getOwnerNumber() - 1] -> addProduct(p_temp);

	return true;
}


bool O_shop::operator+=(Buyer* b_temp)
{
	numberOfBuyers++;

	if (numberOfBuyers == logicalNumberBuyer)
	{
		logicalNumberBuyer *= 2;
	    Buyer** allBuyersCopy = new Buyer * [logicalNumberBuyer];

		for (int i = 0; i < numberOfBuyers - 1; i++)
		{
			allBuyersCopy[i] = allBuyers[i];
		}

		delete[]allBuyers;
		allBuyers = allBuyersCopy;
    }

	allBuyers[numberOfBuyers - 1] = b_temp;

	return true;
}

int O_shop::getNumberOfBuyers() const
{
	return numberOfBuyers;
}

bool O_shop::setNumberOfBuyers()
{
	numberOfBuyers = 0;
	return true;
}

void O_shop::printAllBuyers() const
{
	cout << "Buyers List:" << endl;
	cout << "------" << endl;

	for (int i = 0; i < numberOfBuyers;i++)
	{
		allBuyers[i]->printBuyerAndAddress();
	}
}

void O_shop::freeMemory()
{
	for (int i = 0; i < numberOfBuyers-2; i++)
		delete allBuyers[i];

	delete[]allBuyers;
}

bool O_shop::setProductToBuyerShoppingCart(int selectBuyer,int selectSeller,int MainproductLocation)
{
	allBuyers[selectBuyer - 1]->addShoppingCart(allSellers[selectSeller-1], selectSeller, MainproductLocation);
	return true;
}

int O_shop::getSellersNumOfProduct(int sellerPlace) const
{
	return allSellers[sellerPlace-1]->getNumOfProducts();
}

bool O_shop::removeProductFromBuyerCart(int selectBuyer)
{
	return allBuyers[selectBuyer-1]->removeProductFromShoppingCart();
}

int O_shop::getBuyersNumOfProduct(int buyerPlace) const
{
	return allBuyers[buyerPlace - 1]->getNumOfProducts();
}

int O_shop::getNumberOfProducts() const
{
	return numberOfProducts;
}

Product** O_shop::getAllProducts() const
{
	return allProducts;
}

bool O_shop::comparePrice(const int i, const int j) const
{
	return *allBuyers[i-1] > allBuyers[j-1];
}
