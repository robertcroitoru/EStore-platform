#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	ShoppingCart *aux = new ShoppingCart();
	for(list<User*>::iterator iter = usr.begin(); iter != usr.end(); iter++){

		__UserID__ProductsCart__.insert({(*iter)->getUserID(), aux});
	}
}

list<Product *> &Server::getProductsList()
{
	return prod;
}

list<User *> &Server::getUsersList()
{
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	if(quantity <= 0) //pentru ca nu se pot adauga numere negative de produse in cos
		return false;
	
	bool idprodus = false, iduser = false;
	Product *aux;
	for(list<Product*>::iterator iter = prod.begin(); iter != prod.end(); iter++){
		
		if((*iter)->getId() == productID){
			idprodus = true; // cautam in lista de produse ID ul si retinem daca s-a gasit
			aux = (*iter); // retinem produsul pentru a verifica, mai tarziu, cantitatea
		}
	}

	for(list<User*>::iterator iter = usr.begin(); iter != usr.end(); iter++){

		if((*iter)->getUserID() == userID)
			iduser = true; // la fel si pentru user
	}

	if(idprodus == false || iduser == false)
		return false; // daca nu s-a gasit ID-ul produsului sau al userului, intoarcem false

	if(quantity > aux->getQuantity())
		return false; // in cazul in care se vrea a se adduaga mai multe produse de acelasi tip decat sunt pe stoc

	if(__UserID__ProductsCart__[userID]->getShoppingCart().count(productID) == 0){
		
		__UserID__ProductsCart__[userID]->addProduct(productID, quantity); //daca produsul nu se afla in cos, il adaugam
	}
	else{

		__UserID__ProductsCart__[userID]->raiseQuantity(productID, quantity);
	} 
	aux->decreaseQuantity(quantity);

	delete aux;
	return true;

}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	if(quantity <= 0) //pentru ca nu se pot adauga numere negative de produse in cos
		return false;

	bool idprodus = false, iduser = false;
	Product *aux;
	for(list<Product*>::iterator iter = prod.begin(); iter != prod.end(); iter++){
		
		if((*iter)->getId() == productID){
			idprodus = true; // cautam in lista de produse ID ul si retinem daca s-a gasit
			aux = (*iter); // retinem produsul pentru a verifica, mai tarziu, cantitatea
		}
	}

	for(list<User*>::iterator iter = usr.begin(); iter != usr.end(); iter++){

		if((*iter)->getUserID() == userID)
			iduser = true; // la fel si pentru user
	}

	return true;
	
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}