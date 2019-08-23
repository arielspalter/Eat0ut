#include "reservation_record.h"
#include "customer_table.h"
#include "restaurant_table.h"
#include <string>
#include <vector>
#include <chrono>

// global tables

class ReservationsTable
{
private:
    
    int CheckCapacity(int);
    bool IsAvailable(int);
    //bool CustomerExists(std::vector<CustomerRecord *>);
    void CheckAvailabilityAndBook(int, int, int, int, time_t);

public:
    RestaurantTable global_restaurants;
    CustomerTable global_customers;
    std::vector<RestaurantRecord *> restaurants_;
    std::vector<CustomerRecord *> customers_;
    std::vector<ReservationsRecord *> reservations_;
    ReservationsTable();
    ReservationsTable(const ReservationsTable &);
    ~ReservationsTable();
    // loop through restaurants_ check capacity and int accumulator++
    void AddNewCustomer();
    void AddReservation();
    int ChooseRestaurant();
    void PrintAllReservations();

    std::vector<ReservationsRecord *> ShowAllReservations();
};