#include "../include/DB.h"
#include "../include/io_operations.h"
#include <iomanip>

EatOutDatabase::EatOutDatabase()
{
    MainMenu();
};
EatOutDatabase::EatOutDatabase(const EatOutDatabase &){};
EatOutDatabase::~EatOutDatabase(){};

// Main menu
void EatOutDatabase::PrintMainMenu()
{
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "############ Welcome to Eat0ut ###########" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "#"
              << "          Please Pick an Option         #" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "#"
              << " press 1: to add new customer           #" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "#"
              << " press 2: to add new reservation        #" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "#"
              << " press 3: See all reservations          #" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "#"
              << " press 4: Search Resturant              #" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "#"
              << " press 5: Search Customer               #" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "#"
              << " press 6: Exit                          #" << '\n';
    std::cout << "#                                        #" << '\n';
    std::cout << "##########################################" << '\n';

    std::cout << '\n';
    std::cout << '\n';
}
// utility function to convert strings to lower
// std::string EatOutDatabase::ToLower(std::string input_string)
// {
//     std::string output_string;
//     for (size_t i = 0; i < input_string.size(); i++)
//     {
//         output_string.push_back(tolower(input_string[i]));
//     }
//     return output_string;
// }

// get restaurant ID
int EatOutDatabase::GetRestaurantId(std::string restaurant_name)
{
    //int restaurant_id;
    for (auto &x : reservations.restaurants_)
    {
        if (ioperations::ToLower(x->restaurant_name) == ioperations::ToLower(restaurant_name))
        {
            return x->restaurant_id;
        }
    }
}
// get restaurant Name
std::string EatOutDatabase::GetRestaurantName(std::string restaurant_name)
{
    for (auto &x : reservations.restaurants_)
    {
        if (ioperations::ToLower(x->restaurant_name) == ioperations::ToLower(restaurant_name))
        {
            return x->restaurant_name;
        }
    }
}

// get customer ID
int EatOutDatabase::GetCustomerId(std::string customer_name)
{
    for (auto &x : reservations.customers_)
    {
        if (ioperations::ToLower(x->customer_firstname_) == ioperations::ToLower(customer_name))
        {
            return x->customer_record_id_;
        }
    }
}
// get restaurant Name
std::string EatOutDatabase::GetCustomerName(std::string customer_name)
{
    for (auto &x : reservations.customers_)
    {
        if (ioperations::ToLower(x->customer_firstname_) == ioperations::ToLower(customer_name))
        {
            return x->customer_firstname_ + " " + x->customer_lastname_;
        }
    }
}
void EatOutDatabase::SearchRestaurant()
{
    std::string restaurant_name;

    std::cout << "##### Search Restaurant #####" << '\n';
    std::cout << "Enter restaurant name: ";
    std::cin.sync();
    std::getline(std::cin, restaurant_name);
    std::string full_restaurant_name = GetRestaurantName(restaurant_name);
    int restaurant_id = GetRestaurantId(restaurant_name);
    std::cout << '\n';
    std::cout << "*** Reservations for " << full_restaurant_name << " ***" << '\n';
    bool restaurant_exists = false;
    for (auto &x : reservations.reservations_)
    {
        if (restaurant_id == x->restaurant_id)
        {

            restaurant_exists = true;
            std::cout << "----------------------------" << '\n';
            std::cout << "reservation_id: " << x->reservation_id << '\n';
            for (auto &y : reservations.customers_)
            {
                if (x->customer_id == y->customer_record_id_)
                {
                    std::cout << "Customer name: " << y->customer_firstname_ << " " << y->customer_lastname_ << '\n';
                }
            }
        }
    }

    if (!restaurant_exists)
    {
        std::cout << "RESTAURANT NOT FOUND" << '\n';
    }
}

std::vector<std::string> EatOutDatabase::GetRestaurantNameByReservationId(int reservation_id)
{
    //std::vector<int> restaurants_ids;
    std::vector<std::string> restaurants_names;
    for (auto &x : reservations.reservations_)
    {
        if (reservation_id == x->reservation_id)
        {
            for (auto &y : reservations.restaurants_)
            {
                if (x->restaurant_id == y->restaurant_id)
                {
                    restaurants_names.push_back(y->restaurant_name);
                }
            }
            //restaurants_ids.push_back(x->restaurant_id);
            return restaurants_names;
        }
    }
}
void EatOutDatabase::SearchCustomer()
{
    std::string input_customer_name;
    std::cout << "##### Search Customer #####" << '\n';
    std::cout << "Enter customer first name: ";
    std::cin.sync();
    std::getline(std::cin, input_customer_name);
    std::string full_name = GetCustomerName(input_customer_name);
    int customer_id = GetCustomerId(input_customer_name);
    std::cout << '\n';
    std::cout << "*** Reservations for " << full_name << " ***" << '\n';
    bool customer_exists = false;
    for (auto &x : reservations.reservations_)
    {
        if (customer_id == x->customer_id)
        {

            customer_exists = true;
            std::cout << "----------------------------" << '\n';
            //std::cout << "reservation_id: " << x->reservation_id << '\n';
            std::vector<std::string> d = GetRestaurantNameByReservationId(x->reservation_id);
            for (auto &y : reservations.customers_)
            {
                if (x->customer_id == y->customer_record_id_)
                {
                    std::cout << "Customer name: " << y->customer_firstname_ << " " << y->customer_lastname_ << '\n';
                }
            }
            for (auto &z : d)
            {
                std::cout << "Reservation at: " << z << " " << '\n';
            }
        }
    }

    if (!customer_exists)
    {
        std::cout << "CUSTOMER NOT FOUND" << '\n';
    }
}
void EatOutDatabase::MainMenu()
{
    char user_input;
    PrintMainMenu();
    std::cin >> user_input;
    switch (user_input)
    {
    case '1':
        reservations.AddNewCustomer();
        MainMenu();
        break;
    case '2':
        reservations.AddReservation();
        MainMenu();
        break;
    case '3':
        reservations.PrintAllReservations();
        MainMenu();
        break;
    case '4':
        SearchRestaurant();
        MainMenu();
        break;

    case '5':
        SearchCustomer();
        MainMenu();
        break;

    case '6':
        std::cout << "You are leaving the system. See you next time!"<<'\n';
        system("pause");
        exit(0);
        break;

    default:
        std::cout << "INVALID OPTION" << '\n';
        MainMenu();
        break;
    }
}