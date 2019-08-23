#include "restaurant_record.h"
#include <iostream>
#include <string>
#include <vector>

class RestaurantTable
{
    private:
    std::vector<RestaurantRecord*> all_restaurants_;
    
    public:
    RestaurantTable();
    RestaurantTable(const RestaurantTable&);
    ~RestaurantTable();
    
    void AddRestaurant();
    std::vector<RestaurantRecord*> ShowAllRestaurants();
    void PrintAllRestaurants();
};