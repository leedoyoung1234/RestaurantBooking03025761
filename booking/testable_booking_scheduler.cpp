#include "booking_scheduler.cpp"

class TestableBookingScheduler : public BookingScheduler {
public:
	static 	tm getTm(int year, int mon, int day, int hour, int min) {
		tm result = { 0, min, hour, day, mon - 1, year - 1900, 0, 0, -1 };
		return result;
	}

	TestableBookingScheduler(int capacityPerHour, tm dateTime) :
		BookingScheduler{ capacityPerHour },
		dateTime{ dateTime } {
	}
	time_t getNow() override {
		return mktime(&dateTime);
	}
private:
	tm dateTime;
};