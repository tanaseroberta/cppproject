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
	Ticket() :ticketId("000") {
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
	//operator <<
	friend ostream& operator<<(ostream& out, Ticket&);
	//operator>>
	friend istream& operator>>(istream& in, Ticket&);


	//operator !overloading
	bool operator !()
	{
		return !this->isReserved;
	}
	//operator cast 
	
	operator int()
	{
		return this->seatNumber;
	}

};

ostream& operator<<(ostream& out, Ticket& t)
{
	out << t.ticketId << endl;
	out << t.rowNumber << endl;
	out << t.seatNumber << endl;
	out << t.isReserved << endl;
	return out;
}
istream& operator>>(istream& in, Ticket& t) {


	cout << "Enter Row Number: ";
	in >> t.rowNumber;

	cout << "Enter Seat Number: ";
	in >> t.seatNumber;

	cout << "Is Reserved (1 for Yes, 0 for No): ";
	in >> t.isReserved;

	return in;
}

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
		this->ticket = new Ticket[numberOfTickets];
		for (int i = 0; i < numberOfTickets; ++i) {
			this->ticket[i] = ticket[i];
		}
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
			this->maxSeatsPerRow = maxSeatsPerRow;
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
		this->ticket = new Ticket[z.numberOfTickets];
		for (int i = 0; i < z.numberOfTickets; ++i) {
			this->ticket[i] = z.ticket[i];
		}
	
	}
	Zone& operator=(const Zone& z) {
		if (this != &z) {
			this->maxRowNumber = z.maxRowNumber;
			this->maxSeatsPerRow = z.maxSeatsPerRow;
			this->numberOfTickets = z.numberOfTickets;
			this->ticket = new Ticket[z.numberOfTickets];
			for (int i = 0; i < z.numberOfTickets; ++i) {
				this->ticket[i] = z.ticket[i];
			}
			return *this;
		}
	}
	//destructor
	~Zone() {
		if (ticket != nullptr) {
			delete[]this->ticket;
		}
	}
	//operator <<
	friend ostream& operator<<(ostream& out, Zone& );
	//operator>>
	friend istream& operator<<(istream& in, Zone&);
	//operator !overloading
	bool operator !() {
	
		return (this->numberOfTickets == 0);// Return true if the zone has no tickets
	}
	//operator cast 

	operator int() {
		
		return this->numberOfTickets; //  Return the total number of tickets as an integer
	}
};
ostream& operator<<(ostream& out, Zone& z) {
	out << z.maxRowNumber << endl;
	out << z.maxSeatsPerRow << endl;
	out << z.numberOfTickets << endl;
	out << z.ticket << endl;
	return out;
}
istream& operator<<(istream& in, Zone& z) {
	cout << "Enter maximum row number: ";
	in >> z.maxRowNumber;
	cout << "Enter maximum seats per row: ";
	in >> z.maxSeatsPerRow;
	cout << "Enter number of ticket: ";
	in >> z.numberOfTickets;

	return in;
}
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
		for (int i = 0; i < l.numberOfZones; ++i) {
			this->zones[i] = l.zones[i];
		}
	}
	//operator=
	Location& operator = (const Location &l) {
		if (this != &l) {
			this->name = l.name;
			this->maximumCapacity = l.maximumCapacity;
			this->numberOfZones = l.numberOfZones;
			for (int i = 0; i < l.numberOfZones; ++i) {
				this->zones[i] = l.zones[i];
			}
		}
		return *this;

		
	}
	// operator<<
	friend ostream& operator<<(ostream& out, Location& );
	//operator>>
	friend istream& operator>>(istream& in, Location& );
};
ostream& operator<<(ostream& out, Location& l) {
	out << l.name << endl;
	out << l.maximumCapacity << endl;
	out << l.numberOfZones << endl;
	out << l.zones;
	return out;
}
istream& operator>>(istream& in, Location& l) {
	cout << "Enter name of the location: ";
	in >> l.name;
	cout << "Enter maximum Capacity: ";
	in >> l.maximumCapacity;
	cout << "Enter number of zones: ";
	in >> l.numberOfZones;
	return in;
	
}
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
	void setEventName(string eventName) {
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
	//operator<<
	friend ostream& operator<<(ostream& out, Event&);
	
   friend istream& operator>>(istream& in, Event );

};
ostream& operator<<(ostream& out, Event& e) {
	out << e.eventName << endl;
	out << e.location << endl;
	return out;
}
istream& operator>>(istream& in, Event e) {
	cout << "Enter event name: ";
	in >> e.eventName;
	cout << "Enter location: ";
	in >> e.location;
	return in;
}
int main() {
	//TICKET
	// Object created based on the default constructor without parameters
	Ticket t;
	cout << "Ticket ID: " << t.getTicketId() << endl;
	cout << "Row Number: " << t.getRowNumber() << endl;
	cout << "Seat Number: " << t.getSeatNumber() << endl;
	cout << "Is Reserved: " << t.getIsReserved() << endl;

	t.setRowNumer(4);
	t.setSeatNumber(27);
	t.setIsReserved(true);
	cout << endl << endl;
	cout << "Ticket ID: " << t.getTicketId() << endl;
	cout << "Row Number: " << t.getRowNumber() << endl;
	cout << "Seat Number: " << t.getSeatNumber() << endl;
	cout << "Is Reserved: " << t.getIsReserved() << endl;
	cout << endl<<endl;
	// Object created based on the constructor with parameters
	Ticket t1("A1234", 4, 56, false);
	//copy constructor
	Ticket t2 = t1;
	cout << "Ticket ID: " << t2.getTicketId() << endl;
	cout << "Row Number: " << t2.getRowNumber() << endl;
	cout << "Seat Number: " << t2.getSeatNumber() << endl;
	cout << "Is Reserved: " << t2.getIsReserved() << endl;
	cout << endl<<endl;
	//operator=
	t1 = t;
	cout << "Ticket ID: " << t1.getTicketId() << endl;
	cout << "Row Number: " << t1.getRowNumber() << endl;
	cout << "Seat Number: " << t1.getSeatNumber() << endl;
	cout << "Is Reserved: " << t1.getIsReserved() << endl;
	cout << endl<<endl;

	//operator !
	Ticket myTicket("123", 5, 10, false);
	if (!myTicket) {
		cout << "This ticket is not reserved." << endl;
	}
	else {
		cout << "This ticket is reserved." << endl;
	}
	cout << endl << endl;
	//cast operator 
	Ticket myticket("456", 7, 15, true);
	int seatNumber = myticket; 
	cout << "Seat Number: " << seatNumber << endl;
	cout << endl << endl;
	//ZONE
	
	Zone z;
	cout << "Max Row Number: "<<z.getMaxRowNumber() << endl;
	cout <<"Max Seats number: "<< z.getMaxSeatsPerRow() << endl;
	cout <<"Number of Tickets: "<<z.getNumberOfTickets() << endl;
	cout <<"Ticket : "<<z.getTicket() << endl;
	z.setMaxRowNumber(10);
	z.setMaxSeatsPerRow(20);
	z.setNumberOfTickets(100);
	cout << endl << endl;
	cout << "Max Row Number: " << z.getMaxRowNumber() << endl;
	cout << "Max Seats number: " << z.getMaxSeatsPerRow() << endl;
	cout << "Number of Tickets: " << z.getNumberOfTickets() << endl;
	cout << "Ticket : " << z.getTicket() << endl;
	cout << endl << endl;
	
	Ticket* ticketArray = new Ticket[100];  // Make sure to allocate and initialize Ticket objects

	// Creating a Zone object with the provided parameters
	Zone myZone(10, 20, 100, ticketArray);

    // Operator ! usage
    if (!myZone) {
        cout << "This zone has no tickets." << endl;
    } else {
        cout << "This zone has tickets." << endl;
    }
	
	// Operator ! 
	if (!myZone) {
		cout << "This zone has no tickets." << endl;
	}
	else {
		cout << "This zone has tickets." << endl;
	}
	cout << endl << endl;
	 // Operator int() 
	int totalTickets = myZone;
	cout << "Total number of tickets in this zone: " << totalTickets << endl;
	cout << endl << endl;
	//Location
	Location l;
	cout << "Name: " << l.getName() << endl;
	cout <<"Maximum Capacity: " <<l.getMaximumCapacity() << endl;
	cout << "Number of Zones: "<<l.getNumberOfZones() << endl;
	
	l.setName("Carol Davila");
	l.setMaximumCapacity(200);
	l.setNumberOfZones(3);
	cout << endl << endl;
	cout << "Name: " << l.getName() << endl;
	cout << "Maximum Capacity: " << l.getMaximumCapacity() << endl;
	cout << "Number of Zones: " << l.getNumberOfZones() << endl;
	cout << endl << endl;
	return 0;

}