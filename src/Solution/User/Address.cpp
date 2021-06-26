#include "Address.h"

using namespace std;

Address::Address()
{
	county = "";
	locality = "";
	street = "";
	number = 0;
	block = "";
	apartment = 0;
}

Address::Address(const Address &address)
{
	this->county = address.county;
	this->locality = address.locality;
	this->street = address.street;
	this->number = address.number;
	this->block = address.block;
	this->apartment = address.apartment;
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{
	this->county = jud;
	this->locality = loc;
	this->street = str;
	this->number = nr;
	this->block = bl;
	this->apartment = ap;
}

const Address &Address::operator=(const Address &adr)
{
	this->county = adr.county;
	this->locality = adr.locality;
	this->street = adr.street;
	this->number = adr.number;
	this->block = adr.block;
	this->apartment = adr.apartment;
	return *this;
}

void Address::setStrada(const string &str)
{
	street = str;
}

void Address::setNumber(int nr)
{
	number = nr;
}

void Address::setBlock(const string &bl)
{
	block = bl;
}

void Address::setApartment(int ap)
{
	apartment = ap;
}

void Address::setCounty(const string &jud)
{
	county = jud;
}

void Address::setLocality(const string &loc)
{
	locality = loc;
}

string &Address::getStreet()
{
	return street;
}

int Address::getNumber()
{
	return number;
}
string &Address::getBlock()
{
	return block;
}

int Address::getApartment()
{
	return apartment;
}

string &Address::getCounty()
{
	return county;
}

string &Address::getLocality()
{
	return locality;
}

bool Address::operator==(const Address &address)
{
	if (county == address.county && locality == address.locality && street == address.street && number == address.number && block == address.block && apartment == address.apartment)
		return true;

	return false;
}

bool Address::operator!=(const Address &address)
{
	return !(*this == address);
}

ostream &operator<<(ostream &os, const Address &a)
{
	os << "Country: " << a.county << "\n";
	os << "Locality: " << a.locality << "\n";
	os << "Street: " << a.street << "\n";
	os << "Block: " << a.block << "\n";
	os << "Apartment:" << a.apartment << "\n";
	os << "\n";
	return os;
}

json Address::toJSON()
{
	return json(*this);
}