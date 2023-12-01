#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Location {
	int maxSeats;
	int noRows;
	int* seatsPerRow;
	char* locationName;

public:
	Location() {
		this->maxSeats = 0;
		this->noRows = 0;
		this->seatsPerRow = nullptr;
		this->locationName = new char[strlen("") + 1];
		strcpy(this->locationName, "");
	}
	//constructor with parameters
	Location(int maxSeats, int noRows, const char* locationName)
	{
		this->maxSeats = maxSeats;
		this->noRows = noRows;
		this->seatsPerRow = new int[this->noRows];
		for (int i = 0; i < this->noRows; i++) {
			this->seatsPerRow[i] = seatsPerRow[i];
		}
		this->locationName = new char[strlen(locationName) + 1];
		strcpy(this->locationName, locationName);
	}
	//destructor
	~Location() {
		if (this->seatsPerRow != nullptr) {
			delete[]this->seatsPerRow;
		}
		if (this->locationName != nullptr) {
			delete[]this->locationName;
		}
	}
	// Copy constructor
	Location(const Location& l) {
		this->maxSeats = l.maxSeats;
		this->noRows = l.noRows;
		this->seatsPerRow = new int[this->noRows];
		for (int i = 0; i < this->noRows; i++) {
			this->seatsPerRow[i] = l.seatsPerRow[i];
		}
		this->locationName = new char[strlen(l.locationName) + 1];
		strcpy(this->locationName, l.locationName);
	}
	// Assignment operator
	Location& operator=(const Location& l) {
		if (this != &l) {
			this->maxSeats = l.maxSeats;
			this->noRows = l.noRows;
			delete[]this->seatsPerRow;
			this->seatsPerRow = new int[this->noRows];
			for (int i = 0; i < this->noRows; i++) {
				this->seatsPerRow[i] = l.seatsPerRow[i];
			}
			delete[] this->locationName;
			this->locationName = new char[strlen(l.locationName) + 1];
			strcpy(this->locationName, l.locationName);
		}
		return *this;
	}
	//// Generic Method 1: Calculate Total Seats
	//	int calculateTotalSeats() const {
	//	return maxSeats * noRows;
	//}

	//// Generic Method 2: Display Seat Configuration
	//void displaySeatConfiguration() const {
	//	cout << "Seat Configuration:\n";
	//	for (int i = 0; i < noRows; ++i) {
	//		cout << "Row " << i + 1 << ": " << seatsPerRow[i] << " seats\n";
	//	}
	//}
	////method that reads location characteristics
	//void readLocationCharacteristics() {
	//	cout << "Enter location characteristics:\n";
	//	cout << "Location Name: ";
	//	string tempLocationName;
	//	getline(cin, tempLocationName);
	//	if (this->locationName != nullptr) {
	//		delete[]this->locationName;
	//	}
	//	locationName= new char[tempLocationName.length() + 1];
	//	strcpy(locationName, tempLocationName.data());
	//	cout << "Maximum Number of Seats: ";
	//	cin >> maxSeats;
	//	cout << "Number of Rows: ";
	//	cin >> noRows;
	//	// Allocate memory for seatsPerRow
	//	if (this->seatsPerRow != nullptr) {
	//		delete[] this->seatsPerRow;
	//	}
	//	this->seatsPerRow = new int[noRows];

	//	// Read seats per row
	//	for (int i = 0; i < noRows; ++i) {
	//		cout << "Number of Seats in Row " << i + 1 << ": ";
	//		cin >> seatsPerRow[i];
	//	}
	//	cin.ignore();
	//}
	// Overloading stream insertion operator (<<)
	friend ostream& operator<<(ostream& os, const Location& location) {
		os << "Location Information:\n";
		os << "Name: " << location.locationName << "\n";
		os << "Max Seats: " << location.maxSeats << "\n";
		os << "Number of Rows: " << location.noRows << "\n";
		os << "Seat Configuration:\n";
		for (int i = 0; i < location.noRows; ++i) {
			os << "Row " << i + 1 << ": " << location.seatsPerRow[i] << " seats\n";
		}
		return os;
	}

	// Overloading stream extraction operator (>>)
	friend istream& operator>>(istream& is, Location& location) {
		cout << "Enter location characteristics:\n";
		cout << "Location Name: ";
		string tempLocationName;
		getline(is, tempLocationName);
		if (location.locationName != nullptr) {
			delete[] location.locationName;
		}
		location.locationName = new char[tempLocationName.length() + 1];
		strcpy(location.locationName, tempLocationName.data());
		cout << "Maximum Number of Seats: ";
		is >> location.maxSeats;
		cout << "Number of Rows: ";
		is >> location.noRows;

		// Allocate memory for seatsPerRow
		if (location.seatsPerRow != nullptr) {
			delete[] location.seatsPerRow;
		}
		location.seatsPerRow = new int[location.noRows];

		// Read seats per row
		for (int i = 0; i < location.noRows; ++i) {
			cout << "Number of Seats in Row " << i + 1 << ": ";
			is >> location.seatsPerRow[i];
		}

		is.ignore();  // Ignore newline character

		return is;
	}


	// Accessor methods
	//getters
	int getMaxSeats() {
		return this->maxSeats;
	}

	int getNoRows() {
		return this->noRows;
	}
	int* getSeatsPerRow() {
		return this->seatsPerRow;
	}
	char* getLocationName() {
		return this->locationName;
	}
	//setters
	void setMaxSeats(int maxSeats) {
		this->maxSeats = maxSeats;
	}

	void setSeatsPerRow(int* seatsPerRow, int noRows) {
		if (this->seatsPerRow != nullptr) {
			delete[]this->seatsPerRow;
		}
		if (this->noRows > 0 && this->seatsPerRow != nullptr) {
			this->noRows = noRows;
			this->seatsPerRow = new int[this->noRows];
			for (int i = 0; i < this->noRows; i++) {
				this->seatsPerRow[i] = seatsPerRow[i];
			}
		}
		else {
			this->noRows = 0;
			this->seatsPerRow = nullptr;
		}
	}
	void setLocationName(const char* locationName) {
		if (this->seatsPerRow != nullptr) {
			delete[]this->seatsPerRow;
		}
		this->locationName = new char[strlen(locationName) + 1];
		strcpy(this->locationName, locationName);
	}

	// Overloading indexing operator []
	int operator[](int index) const {
		// Check if index is within bounds
		if (index >= 0 && index < noRows) {
			// Return the number of seats in the specified row
			return seatsPerRow[index];
		}
		else {
			// Handle out-of-bounds access
			// For simplicity, returning -1 indicating an error
			cout << "Error: Invalid row index\n";
			return -1;
		}
	}

	// Method to set the number of seats in a specific row
	void setSeatsInRow(int index, int seats) {
		// Check if index is within bounds
		if (index >= 0 && index < noRows) {
			// Set the number of seats in the specified row
			seatsPerRow[index] = seats;
		}
		else {
			// Handle out-of-bounds access
			cout << "Error: Invalid row index\n";
		}
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
	//constructor with parameteres
	Event(string eventName, string eventDate, string eventTime) {
		this->eventName = eventName;
		this->eventDate = eventDate;
		this->eventTime = eventTime;
		totalEvents++;
	}
	//copy constructor
	Event(const Event& e)
	{
		this->eventName = e.eventName;
		this->eventDate = e.eventDate;
		this->eventTime = e.eventTime;


	}
	//assignment 
	Event& operator=(const Event& e) {
		if (this != &e) {
			this->eventName = e.eventName;
			this->eventDate = e.eventDate;
			this->eventTime = e.eventTime;

			return *this;

		}
	}


	//void readEventCharacteristics() {
	//	cout << "Enter event characteristics:\n";
	//	cout << "Event Name: ";
	//	getline(cin, eventName);
	//	cout << "Event Date: ";
	//	getline(cin, eventDate);
	//	cout << "Event Time: ";
	//	getline(cin, eventTime);
	//}
	//// Generic Method 1: Display Event Details
	//void displayEventDetails() const {
	//	cout << "Event Details:\n";
	//	cout << "Name: " << eventName << "\n";
	//	cout << "Date: " << eventDate << "\n";
	//	cout << "Time: " << eventTime << "\n";
	//}

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
	//setters

	void setEventName(string getEventName) {
		this->eventName = eventName;
	}
	void setEventDate(string eventDate) {
		this->eventDate = eventDate;
	}
	void setEventTime(string eventTime) {
		this->eventTime = eventTime;
	}
	// Method to check if the event time is within working hours
	bool isEventTimeValid() const {
		// Assuming working hours are from 9 AM to 5 PM
		const string workingHoursStart = "09:00";
		const string workingHoursEnd = "17:00";

		// Extract hours and minutes from the event time
		string eventHoursStr = getEventTime().substr(0, 2);
		string eventMinutesStr = getEventTime().substr(3, 2);
		int eventHours = stoi(eventHoursStr);
		int eventMinutes = stoi(eventMinutesStr);

		// Extract hours and minutes from working hours start and end
		int startHours = stoi(workingHoursStart.substr(0, 2));
		int startMinutes = stoi(workingHoursStart.substr(3, 2));
		int endHours = stoi(workingHoursEnd.substr(0, 2));
		int endMinutes = stoi(workingHoursEnd.substr(3, 2));

		// Check if the event time is within working hours
		if (eventHours > startHours || (eventHours == startHours && eventMinutes >= startMinutes)) {
			if (eventHours < endHours || (eventHours == endHours && eventMinutes <= endMinutes)) {
				return true;
			}
		}

		return false;
	}

	//1. Overloading addition operator +
	Event operator+(const Event& other) const {
		Event result;


		result.eventName = this->eventName + " & " + other.eventName;
		result.eventDate = this->eventDate + " & " + other.eventDate;
		result.eventTime = this->eventTime + " & " + other.eventTime;

		return result;
	}

	//2. Overloading relational operator ==
	bool operator==(const Event& other) {
		return eventName == other.eventName && eventDate == other.eventDate && eventTime == other.eventTime;
	}
	// Display Event information
	void display() {
		cout << "Event Information:\n";
		cout << "Name: " << eventName << "\n";
		cout << "Date: " << eventDate << "\n";
		cout << "Time: " << eventTime << "\n";
	}
	friend ostream& operator<<(ostream& os, const Event& event) {
		os << "Event Information:\n";
		os << "Name: " << event.eventName << "\n";
		os << "Date: " << event.eventDate << "\n";
		os << "Time: " << event.eventTime << "\n";
		return os;
	}

	// Overloading stream extraction operator (>>)
	friend istream& operator>>(istream& is, Event& event) {

		cout << "Enter Event Name: ";
		getline(is, event.eventName);
		cout << "Enter Event Date: ";
		getline(is, event.eventDate);
		cout << "Enter Event Time: ";
		getline(is, event.eventTime);
		return is;
	}
};


