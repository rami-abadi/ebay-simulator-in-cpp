#ifndef __BUYER_H
#define __BUYER_H

#include "Person.h"
#include "Product.h"
#include "Seller.h"

class Buyer:Person
{
	private:
		Product** shoppingCart;
		int numberOfItemsInCart = 0;
		int sumPriceOfProducts = 0;
		int logicalNumberProduct = 1;

	public:
		Buyer() = default;
		Buyer(const Person & f_Person);

		bool addShoppingCart(Seller* seller, int selectSeller, int MainproductLocation);
		void printBuyerAndAddress() const;
		void printAllShoppingCartAndPrice() const;
		bool removeProductFromShoppingCart();
		int getNumOfProducts() const;
		bool operator>(Buyer* buyer) const;
};

#endif
