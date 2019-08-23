#include "customer_record.h"
#include <iostream>
#include <vector>

class CustomerTable
{
    private:
    std::vector<CustomerRecord*> all_customers_;
    
    public:
    
    CustomerTable();
    CustomerTable(const CustomerTable&);
    ~CustomerTable();

    void AddCustomer();
    int GetCustomerId();
    std::vector<CustomerRecord*> ShowAllCustomers();
};