int Event::totalEvents = 0;

class Ticket {
	string ticketType;
	const string ticketID; // Constant field
	static int totalTickets;

public:
	Ticket() : ticketID(generateTicketID()) {
		this->ticketType = "";
		totalTickets++;
	}

	Ticket(string ticketType) : ticketID(generateTicketID()) {
		this->ticketType = ticketType;
		totalTickets++;
	}

	// Generating a random ticket ID
	string generateTicketID() {

		int randomNum = rand() % 1000;

		return to_string(randomNum);
	}
	// Generic Method 1: Display Ticket Information
	void displayTicketInformation() const {
		cout << "Ticket Information:\n";
		cout << "Type: " << ticketType << "\n";
		cout << "ID: " << ticketID << "\n";
	}
	// Accessor methods
	string getTicketType() {
		return this->ticketType;
	}

	const string getTicketID() {
		return this->ticketID;
	}

	// Static field accessor
	static int getTotalTickets() {
		return totalTickets;
	}
	void setTicketType(string ticketType) {
		this->ticketType = ticketType;
	}
	// Static method to set totalTickets
	static void setTotalTickets(int newValue) {
		totalTickets = newValue;
	}
	// Function to convert a substring to an integer
	int stoi(const string& str, size_t start, size_t end) {
		int result = 0;
		for (size_t i = start; i < end; ++i) {
			result = result * 10 + (str[i] - '0');
		}
		return result;
	}

