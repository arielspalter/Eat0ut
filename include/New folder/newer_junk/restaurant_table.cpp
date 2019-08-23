
#include "../include/restaurant_table.h"
//#include "../include/restaurant_record.h"
RestaurantTable::RestaurantTable()
{
    RestaurantRecord restaurant_1(1,"My India","625 Roselawn Ave", indian,80);
    RestaurantRecord restaurant_2(2,"Little China","1100 Eglinton Ave E", asian,55);
    RestaurantRecord restaurant_3(3,"To The Bone","555 Bloor St", burger_and_meat,110);
    RestaurantRecord restaurant_4(4,"L'Arpège","127 Jarvis St", french_bistro,15);
    RestaurantRecord restaurant_5(5,"The West Fusion","1234 Dufferin St", fusion,80);
    RestaurantRecord restaurant_6(6,"Spanish Dream","2233 Carlton St", spanish_tapas,80);
    RestaurantRecord restaurant_7(7,"Ahui","999 Mount Pleasant Ave", middleeastern,80);
    RestaurantRecord restaurant_8(8,"Achilles","111 Charles St", vegetarian,80);
    RestaurantRecord restaurant_9(9,"Bacon Dump","3456 Eglinton Ave W", burger_and_meat,80);
    RestaurantRecord restaurant_10(10,"Bamboolong","483 Yonge St", indian,80);
    RestaurantTable::all_restaurants_.push_back(&restaurant_1);
    RestaurantTable::all_restaurants_.push_back(&restaurant_2);
    RestaurantTable::all_restaurants_.push_back(&restaurant_3);
    RestaurantTable::all_restaurants_.push_back(&restaurant_4);
    RestaurantTable::all_restaurants_.push_back(&restaurant_5);
    RestaurantTable::all_restaurants_.push_back(&restaurant_6);
    RestaurantTable::all_restaurants_.push_back(&restaurant_7);
    RestaurantTable::all_restaurants_.push_back(&restaurant_8);
    RestaurantTable::all_restaurants_.push_back(&restaurant_9);
    RestaurantTable::all_restaurants_.push_back(&restaurant_10);
};
// void RestaurantTable::AddRestaurant()
// {


    
// }
std::vector<RestaurantRecord*> RestaurantTable::ShowAllRestaurants()
{
    return all_restaurants_;
}
RestaurantTable::RestaurantTable(const RestaurantTable&)
{
    std::cout << "Restaurant Table was copied";
}
RestaurantTable::~RestaurantTable()
{
    std::cout << "Restaurant Table was distroyed";
};
