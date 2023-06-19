#ifndef __SELLER_H
#define __SELLER_H

#include "Person.h"
#include "Product.h"

class Seller:Person
{
	private:
		int logicalNumberProduct = 1;
		int numOfProducts = 0;
		Product** allProduct;
	
	public:
		Seller(const Person& f_Person);

		bool addProduct(Product* p_temp);
		void printSellerAndAddress() const;
		char* getNameOfProductSelected(int selectSeller) const;
		int getPriceOfProductSelected(int selectSeller) const;
		int getSerialNumberOfProductSelected(int selectSeller) const;
		Category getCategorySelected(int selectSeller) const;
		int getNumOfProducts() const;


};

#endif
