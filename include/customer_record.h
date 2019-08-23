#include <string>

class CustomerRecord
{
    private:
   
    public:
    int customer_record_id_;
    std::string customer_firstname_;
    std::string customer_lastname_;
    std::string customer_phone_;
    std::string customer_email_;
    CustomerRecord(int, std::string,std::string,std::string,std::string);
    CustomerRecord(const CustomerRecord&);
    ~CustomerRecord();

};