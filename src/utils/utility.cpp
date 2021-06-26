#include "utility.h"

bool Utility::compareProducts(ResealedProduct *a, ResealedProduct *b){

    return (a->getPrice() < b->getPrice());
}

/*bool Utility::compareFoodName(FoodProduct *a, FoodProduct *b){

    return (a->getName() < b->getName());
}

bool Utility::compareFoodCountry(FoodProduct *a, FoodProduct *b){

    return (a->getCountryOfOrigin() < b->getCountryOfOrigin());
    
}

bool Utility::compareFoodPrice(FoodProduct *a, FoodProduct *b){

    return (a->getLeiPerKg() < b->getLeiPerKg());
    
}
*/
bool Utility::compareFood(FoodProduct *a, FoodProduct *b){

    if (a->getName() < b->getName()){return true;}
        if (a->getName() > b->getName()){return false;}
    if (a->getCountryOfOrigin() < b->getCountryOfOrigin()){return true;}
        if (a->getCountryOfOrigin() > b->getCountryOfOrigin()){return false;}
    if (a->getLeiPerKg() < b->getLeiPerKg()){return true;}
        if (a->getLeiPerKg() > b->getLeiPerKg()){return false;}
}

bool Utility::compareUsers(User *a, User *b){

    return a->getUserID() < b->getUserID();
}