#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	this->payMethod = payMethod;
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod = payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	this->shoppingCart.insert({id, quantity});
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	this->shoppingCart[id] = shoppingCart[id] + quantity;
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	this->shoppingCart[id] = shoppingCart[id] - quantity;
}

int ShoppingCart::getQuantity(int productID)
{
	if(shoppingCart.count(productID) > 0)
		return shoppingCart[productID];
	return -1;
}

void ShoppingCart::deleteProduct(int productID)
{
	this->shoppingCart.erase(productID);
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return this->shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}