	// Function to extract hours and minutes from a time string
	bool extractTime(const string& timeStr, int& hours, int& minutes) {
		size_t colonPos = timeStr.find(':');
		if (colonPos == string::npos) {
			return false;  // Colon not found
		}

		// Extract hours and minutes from substrings
		hours = stoi(timeStr, 0, colonPos);
		minutes = stoi(timeStr, colonPos + 1, timeStr.size());

		return true;
	}
	//1 
	// Overloading the Negation Operator (!)
	Ticket operator!() const {
		Ticket result(*this);

		result.ticketType += "_negated";

		return result;
	}
	//2 
	// Overloading the Subtraction Operator (-)
	Ticket operator-(const Ticket& other) const {
		Ticket result;
		result.ticketType = ticketType + "_subtracted_" + other.ticketType;

		return result;
	}

	// Overloading stream insertion operator (<<)
	friend ostream& operator<<(ostream& os, const Ticket& ticket) {
		os << "Ticket Type: " << ticket.ticketType << ", Ticket ID: " << ticket.ticketID;
		return os;
	}

	// Overloading stream extraction operator (>>)
	friend istream& operator>>(istream& is, Ticket& ticket) {
		cout << "Enter Ticket Type: ";
		is >> ticket.ticketType;
		return is;
	}

};

