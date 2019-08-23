#include "../include/customer_table.h"

// global customer id
int customer_id_ = 0;

CustomerTable::CustomerTable(){};
CustomerTable::CustomerTable(const CustomerTable &)
{
    std::cout << "Customer Table was copied";
}
CustomerTable::~CustomerTable() 
{
    for (size_t i = 0; i < all_customers_.size(); i++)
    {
        delete all_customers_[i];
    }
    
}

void CustomerTable::AddCustomer()
{
    
    std::string customer_firstname_;
    std::string customer_lastname_;
    std::string customer_phone_;
    std::string customer_email_;
    char confirmation;
    customer_id_ ++;
    std::cout << "########## Add a new customer ##########" << '\n'
              << '\n';
    std::cout << "Please enter your first name: ";
    std::cin >> customer_firstname_;
    std::cout << '\n';
    std::cout << "Please enter your last name: ";
    std::cin >> customer_lastname_;
    std::cout << '\n';
    std::cout << "Please enter your phone number: ";
    std::cin >> customer_phone_;
    std::cout << '\n';
    std::cout << "Please enter your email address: ";
    std::cin >> customer_email_;
    std::cout << '\n';
    std::cout << "----------Please confirm the information you have entered----------" << '\n';
    std::cout << "customer id: " << customer_id_ << '\n'; 
    std::cout << "first name: " << customer_firstname_ << '\n';
    std::cout << "last name: " << customer_lastname_ << '\n';
    std::cout << "phone number: " << customer_phone_ << '\n';
    std::cout << "email address: " << customer_email_ << '\n'<< '\n';
              
    std::cout << "Confirmed? (y/n): ";
    std::cin >> confirmation;
    if (confirmation == 'n' || confirmation == 'N')
    {
        AddCustomer();
    }
    else if (confirmation == 'y' || confirmation == 'Y')
    {
        
        all_customers_.push_back(
            new CustomerRecord(customer_id_, customer_firstname_, customer_lastname_, customer_phone_, customer_email_)
        );
    }
    else
    {
        char try_again;
        std::cout << "INVALID ENTRY! Would you like to try again? (y/n)" << '\n';
        std::cin >> try_again;
        if(try_again == 'y' || try_again == 'Y')
        {
            AddCustomer();
        }
        else
        {
            std::cout << "Bye Bye.." << '\n';
            return;
        }
        
    }
}
int CustomerTable::GetCustomerId()
{
    return customer_id_;
}
std::vector<CustomerRecord *> CustomerTable::ShowAllCustomers()
{
    return all_customers_;
}
