#include "../include/restaurant_record.h"

RestaurantRecord::RestaurantRecord(int id,std::string name,std::string address,RestaurantStyle style,int capacity): 
restaurant_id(id),
restaurant_name(name),
restaurant_address(address),
restaurant_style(style),
restaurant_capacity(capacity){};

RestaurantRecord::~RestaurantRecord(){}

