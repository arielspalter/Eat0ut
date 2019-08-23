#include "../include/reservation_record.h"
#include <iostream>

ReservationsRecord::ReservationsRecord(int id, int rest_id, int cust_id, int accumlated,time_t date):
reservation_id(id),
restaurant_id(rest_id),
customer_id(cust_id),
accumulated_reservations(accumlated),
reservation_time(date)
{};
ReservationsRecord::ReservationsRecord(const ReservationsRecord&)
{
    std::cout << "Reservation Record was copied";
}
ReservationsRecord::~ReservationsRecord(){}