#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Ticket {
	const string ticketId;
	int rowNumber;
	int seatNumber;
	bool isReserved;
public:
	//default constructor
	Ticket() :ticketId("0000") {
		this->rowNumber = 0;
		this->seatNumber = 0;
		this->isReserved = false;
	}
	//constructor with parameters
	Ticket(string ticketId, int rowNumber, int seatNumber, bool isReserved) :ticketId(ticketId) {
		this->rowNumber = rowNumber;
		this->seatNumber = seatNumber;
		this->isReserved = isReserved;
	}
	//accessor methods
	//getters
	string getTicketId() {
		return this->ticketId;
	}
	int getRowNumber() {
		return this->rowNumber;
	}
	int getSeatNumber() {
		return this->seatNumber;
	}
	bool getIsReserved() {
		return this->isReserved;
	}
	//setters
	void setRowNumer(int rowNumber) {
		if (rowNumber > 0) {
			this->rowNumber = rowNumber;
		}
		else {
			this->rowNumber = 0;
		}
	}
	void setSeatNumber(int seatNumber) {
		if (seatNumber > 0) {
			this->seatNumber = seatNumber;
		}
		else {
			this->seatNumber = 0;
		}
	}
	void setIsReserved(bool isReserved) {
		this->isReserved = isReserved;
	}
	//copy constructor
	Ticket(const Ticket& t) :ticketId(t.ticketId) {
		this->rowNumber = t.rowNumber;
		this->seatNumber = t.seatNumber;
		this->isReserved = t.isReserved;
	}
	//overloading operator=
	Ticket& operator=(const Ticket& t) {
		if (this != &t) {
			this->rowNumber = t.rowNumber;
			this->seatNumber = t.seatNumber;
			this->isReserved = t.isReserved;
			return *this;
		}
	}
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
public:
	//default constructor
	Zone() {
		this->maxRowNumber = 0;
		this->maxSeatsPerRow = 0;
		this->numberOfTickets = 0;
		this->ticket = nullptr;
	}
	//constructor with parameters
	Zone(int maxRowNumber, int maxSeatsPerRow, int numberOfTickets, Ticket* ticket) {
		this->maxRowNumber = maxRowNumber;
		this->maxSeatsPerRow = maxSeatsPerRow;
		this->numberOfTickets = numberOfTickets;
		this->ticket = ticket;
	}
	//accessor methods 
	//getters 
	int getMaxRowNumber() {
		return this->maxRowNumber;
	}
	int getMaxSeatsPerRow() {
		return this->maxSeatsPerRow;
	}
	int getNumberOfTickets() {
		return this->numberOfTickets;
	}

	Ticket* getTicket() {
		return this->ticket;
	}
	//setters
	void setMaxRowNumber(int maxRowNumber) {
		if (maxRowNumber > 0) {
			this->maxRowNumber = maxRowNumber;
		}
		else {
			this->maxRowNumber = 0;
		}
	}
	void setMaxSeatsPerRow(int maxSeatsPerRow) {
		if (maxSeatsPerRow > 0) {
			this->maxRowNumber = maxSeatsPerRow;
		}
		else {
			this->maxSeatsPerRow = 0;
		}
	}
	void setNumberOfTickets(int numberOfTickets) {
		if (numberOfTickets > 0) {
			this->numberOfTickets = numberOfTickets;
		}
		else {
			this->numberOfTickets = 0;
		}
	}

	void setTicket(Ticket* newTicket) {
		this->ticket = newTicket;
	}
	//copy constructor
	Zone(const Zone& z) {
		this->maxRowNumber = z.maxRowNumber;
		this->maxSeatsPerRow = z.maxSeatsPerRow;
		this->numberOfTickets = z.numberOfTickets;
		this->ticket = z.ticket;
	}
	Zone& operator=(const Zone& z) {
		if (this != &z) {
			this->maxRowNumber = z.maxRowNumber;
			this->maxSeatsPerRow = z.maxSeatsPerRow;
			this->numberOfTickets = z.numberOfTickets;
			this->ticket = z.ticket;
			return *this;
		}
	}


};

class Location {

	string name;
	int maximumCapacity;
	int numberOfZones;
	Zone* zones;
public:
	//default constructor
	Location() {
		this->name = "N/A";
		this->maximumCapacity = 0;
		this->numberOfZones = 0;
		this->zones = nullptr;
	}
	//constructor with parameters
	Location(string name, int maximumCapacity, int numberOfZones, Zone* zones) {
		this->name = name;
		this->maximumCapacity = maximumCapacity;
		this->numberOfZones = numberOfZones;
		this->zones = zones;
	}
	//accessor methods
	//getters
	string getName() {
		return this->name;
	}
	int getMaximumCapacity() {
		return this->maximumCapacity;
	}
	int getNumberOfZones() {
		return this->numberOfZones;
	}
	//
	Zone* getZones() {
		return this->zones;
	}
	//setters
	void setName(string name) {
		if (name.size() > 3) {
			this->name = name;
		}
		else {
			this->name = "N/A";
		}
	}
	void setMaximumCapacity(int maximumCapacity) {
		if (maximumCapacity > 0) {
			this->maximumCapacity = maximumCapacity;
		}
		else {
			this->maximumCapacity = 0;
		}
	}
	void setNumberOfZones(int numberOfZones) {
		if (numberOfZones > 0) {
			this->numberOfZones = numberOfZones;
		}
		else {
			this->numberOfZones = 0;
		}
	}
	//
	void setZones(Zone* zones) {
		this->zones = zones;
	}
	//copy constructor
	Location(const Location& l) {
		this->name = l.name;
		this->maximumCapacity = l.maximumCapacity;
		this->numberOfZones = l.numberOfZones;
		this->zones = l.zones;
	}
	//operator=
	Location& operator = (const Location &l) {
		if (this != &l) {
		this->name = l.name;
		this->maximumCapacity = l.maximumCapacity;
		this->numberOfZones = l.numberOfZones;
		this->zones = l.zones;
		return *this;

		}
	}
};
class Event {
	string eventName;
	Location location;
public:
	//default constructor
	Event() {
		this->eventName = "N/A";
		this->location = Location();
	}
	//constructor with parameters
	Event(string eventName, Location location) {
		this->eventName = eventName;
		this->location = location;
	}
	//accessor methods
	//getters
	string getEventName() {
		return this->eventName;
	}
	//
	Location getLocation() {
		return this->location;
	}
	//setters
	void setEventName(string name) {
		this->eventName = eventName;
	}
	//
	void setLocation(Location location) {
		this->location = location;
	}
	//copy constructor
	Event(const Event& e) {
		this->eventName = e.eventName;
		this->location = e.location;
	}
	//operator=
	Event& operator=(const Event& e) {
		if (this != &e) {
			this->eventName = e.eventName;
			this->location = e.location;
			return *this;
		}
	}

};
int main() {

}