//#include "restaurant_table.h"
//#include "customer_table.h"
#include <string>
#include <vector>
#include <chrono>

class ReservationsRecord
{
private:
public:
    int reservation_id;
    int restaurant_id;
    int customer_id;
    int accumulated_reservations;
    std::time_t reservation_time;
    ReservationsRecord(int, int, int, int, time_t);
    ReservationsRecord(const ReservationsRecord &);
    ~ReservationsRecord();
};