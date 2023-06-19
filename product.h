#ifndef _PRODUCT_H
#define _PRODUCT_H

enum class Category { Kids, Electronics, Office, Clothing };
static const char* n_category[4] = { "Kids", "Electronics", "Office", "Clothing" };

class Product
{
	private:
		char* m_nameOfProduct;
		int m_priceOfProduct;
		int m_serialNumber;
		int m_ownerNumber;
		Category type;

	public:
		Product(const char* nameOfProduct, const int priceOfProduct, const int category, const int serialNumber, const int ownerNumber);
		Product() = default;

		char* getNameOfProduct() const;
		int getPriceOfProduct() const;
		Category getCategory() const;
		int getSerialNumber() const;
		int getOwnerNumber() const;

		friend ostream& operator<<(ostream& os, Product *p)
		{
			os << "Category: " << n_category[int(p->type)] << "\nName: " << p->m_nameOfProduct << "\nSerial Number: " << p->m_serialNumber << endl;
			os << "Price: " << p->m_priceOfProduct << "$" << "\nSeller ID: " << p->m_ownerNumber << "\n" << endl;
			return os;
		}
};

#endif 
