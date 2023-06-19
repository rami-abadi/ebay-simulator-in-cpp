#ifndef __ADDRESS_H
#define __ADDRESS_H

class Address
{
	protected:
		char* m_stateName;
		char* m_cityName;
		char* m_streetName;
		int m_buildingNumber;

	public:
		Address() = default;
		Address(const char* stateName, const char* cityName, const char* streetName, const int buildingNumber);
		bool deleteAddress();
		string printAddress() const;
};

#endif
