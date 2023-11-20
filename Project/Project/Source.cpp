#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;
class Ticket {

	const string ticketId;
	int rowNumber;
	int seatNumber;
	bool isReserved;
};
enum ZoneName {
	NORMAL = 1, PREMIUM = 2, VIP = 3
};
class Zone {

	ZoneName name;
	int maxRowNumber;
	int maxSeatsPerRow;
	int numberOfTickets;
	Ticket* ticket;
};
class Location {

	char* name;
	int maximumCapacity;
	int numberOfZones;
	Zone* zones;
};
class Event {

	string eventName;
	Location location;
};