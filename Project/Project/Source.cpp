#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Location {
	int maxSeats;
	int noRows;
	string locationName;

public:
	Location() {
		this->maxSeats = 0;
		this->noRows = 0;
		this->locationName = "";
	}

	void readLocationCharacteristics() {
		cout << "Enter location characteristics:\n";
		cout << "Location Name: ";
		getline(cin, locationName);
		cout << "Maximum Number of Seats: ";
		cin >> maxSeats;
		cout << "Number of Rows: ";
		cin >> noRows;
		cin.ignore();
	}

	// Accessor methods
	int getMaxSeats() const {
		return this->maxSeats;
	}

	int getNoRows() const {
		return this->noRows;
	}

	string getLocationName() const {
		return this->locationName;
	}
};

class Event {
	string eventName;
	string eventDate;
	string eventTime;
	static int totalEvents;

public:
	Event() {
		this->eventName = "";
		this->eventDate = "";
		this->eventTime = "";
		totalEvents++;
	}

	void readEventCharacteristics() {
		cout << "Enter event characteristics:\n";
		cout << "Event Name: ";
		getline(cin, eventName);
		cout << "Event Date: ";
		getline(cin, eventDate);
		cout << "Event Time: ";
		getline(cin, eventTime);
	}

	// Accessor methods
	string getEventName() const {
		return this->eventName;
	}

	string getEventDate() const {
		return this->eventDate;
	}

	string getEventTime() const {
		return this->eventTime;
	}

	// Static field accessor
	static int getTotalEvents() {
		return totalEvents;
	}
};


int Event::totalEvents = 0;

class Ticket {
	string ticketType;
	const string ticketID; // Constant field
	static int totalTickets;

public:
	Ticket() : ticketType(""), ticketID("") {
		totalTickets++;
	}

	Ticket(const string& type) : ticketType(type), ticketID(generateTicketID()) {
		totalTickets++;
	}

	// Generating a random ticket ID
	string generateTicketID() {
		time_t currentTime = time(nullptr);
		srand(static_cast<unsigned>(currentTime));
		int randomNum = rand() % 1000;

		return to_string(currentTime) + to_string(randomNum);
	}

	// Accessor methods
	string getTicketType() const {
		return this->ticketType;
	}

	string getTicketID() const {
		return this->ticketID;
	}

	// Static field accessor
	static int getTotalTickets() {
		return totalTickets;
	}
};


int Ticket::totalTickets = 0;

int main() {
	Location location;
	Event event;

	location.readLocationCharacteristics();
	event.readEventCharacteristics();

	int numTickets;
	cout << "Enter the number of tickets to generate: ";
	cin >> numTickets;
	cin.ignore();

	for (int i = 0; i < numTickets; ++i) {
		string ticketType;
		cout << "Enter ticket type for ticket " << i + 1 << ": ";
		getline(cin, ticketType);

		Ticket ticket(ticketType);

		// Display ticket information
		cout << "\nTicket Information:\n";
		cout << "Location: " << location.getLocationName() << "\n";
		cout << "Event: " << event.getEventName() << "\n";
		cout << "Date and Time: " << event.getEventDate() << " " << event.getEventTime() << "\n";
		cout << "Ticket Type: " << ticket.getTicketType() << "\n";
		cout << "Ticket ID: " << ticket.getTicketID() << "\n";
	}

	cout << "\nTotal Events: " << Event::getTotalEvents() << endl;
	cout << "Total Tickets: " << Ticket::getTotalTickets() << endl;

	return 0;
}