int Ticket::totalTickets = 0;



int main() {
	// Location characteristics
	Location location;
	cout << "Enter characteristics of the location:\n";
	cin >> location;

	// Event characteristics
	Event event;
	cout << "Enter characteristics of the event:\n";
	cin >> event;

	// Generate nominal tickets as strings
	int numTickets;
	cout << "Enter the number of tickets to generate: ";
	cin >> numTickets;

	string ticketsString; // Concatenate generated tickets as strings
	for (int i = 0; i < numTickets; ++i) {
		Ticket ticketType;
		cout << "Enter ticket type for Ticket " << i + 1 << " (VIP, Lawn, Tribune, Box, etc.): ";
		cin >> ticketType;

		// You can customize the ticket type based on your requirements
		// For simplicity, just setting the ticket type as entered by the user
		Ticket ticket(ticketType);

		// Concatenate the ticket information to the string
		ticketsString += "Ticket Type: " + ticket.getTicketType() + ", Ticket ID: " + ticket.getTicketID() + "\n";
	}

	// Display generated tickets
	cout << "\nGenerated Tickets:\n" << ticketsString;

	// Validate issued tickets
	string enteredTicketID;
	cout << "\nEnter a ticket ID to validate (or 'exit' to end): ";
	cin >> enteredTicketID;

	while (enteredTicketID != "exit") {
		// Validate the entered ticket ID (search in the concatenated string)
		size_t found = ticketsString.find("Ticket ID: " + enteredTicketID);
		if (found != string::npos) {
			cout << "Ticket is now valid!\n";
		}
		else {
			cout << "Ticket does not exist!\n";
		}

		// Prompt for the next ticket ID
		cout << "\nEnter another ticket ID to validate (or 'exit' to end): ";
		cin >> enteredTicketID;
	}
	/////
	// Location characteristics

	cin.ignore();
	// Event characteristics
	Event event1;
	cout << "Enter characteristics of the first event:\n";
	cin >> event1;

	Event event2;
	cout << "Enter characteristics of the second event:\n";
	cin >> event2;

	// Using the equality operator (==) for events
	if (event1 == event2) {
		cout << "The two events are the same.\n";
	}
	else {
		cout << "The two events are different.\n";
	}

	// Using the negation operator (!) for tickets
	Ticket originalTicket("Regular");
	Ticket negatedTicket = !originalTicket;

	// Using the subtraction operator (-) for tickets
	Ticket otherTicket("VIP");
	Ticket subtractedTicket = originalTicket - otherTicket;

	// Displaying information
	cout << "\nOriginal Ticket:\n" << originalTicket << "\n";
	cout << "Negated Ticket:\n" << negatedTicket << "\n";
	cout << "Subtracted Ticket:\n" << subtractedTicket << "\n";

	return 0;
}
