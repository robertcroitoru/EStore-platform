#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
  
  list<Product*>::iterator iter;
  //list<Product*> ProductList;
  list<Product*> EspressoareReduse;

  //Server.GetInstance();
  //ProductList = server->getProductsList();
  for(iter = server->getProductsList().begin(); iter != server->getProductsList().end(); iter++){

      if((*iter)->getCategory() == "espressor" && (*iter)->getProductType() == "REDUS")

        EspressoareReduse.push_back(*iter);
  }

  return EspressoareReduse;
}

list<User*> QuerySolver::Query_3b(){
  
  list<User*> UsersBasic;
  list<User*>::iterator iter;
  for(iter = server->getUsersList().begin(); iter != server->getUsersList().end(); iter++){

      if((*iter)->getUserType() == "NONPREMIUM" && (*iter)->getTransportCost() <=11.5)

        UsersBasic.push_back(*iter);
  }
  return UsersBasic;
}

list<Product*> QuerySolver::Query_3c(){
  
  list<ResealedProduct*> ProduseResealed;
  list<Product*> Produse;
  for(list<Product*>::iterator iter = server->getProductsList().begin(); iter != server->getProductsList().end(); iter++){

      if((*iter)->getProductType() == "RESIGILAT"){
        ResealedProduct *aux = dynamic_cast<ResealedProduct*>(*iter);
        if(aux != nullptr){
              
              if(aux->getReason() == "lipsa_accesorii")
                  ProduseResealed.push_back(aux);
        }
      }
  }
  
  ProduseResealed.sort(Utility::compareProducts);
  for(list<ResealedProduct*>::iterator iter = ProduseResealed.begin(); iter != ProduseResealed.end(); iter++){

    Product *aux = dynamic_cast<Product *>(*iter);
    Produse.push_back(aux);
  }

  return Produse;
}

list<Product*> QuerySolver::Query_3d(){
  
  list<FoodProduct*> ProduseFood;
  list<Product*> Produse;
  for(list<Product*>::iterator iter = server->getProductsList().begin(); iter != server->getProductsList().end(); iter++){

      if((*iter)->getProductType() == "ALIMENTAR"){
        FoodProduct *aux = dynamic_cast<FoodProduct*>(*iter);
        if(aux != nullptr){
      
            ProduseFood.push_back(aux);
        }
      }
  }

  ProduseFood.sort(Utility::compareFood);
  for(list<FoodProduct*>::iterator iter = ProduseFood.begin(); iter != ProduseFood.end(); iter++){

    Product *aux = dynamic_cast<Product *>(*iter);
    Produse.push_back(aux);
  }

  return Produse;
}

list<User*> QuerySolver::Query_3e(){
  
  //aflam judetul cu cei mai multi utilizatori, folosind un  map cu key - numele jud si data - numarul de utilizatori
  map<string, int> Judete;
  for(list<User*>::iterator iter = server->getUsersList().begin(); iter != server->getUsersList().end(); iter++){

      if(Judete.count((*iter)->getBillingData().getCounty()) == 0)
          Judete.insert({(*iter)->getBillingData().getCounty(), 1});
      if(Judete.count((*iter)->getDeliveryData().getCounty()) == 0)
          Judete.insert({(*iter)->getDeliveryData().getCounty(), 1});
  }

  for(list<User*>::iterator iter = server->getUsersList().begin(); iter != server->getUsersList().end(); iter++){

      Judete[(*iter)->getBillingData().getCounty()]++;
      Judete[(*iter)->getDeliveryData().getCounty()]++;
  }

  int max = 0;
  string JudMAx;
  for(map<string, int>::iterator iter = Judete.begin(); iter!= Judete.end(); iter++){

      if(iter->second > max){

          max = iter->second;
          JudMAx = iter->first;
      }
  }

  list<User*> Userslist;
  for(list<User*>::iterator iter = server->getUsersList().begin(); iter != server->getUsersList().end(); iter++){

      if((*iter)->getDeliveryData().getBlock() == (*iter)->getBillingData().getBlock() &&  (*iter)->getBillingData().getBlock() == "-")
          if((*iter)->getDeliveryData().getApartment() == (*iter)->getBillingData().getApartment() && (*iter)->getBillingData().getApartment() == 0)
            if((*iter)->getDeliveryData().getCounty() == JudMAx)
                Userslist.push_back(*iter);
  }
  Userslist.sort(Utility::compareUsers);
  return Userslist;
        
}

list<User*> QuerySolver::Query_3f()
{
  
  list<User*> PremiumUsers;

  for(list<User*>::iterator iter = server->getUsersList().begin(); iter != server->getUsersList().end(); iter++){

       if((*iter)->getUserType() == "PREMIUM")

          PremiumUsers.push_back(*iter);
  }

  map<int, int> Discounts;
  list<User*> UsersCuCupoane;
  for(list<User*>::iterator iter1 = PremiumUsers.begin(); iter1 != PremiumUsers.end(); iter1++){

      Discounts = dynamic_cast<PremiumUser *>(*iter1)->getDiscounts();
      int ok = 0;
      for(map<int, int>::iterator iter2 = Discounts.begin(); iter2 != Discounts.end(); iter2++){

          for(list<Product*>::iterator iter3 = server->getProductsList().begin(); iter3 != server->getProductsList().end(); iter3++){

              if((*iter3)->getId() == (*iter2).first && ok == 0)

                //if((*iter3)->getId()/10%10 == 1 || (*iter3)->getId()/10%10 == 6){
                if((*iter3)->getCategory() == "telefon" || (*iter3)->getCategory() == "imprimanta"){
                    UsersCuCupoane.push_back(*iter1);
                    ok = 1; // in cazul in care am gasit 
                }
          }
      }
  }

  return UsersCuCupoane;
  

}
