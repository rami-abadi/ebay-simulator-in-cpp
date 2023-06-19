#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "Person.h"
#include "Address.h"
#include "O_shop.h"

Person::Person(const Address& address, const char* name, const int password)
{
	m_userName = new char[strlen(name) + 1];
	strcpy(m_userName, name);

	m_password = password;

	m_address = address;
}

bool Person::deletePerson()
{
	delete[] m_userName;

	return true;
}
