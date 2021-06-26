#include "FoodProduct.h"

FoodProduct::FoodProduct()
{
	leiPerKg = 0;
	countryOfOrigin = "";
}

FoodProduct::FoodProduct(const string &categorie, int id, const string &nume, float leiPerKg, const string &taraOrigine, int cantitate) : Product(categorie, id, nume, cantitate)
{
	this->countryOfOrigin = taraOrigine;
	this->leiPerKg = leiPerKg;
}

FoodProduct::FoodProduct(const FoodProduct &pa) : Product(pa)
{
	this->countryOfOrigin = pa.countryOfOrigin;
	this->leiPerKg = pa.leiPerKg;
}

void FoodProduct::setLeiPerKg(float leiPerKg)
{
	this->leiPerKg = leiPerKg;
}

void FoodProduct::setCountryOfOrigin(const string &countryOfOrigin)
{
	this->countryOfOrigin = countryOfOrigin;
}

float FoodProduct::getLeiPerKg()
{
	return leiPerKg;
}

string &FoodProduct::getCountryOfOrigin()
{
	return countryOfOrigin;
}

const FoodProduct &FoodProduct::operator=(const FoodProduct &a)
{
	this->leiPerKg = a.leiPerKg;
	this->countryOfOrigin = a.countryOfOrigin;
	Product::operator=(a);
	
	return *this;
}

string FoodProduct::getProductType()
{
	return "ALIMENTAR";
}

json FoodProduct::toJSON()
{
	return json(*this);
}

void FoodProduct::display()
{
	cout << "Product alimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Categorie : " << this->category << endl;
	cout << "ID : " << this->id << endl;
	cout << "Cantitate (stoc): " << this->quantity << endl;
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Tara de Origine : " << this->countryOfOrigin << endl
		 << endl;
}