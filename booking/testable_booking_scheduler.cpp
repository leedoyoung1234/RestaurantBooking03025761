#include "gmock/gmock.h"
#include "booking_scheduler.cpp"

class TestableBookingScheduler : public BookingScheduler {
public:
	static 	tm getTm(int year, int mon, int day, int hour, int min) {
		tm result = { 0, min, hour, day, mon - 1, year - 1900, 0, 0, -1 };
		return result;
	}

	TestableBookingScheduler(int capacityPerHour) :
		BookingScheduler{ capacityPerHour } {
	}
	MOCK_METHOD(time_t, getNow, (), (override));
private:
	tm dateTime;
};