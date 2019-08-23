#include "../include/reservations_table.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <limits>
#include "../include/io_operations.h"

// global reservation id
static int reservation_id = 0;

ReservationsTable::ReservationsTable(){};

void ReservationsTable::AddNewCustomer()
{
    global_customers.AddCustomer();
}
ReservationsTable::ReservationsTable(const ReservationsTable &)
{
    std::cout << "Reservation table was copied";
}
ReservationsTable::~ReservationsTable()
{
    for (size_t i = 0; i < reservations_.size(); i++)
    {
        delete reservations_[i];
    }
    for (size_t i = 0; i < customers_.size(); i++)
    {
        delete customers_[i];
    }
    for (size_t i = 0; i < restaurants_.size(); i++)
    {
        delete restaurants_[i];
    }
};

std::vector<ReservationsRecord *> ReservationsTable::ShowAllReservations()
{
    return reservations_;
}

int ReservationsTable::ChooseRestaurant()
{
    restaurants_ = global_restaurants.ShowAllRestaurants();
    int restaurant_number_user_input, restaurant_id = 0;
    bool restaurant_exists = false;
    std::cout << "##### Please pick a restaurant from the list below #####" << '\n';
    for (auto &x : restaurants_)
    {
        std::cout << ""
                  << "For: "
                  << "'" << x->restaurant_name << "'";
        std::cout << " -- Press " << x->restaurant_id << '\n';
    }
    std::cout << "your entry: ";
    std::cin >> restaurant_number_user_input;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    for (auto &x : restaurants_)
    {
        if (restaurant_number_user_input == x->restaurant_id)
        {
            restaurant_exists = true;
            restaurant_id = x->restaurant_id;
            std::cout  << '\n';
            std::cout << "you have picked: " << x->restaurant_name << '\n';
            std::cout  << '\n';
            return restaurant_number_user_input;
        }
    }
    if (!restaurant_exists)
    {
        char user_input;
        std::cout << "Restaurant not found! Would you like to try again? (y/n)" << '\n';
        std::cout << "your entry: ";
        std::cin >> user_input;
        if (user_input == 'y' || user_input == 'Y')
        {
            ChooseRestaurant();
        }
        else if (user_input == 'n' || user_input == 'N')
        {
            std::cout << "Bye Bye..." << '\n';
            return 0;
        }
        else
        {
            std::cout << "INVALID ENTRY" << '\n';
            ChooseRestaurant();
        }
    }
}
// retrieve the restaurant capacity
int ReservationsTable::CheckCapacity(int restaurant_id)
{
    int capacity;
    for (auto &x : restaurants_)
    {
        if (restaurant_id == x->restaurant_id)
        {
            capacity = x->restaurant_capacity;
        }
    }
    return capacity;
}
// check the number of reservation is less than the capacity
bool ReservationsTable::IsAvailable(int restaurant_id)
{
    bool is_available = false;
    int capacity = CheckCapacity(restaurant_id);
    int accumulated_reservations = 1;

    for (auto &x : reservations_)
    {
        if (restaurant_id == x->restaurant_id)
        {
            accumulated_reservations++;
        }
    }
    if (accumulated_reservations < capacity)
    {
        is_available = true;
    }
    return is_available;
}

// if less restaurant is not full, perform reservation
void ReservationsTable::CheckAvailabilityAndBook(int reservation_id, int restaurant_id, int customer_id, int accumulated, time_t current_time)
{
    if (IsAvailable(restaurant_id))
    {
        reservations_.push_back(new ReservationsRecord(reservation_id, restaurant_id, customer_id, accumulated, current_time));
        std::cout << "--- Your reservation is accepted! bon a petite! ---" << '\n';
    }
    else
    {
        char another_reservation_user_input;
        std::cout << "Sorry, the restaurant is full. would you like to make another reservation? (y/n)" << '\n';
        std::cout << "your entry: ";
        std::cin >> another_reservation_user_input;
        if (another_reservation_user_input == 'y' || another_reservation_user_input == 'Y')
        {
            AddReservation();
        }
        else
        {
            std::cout << "Okay, Will see you soon. Bye Bye.." << '\n';
            return;
        }
    }
}

// main method to add reservation
void ReservationsTable::AddReservation()
{
    customers_ = global_customers.ShowAllCustomers();
    static int reservation_id = 0,accumulated=0;
    int restaurant_id, customer_id, number_of_existing_customers = 0;
    std::string customer_fn;
    std::vector<CustomerRecord *> temp;
    bool customer_exists = false;
    std::cout << "########## Add a new Reservation ##########" << '\n';
    std::cout << "enter customer name: ";
    std::cin.sync();
    std::cin.clear();
    std::cin >> customer_fn;

    for (size_t i = 0; i < customers_.size(); i++)
    {
        if (ioperations::ToLower(customers_[i]->customer_firstname_) == ioperations::ToLower(customer_fn))
        {
            number_of_existing_customers++;
            temp.push_back(customers_[i]);
            std::cout << "are you: " << customers_[i]->customer_firstname_ << " " << customers_[i]->customer_lastname_ << "?"
                      << " press " << number_of_existing_customers << '\n';
            customer_exists = true;
        }
    }
    if (!customer_exists)
    {
        std::cout << "CUSTOMER NOT FOUND! " << '\n';
        return;
    }
    else
    {
        bool is_entry_valid = false;
        int input_option;
        std::cin >> input_option;
        for (size_t i = 0; i < temp.size(); i++)
        {
            if ((i + 1) == input_option)
            {
                std::cout << "you are: " << temp[i]->customer_firstname_ << " " << temp[i]->customer_lastname_ << '\n';
                customer_id = temp[i]->customer_record_id_;
                is_entry_valid = true;
                break;
            }
        }

        if (is_entry_valid)
        {
            restaurant_id = ChooseRestaurant();
            reservation_id++;
            accumulated++;
            auto current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            CheckAvailabilityAndBook(reservation_id, restaurant_id, customer_id, accumulated, current_time);
        }
        else
        {
            std::cout << "INVALID ENTRY" <<'\n';
            AddReservation();
        }
    }
}

// print all reservations in the database
void ReservationsTable::PrintAllReservations()
{
    int accumulator = 0;
    std::cout << '\n';
    std::cout << "##### RESERVATION REPORT #####" << '\n';
    for (auto &x : reservations_)
    {
        accumulator++;
        std::cout << '\n';
        std::cout << "##### reservation " << accumulator << " #####" << '\n';
        std::cout << "reservation_id: " << x->reservation_id << '\n';
        std::cout << "restaurant_id: " << x->restaurant_id << '\n';
        std::cout << "customer_id: " << x->customer_id << '\n';
        std::cout << "number of reservations: " << x->accumulated_reservations << '\n';
        std::cout << "timestamp: " << x->reservation_time << '\n';
    }
}
