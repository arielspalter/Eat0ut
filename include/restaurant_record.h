#include<string>
#include "restaurant_styles.h"

class RestaurantRecord
{
    private:
   
    //static int number_of_reservations;

    public:
     int restaurant_id;
    std::string restaurant_address;
    RestaurantStyle restaurant_style;
    int restaurant_capacity;
    std::string restaurant_name;
    RestaurantRecord(int,std::string,std::string,RestaurantStyle,int);
    ~RestaurantRecord();

};