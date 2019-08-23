// #include "restaurant_table.h"
// #include "customer_table.h"
#include "reservations_table.h"
#include <string>
#include <vector>
//#include "io_operations.h"

class EatOutDatabase
{
private:
    ReservationsTable reservations;
    void PrintMainMenu();
    int GetRestaurantId(std::string);
    std::string GetRestaurantName(std::string);
    std::vector<std::string> GetRestaurantNameByReservationId(int);
    int GetCustomerId(std::string);
    std::string GetCustomerName(std::string);
    //std::string ToLower(std::string);

public:
    EatOutDatabase();
    EatOutDatabase(const EatOutDatabase &);
    ~EatOutDatabase();
    void InitializeTables();
    void SearchRestaurant();
    void SearchCustomer();
    void AddNewCustomer();
    void AddNewReservation();
    void ShowAllTables();
    void MainMenu();
};