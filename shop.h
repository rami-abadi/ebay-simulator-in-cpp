#ifndef __O_SHOP_H
#define __O_SHOP_H

#include "Buyer.h"
#include "Seller.h"

class O_shop
{
	public:
		bool setNumberOfBuyers();
		int getNumberOfBuyers() const;
		bool operator+=(Buyer* b_temp);
		bool setNumberOfSellers();
		int getNumberOfSellers() const;
		bool operator+=(Seller* b_temp);
		void printAllBuyers() const;
		void printAllSellers() const;
		void freeMemory();
		bool setProductToSeller(Product* p_temp);
		bool setProductToBuyerShoppingCart(int selectBuyer, int selectSeller, int MainproductLocation);
		int getNumberOfProducts() const;
		Product** getAllProducts() const;
		int getSellersNumOfProduct(int sellerPlace) const;
		int getBuyersNumOfProduct(int buyerPlace) const;
		bool removeProductFromBuyerCart(int selectBuyer);
		bool comparePrice(const int i, const int j) const;

	private:
		int logicalNumberBuyer = 1;
		int numberOfBuyers = 0;
		int logicalNumberSeller = 1;
		int numberOfSellers = 0;
		int logicalNumberProduct = 1;
		int numberOfProducts = 0;

		Buyer** allBuyers = new Buyer * [0];
		Seller** allSellers = new Seller * [0];
		Product** allProducts = new Product * [0];


};

#endif
