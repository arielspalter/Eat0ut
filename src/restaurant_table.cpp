#include "../include/restaurant_table.h"
#include <iomanip>

RestaurantTable::RestaurantTable()
{
    AddRestaurant();
    //PrintAllRestaurants();
}
void RestaurantTable::AddRestaurant()
{
    
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (1, "My India", "625 Roselawn Ave", indian, 3));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (2, "Little China", "1100 Eglinton Ave E", asian, 55));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (3, "To The Bone", "555 Bloor St", burger_and_meat, 110));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (4, "L'Arpège", "127 Jarvis St", french_bistro, 15));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (5, "The West Fusion", "1234 Dufferin St", fusion, 80));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (6, "Spanish Dream", "2233 Carlton St", spanish_tapas, 80));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (7, "Ahui", "999 Mount Pleasant Ave", middleeastern, 80));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (8, "Achilles", "111 Charles St", vegetarian, 80));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (9, "Bacon Dump", "3456 Eglinton Ave W", burger_and_meat, 80));
    RestaurantTable::all_restaurants_.push_back(new RestaurantRecord (10, "Bamboolong", "483 Yonge St", indian, 80));
}
std::vector<RestaurantRecord *> RestaurantTable::ShowAllRestaurants()
{
    return all_restaurants_;
}
RestaurantTable::~RestaurantTable()
{
    for (size_t i = 0; i < all_restaurants_.size(); i++)
    {
        delete all_restaurants_[i];
    }
    
};