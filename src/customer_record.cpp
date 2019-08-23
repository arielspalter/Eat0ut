#include "../include/customer_record.h"

// customer id is added in customer_table as static int that increments with any addition of new customer
CustomerRecord::CustomerRecord(int customerid, std::string firstname,std::string lastname,std::string phone,std::string email):
customer_record_id_(customerid),
customer_firstname_(firstname),
customer_lastname_(lastname),
customer_phone_(phone),
customer_email_(email)
{
    //customer_record_id_++;
    //customer_record_id_ = customerid;
};
CustomerRecord::CustomerRecord(const CustomerRecord&){};
CustomerRecord::~CustomerRecord(){};

