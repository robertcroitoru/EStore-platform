#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/Product/ResealedProduct.h"
#include "../Solution/User/User.h";

class Utility{

public:
    static bool compareProducts(ResealedProduct *, ResealedProduct *);
    //static bool compareFoodName(FoodProduct *, FoodProduct *);
   // static bool compareFoodCountry(FoodProduct *, FoodProduct *);
   // static bool compareFoodPrice(FoodProduct *, FoodProduct *);
    static bool compareFood(FoodProduct *, FoodProduct *);
    static bool compareUsers(User *, User *);

};