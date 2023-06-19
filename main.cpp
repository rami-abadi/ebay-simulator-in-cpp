//rami abadi 
#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "O_shop.h"
#include "Buyer.h"
#include "Address.h"
#include "Person.h"

Person* add_person();
Seller* add_seller();
Buyer* add_buyer();
int selectSeller(int sumOfSellers);
int selectBuyer(int sumOfBuyers);
Product* insertProduct(O_shop* o_shop);
int productLocation();

int main()
{
	O_shop o_shop;
	bool exit = false;
	int numOfBuyers, numOfSellers, seller_number, buyer_number, product_Location, buyer_first, buyer_second;
	cout << "~~ONLINE SHOP~~" << endl;
	
	while (!exit)
	{
		cout << "\n------" << endl;
		cout << "~Shop Menu~" << endl;
		cout << "1. Add new Buyer" << endl;
		cout << "2. Add new Seller" << endl;
		cout << "3. Add Product to Seller" << endl;
		cout << "4. Compare Buyers Shopping Carts" << endl;
		cout << "5. Add Product to Buyer's Shopping Cart" << endl;
		cout << "6. Pay for Shopping Cart" << endl;
		cout << "7. Show Buyers Info" << endl;
		cout << "8. Show Sellers Info" << endl;
		cout << "9. Exit" << endl;
		cout << "------" << endl;
		int choose;

		cout << "\nYour selection: ";
		cin >> choose;
		cout << endl;

		switch (choose)
		{
		case 1:
			if (o_shop+=add_buyer())
				cout << "-- Buyer added" << endl;
			else
				cout << "There was a problem. The action was not performed. Please try again.";

			break;

		case 2:
			if(o_shop+=add_seller())
				cout << "-- Seller added" << endl;
			else
				cout << "There was a problem. The action was not performed. Please try again.";

			break;

		case 3:
			if (o_shop.getNumberOfSellers() == 0)
			{
				cout << "0 Sellers available." << endl;
				break;
			}

			o_shop.setProductToSeller(insertProduct(&o_shop));
			cout << "\nProduct added successfully" << endl;

			break;

		case 4:
			if (o_shop.getNumberOfBuyers() < 2)
			{
				cout << "Not enough Buyers available" << endl;
				break;
			}

			buyer_first = selectBuyer(o_shop.getNumberOfBuyers());
			buyer_second = selectBuyer(o_shop.getNumberOfBuyers());

			if (o_shop.comparePrice(buyer_first, buyer_second))
				cout << "First buyer shopping cart is more expensive";
			else
				cout << "Second buyer shopping cart is more expensive";

			break;

		case 5:
			if (o_shop.getNumberOfBuyers() == 0)
			{
				cout << "0 Buyers available." << endl;
				break;
			}

			if (o_shop.getNumberOfSellers() == 0)
			{
				cout << "0 Sellers available means 0 products avaiable.\n";
				break;
			}
			seller_number = selectSeller(o_shop.getNumberOfSellers());

			if (o_shop.getSellersNumOfProduct(seller_number) == 0)
			{
				cout << "0 Products avaiable.\n";
				break;
			}

			product_Location = productLocation();

			while (product_Location > o_shop.getSellersNumOfProduct(seller_number))
			{
				cout << "There isn't any product to this seller in the location you choose. Please choose another place.\n";
				product_Location = productLocation();
			}

			o_shop.setProductToBuyerShoppingCart(selectBuyer(o_shop.getNumberOfBuyers()), seller_number, product_Location);
			cout << "\nProduct added successfully" << endl;

			break;

		case 6:
			if (o_shop.getNumberOfBuyers() == 0)
			{
				cout << "0 Buyers available.\n";
				break;
			}

			buyer_number = selectBuyer(o_shop.getNumberOfBuyers());
			
			if (o_shop.getBuyersNumOfProduct(buyer_number) == 0)
			{
				cout << "0 Products available.\n";
				break;
			}

			o_shop.removeProductFromBuyerCart(buyer_number);

			break;

		case 7:
			numOfBuyers = o_shop.getNumberOfBuyers();
			
			if (numOfBuyers==0)
			{
				cout << "0 Buyers available.\n";
				break;
			}

			cout << "Buyers count: "<< numOfBuyers <<endl;
			o_shop.printAllBuyers();
			
			break;

		case 8:
			numOfSellers = o_shop.getNumberOfSellers();
			if (numOfSellers==0)
			{
				cout << "0 Sellers available.\n";
				break;
			}

			cout << "Sellers count: " << numOfSellers << endl;
			o_shop.printAllSellers();

			break;

		case 9:
			exit = true;
			cout << "\n\tGoodbye!\n";
			break;

		default:
			cout << "Your choice is invalid, please try again." << endl;
			if (cin.fail()) 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

	}
	return 0;
}

Seller* add_seller()
{
	Person* person = add_person();
	Seller* seller = new Seller(*person);

	delete person;

	return seller;
}

int selectSeller(int sumOfSellers)
{
	int selectSeller;
	cout << "There are " << sumOfSellers << " sellers" << endl;
	cout << "Select Seller Number: ";
	cin >> selectSeller;
	cout << endl;

	while (selectSeller > sumOfSellers || selectSeller <= 0)
	{
		cout << "Your choice is invalid, please try again." << endl;
		cout << "Select Seller Number: ";
		cin >> selectSeller;
		cout << endl;
	}

	return selectSeller;
}

Person* add_person()
{
	char user_name[20] = "def", state_name[20] = "def", city_name[20] = "def", street_name[20] = "def";
	int password = 000;
	int building_number = 0;

	cout << "Please enter User Name: ";
	cin >> user_name;
	cout << "\nPlease enter Password (int): ";
	cin >> password;
	cout << "\nPlease enter State Name: ";
	cin >> state_name;
	cout << "\nPlease enter City Name: ";
	cin >> city_name;
	cout << "\nPlease enter Street Name: ";
	cin >> street_name;
	cout << "\nPlease enter Building Number: ";
	cin >> building_number;
	cout << endl;

	Address address(street_name, city_name, state_name, building_number);
	Person* person = new Person(address, user_name, password);

	return person;
}

Buyer* add_buyer()
{
	Person* person = add_person();
	Buyer* buyer = new Buyer(*person);
	delete person;

	return buyer;
}

int selectBuyer(int sumOfBuyers)
{
	int selectBuyer;
	cout << "There are " << sumOfBuyers << " Buyers." << endl;
	cout << "Select Buyer Number: ";
	cin >> selectBuyer;
	cout << endl;

	while (selectBuyer > sumOfBuyers || selectBuyer <= 0)
	{
		cout << "Your choice is invalid, please try again." << endl;
		cout << "Select Buyer Number: ";
		cin >> selectBuyer;
		cout << endl;
	}

	return selectBuyer;
}

Product* insertProduct(O_shop* o_shop)
{
	int mainCategory = 1;
	char mainNameOfProduct[20] = "def";
	int mainPriceOfProduct = 0;
	int mainSerialNumber = 1234;

	for (int i = 0; i < sizeof(n_category)/sizeof(n_category[0]); i++)
		cout << i+1 << ". " << n_category[i] << endl;

	cout << "\nSelect Category: ";
	cin >> mainCategory;
	cout << endl;

	while (mainCategory > (sizeof(n_category) / sizeof(n_category[0])) || mainCategory < 1)
	{
		cout << "Your choice is invalid, please try again." << endl;
		cin >> mainCategory;
	}

	cout << "Please enter Product name: " ;
	cin >> mainNameOfProduct;
	cout << "\nPlease enter Product price: ";
	cin >> mainPriceOfProduct;
	

	bool flag = false;
	for (int i = 0; i < o_shop->getNumberOfProducts(); i++)
	{
		if (int(o_shop->getAllProducts()[i]->getCategory()) == mainCategory-1 && !strcmp(o_shop->getAllProducts()[i]->getNameOfProduct(), mainNameOfProduct) && o_shop->getAllProducts()[i]->getPriceOfProduct() == mainPriceOfProduct)
		{
			mainSerialNumber = o_shop->getAllProducts()[i]->getSerialNumber();
			flag = true;
		}
	}

	if (!flag)
	{
		cout << "\nPlease enter Product Serial Number: ";
		cin >> mainSerialNumber;
	}

	cout << endl;

	int ownerNumber = selectSeller(o_shop->getNumberOfSellers());

	Product* p = new Product(mainNameOfProduct, mainPriceOfProduct, mainCategory, mainSerialNumber, ownerNumber);

	return p;
}

int productLocation()
{
	int productLocation;
	cout << "Select Product index Number: ";
	cin >> productLocation;
	cout << endl;

	return productLocation;
}
