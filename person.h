#ifndef __PERSON_H
#define __PERSON_H

#include "Address.h"

class Person
{
	private:
		Address m_address;
		char* m_userName;
		int m_password;

	public:
		Person() = default;
		Person(const Address& address, const char* name, const int password);
		//Person(const Person& other)
		//{
		//	m_password = other.m_password;
		//	m_userName = new char[strlen(other.m_userName) + 1];
		//	strcpy(m_userName, other.m_userName);
		//}
		bool deletePerson();

		friend ostream& operator<<(ostream& os, Person p)
		{
			os << "Username: " << p.m_userName << "\nPassword: " << p.m_password << "\n" << p.m_address.printAddress() << endl;
			return os;
		}

};

#endif
