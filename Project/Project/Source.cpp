#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<fstream>
#include<vector>

using namespace std;

class BinaryFilesClass {
public:
	virtual void serialization(string filename) = 0;
	virtual void deserialization(string filename) = 0;

};


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
	Location(int maxSeats, int noRows, const char* locationName, int* seatsPerRow)
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
			if (this->locationName != nullptr) {
				delete[]this->locationName;
			}
			for (int i = 0; i < this->noRows; i++) {
				this->seatsPerRow[i] = l.seatsPerRow[i];
			}
			delete[] this->locationName;
			this->locationName = new char[strlen(l.locationName) + 1];
			strcpy(this->locationName, l.locationName);
		}
		return *this;
	}
	// Generic Method 1: Calculate Total Seats
	int calculateTotalSeats() const {
		return maxSeats * noRows;
	}

	//// Generic Method 2: Display Seat Configuration
	void displaySeatConfiguration() const {
		cout << "Seat Configuration:\n";
		for (int i = 0; i < noRows; ++i) {
			cout << "Row " << i + 1 << ": " << seatsPerRow[i] << " seats\n";
		}
	}
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
	//	//cin >> maxSeats;
	//	cout << "Number of Rows: ";
	//	//cin >> noRows;
	//	// Allocate memory for seatsPerRow
	//	if (this->seatsPerRow != nullptr) {
	//		delete[] this->seatsPerRow;
	//	}
	//	this->seatsPerRow = new int[noRows];

	//	// Read seats per row
	//	for (int i = 0; i < noRows; ++i) {
	//		cout << "Number of Seats in Row " << i + 1 << ": ";
	//		//cin >> seatsPerRow[i];
	//	}
	//	cin.ignore();
	//}
	// Overloading  operator (<<)
	friend ostream& operator<<(ostream& out, const Location& location);

	// Overloading stream extraction operator (>>)
	friend istream& operator>>(istream& in, Location& location);


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
		if (maxSeats > 0) {
			this->maxSeats = maxSeats;
		}
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
	void setNoRows(int noRows) {
		this->noRows = noRows;
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

		if (index >= 0 && index < noRows) {
			// Return the number of seats in the specified row
			return seatsPerRow[index];
		}
		else {


			cout << "Error: Invalid row index\n";
			return -1;// returning -1 indicating an error
		}
	}

	// Method to set the number of seats in a specific row
	void setSeatsInRow(int index, int seats) {

		if (index >= 0 && index < noRows) {

			seatsPerRow[index] = seats;
		}
		else {

			cout << "Error: Invalid row index\n";
		}
	}
};

ostream& operator<<(ostream& out, const Location& location) {
	out << "Location Information:\n";
	out << "Name: " << location.locationName << "\n";
	out << "Max Seats: " << location.maxSeats << "\n";
	out << "Number of Rows: " << location.noRows << "\n";
	out << "Seat Configuration:\n";
	for (int i = 0; i < location.noRows; ++i) {
		out << "Row " << i + 1 << ": " << location.seatsPerRow[i] << " seats\n";
	}
	return out;
}
istream& operator>>(istream& in, Location& location) {
	cout << "Enter location characteristics:\n";
	cout << "Location Name: ";
	string tempLocationName;
	getline(in, tempLocationName);
	if (location.locationName != nullptr) {
		delete[] location.locationName;
	}
	location.locationName = new char[tempLocationName.length() + 1];
	strcpy(location.locationName, tempLocationName.data());
	cout << "Maximum Number of Seats: ";
	in >> location.maxSeats;
	cout << "Number of Rows: ";
	in >> location.noRows;

	// Allocate memory for seatsPerRow
	if (location.seatsPerRow != nullptr) {
		delete[] location.seatsPerRow;
	}
	location.seatsPerRow = new int[location.noRows];

	// Read seats per row
	for (int i = 0; i < location.noRows; ++i) {
		cout << "Number of Seats in Row " << i + 1 << ": ";
		in >> location.seatsPerRow[i];
	}

	in.ignore();  // Ignore newline character

	return in;
}



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
	//destructor
	~Event() {

		// Decrement the total event count upon destruction of an event
		totalEvents--;
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
		if (eventName.size() > 2) {
			this->eventName = eventName;
		}
	}
	void setEventDate(string eventDate) {
		if (eventDate.size() > 4) {
			this->eventDate = eventDate;
		}
	}
	void setEventTime(string eventTime) {
		if (eventTime.size() > 0) {
			this->eventTime = eventTime; \
		}
	}
	//  Method to update Event Information
	void updateEventInformation(string newEventName, string newEventDate, string newEventTime) {

		this->eventName = newEventName;
		this->eventDate = newEventDate;
		this->eventTime = newEventTime;
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
	friend ostream& operator<<(ostream& out, const Event& event);

	// Overloading stream extraction operator (>>)
	friend istream& operator>>(istream& in, Event& event);
};


int Event::totalEvents = 0;

ostream& operator<<(ostream& out, const Event& event) {
	out << "Event Information:\n";
	out << "Name: " << event.eventName << "\n";
	out << "Date (YYYY-MM-DD): " << event.eventDate << "\n";
	out << "TimeHH:MM) : " << event.eventTime << "\n";
	return out;
}
istream& operator>>(istream& in, Event& event) {

	cout << "Enter Event Name: ";
	getline(in, event.eventName);
	cout << "Enter Event Date (YYYY-MM-DD): ";
	getline(in, event.eventDate);
	cout << "Enter Event Time(HH:MM): ";
	getline(in, event.eventTime);
	return in;
}


class Ticket : public BinaryFilesClass {
	string ticketType;
	const string ticketID;
	static int totalTickets;

public:
	Ticket() : ticketID(generateTicketID()) {
		this->ticketType = "N/A";
		totalTickets++;
	}

	Ticket(string ticketType) : ticketID(generateTicketID()) {
		this->ticketType = ticketType;
		totalTickets++;
	}
	//destructor
	~Ticket() {

		// Decrement total tickets count
		totalTickets--;
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
		if (ticketType.size() > 3) {
			this->ticketType = ticketType;
		}
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

		result.ticketType = "Canceled_" + ticketType;

		return result;
	}
	// the negation operator creates a new ticket with a ticket type that represents a canceled or invalid ticket. 
	//2 
	// Overloading the Subtraction Operator (-)
	Ticket operator-(const Ticket& other) const {
		Ticket result;

		result.ticketType = ticketType + "_Combined_" + other.ticketType;

		return result;
	}


	// Overloading stream insertion operator (<<)
	friend ostream& operator<<(ostream& out, const Ticket& ticket);

	// Overloading stream extraction operator (>>)
	friend istream& operator>>(istream& in, Ticket& ticket);


	void serialization(string filename) {
		ofstream outFile(filename, ios::out | ios::binary);
		int typeLength = this->ticketType.size();
		outFile.write((char*)&typeLength, sizeof(typeLength));
		outFile.write(this->ticketType.c_str(), typeLength + 1);


		outFile.close();
	}
	void deserialization(string filename) {
		ifstream outFile(filename, ios::in | ios::binary);
		if (outFile.is_open())
		{

			int typeLength = 0;
			outFile.read((char*)&typeLength, sizeof(typeLength));
			char* aux = new char[typeLength + 1];
			outFile.read(aux, typeLength + 1);
			this->ticketType = aux;
			delete[]aux;
		}
	}
};

int Ticket::totalTickets = 0;
ostream& operator<<(ostream& out, const Ticket& ticket) {
	out << "Ticket Type: " << ticket.ticketType << ", Ticket ID: " << ticket.ticketID;
	return out;
}
istream& operator>>(istream& in, Ticket& ticket) {
	cout << "Enter Ticket Type: ";
	in >> ticket.ticketType;
	return in;
}



class Concert : public Event {
	string headliningArtist;
	string genre;

public:
	// Default constructor
	Concert() : Event(), headliningArtist(""), genre("") {}

	// Parameterized Constructor
	Concert(string eventName, string eventDate, string eventTime,
		string headliningArtist, string genre)
		: Event(eventName, eventDate, eventTime), headliningArtist(headliningArtist),
		genre(genre) {}

	// Accessor and mutator methods for the new attributes
	string getHeadliningArtist() const { return headliningArtist; }
	void setHeadliningArtist(const string& artist) { headliningArtist = artist; }

	string getGenre() const { return genre; }
	void setGenre(const string& genre) { this->genre = genre; }

	// Overriding display method to include concert-specific details
	void display() {
		Event::display(); // Calling the base class version of display
		cout << "Headlining Artist: " << headliningArtist << "\n";
		cout << "Genre: " << genre << "\n";
	}
	friend ostream& operator<<(ostream& out, const Concert& concert);
	friend istream& operator>>(istream& in, Concert& concert);
};
ostream& operator<<(ostream& out, const Concert& concert) {
	out << static_cast<const Event&>(concert); // Utilize Event's operator<<
	out << "Headlining Artist: " << concert.getHeadliningArtist() << endl;
	out << "Genre: " << concert.getGenre() << endl;
	return out;
}

istream& operator>>(istream& in, Concert& concert) {
	in >> static_cast<Event&>(concert); // Utilize Event's operator>>
	cout << "Headlining Artist: ";
	string headliningArtist;
	getline(in, headliningArtist);
	concert.setHeadliningArtist(headliningArtist);

	cout << "Genre: ";
	string genre;
	getline(in, genre);
	concert.setGenre(genre);
	return in;
}



class Manageable {
	vector<Ticket> tickets;
public:
	Manageable() {

	}

	Manageable(int noTickets, Ticket* tickets) {
		for (int i = 0; i < noTickets; i++) {
			this->tickets.push_back(tickets[i]);
		}
	}

	Manageable(const Manageable& m) {
		for (int i = 0; i < m.tickets.size(); i++) {
			this->tickets.push_back(m.tickets[i]);
		}
	}

	Manageable& operator=(const Manageable& m) {
		if (this != &m) {
			this->tickets.clear();
			for (int i = 0; i < m.tickets.size(); i++) {
				this->tickets.push_back(m.tickets[i]);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Manageable& m) {
		out << "----------------------------------" << endl;
		out << "Tickets:" << endl << endl;
		for (int i = 0; i < m.tickets.size(); i++) {
			out << m.tickets[i] << endl;
		}
		out << "----------------------------------" << endl;
		return out;
	}

	~Manageable() {

	}

	void addTicket(Ticket t) {
		this->tickets.push_back(t);
	}
};


void menu() {
	cout << "===== Menu =====" << endl;
	cout << "1. Create your event location" << endl;
	cout << "2. Create the Event" << endl;
	cout << "3. Generate nominal tickets" << endl;
	cout << "4. Display generated tickets" << endl;
	cout << "5. Exit" << endl;

}


int main() {

	// Location characteristics
	Location location;
	cout << "Enter characteristics of the location:\n";
	//cin >> location;

	// Event characteristics
	Event event;
	cout << "Enter characteristics of the event:\n";
	//cin >> event;

	// Generate nominal tickets as strings
	int numTickets = 1;
	cout << "Enter the number of tickets to generate: ";
	//cin >> numTickets;

	string ticketsString; // Concatenate generated tickets as strings
	for (int i = 0; i < numTickets; ++i) {
		Ticket ticketType;
		cout << "Enter ticket type for Ticket " << i + 1 << " (VIP, Lawn, Tribune, Box, etc.): ";
		//cin >> ticketType;


		Ticket ticket(ticketType);


		ticketsString += "Ticket Type: " + ticket.getTicketType() + ", Ticket ID: " + ticket.getTicketID() + "\n";
	}

	// Display generated tickets
	cout << "\nGenerated Tickets:\n" << ticketsString;

	// Validate issued tickets
	string enteredTicketID;
	cout << "\nEnter a ticket ID to validate (or 'exit' to end): ";
	//cin >> enteredTicketID;

	//while (enteredTicketID != "exit") {

	//	size_t found = ticketsString.find("Ticket ID: " + enteredTicketID);
	//	if (found != string::npos) {
	//		cout << "Ticket is now valid!\n";
	//	}
	//	else {
	//		cout << "Ticket does not exist!\n";
	//	}


	//	cout << "\nEnter another ticket ID to validate (or 'exit' to end): ";
	//	//cin >> enteredTicketID;
	//}

	// Location characteristics

	//cin.ignore();

	Event event1;
	cout << "Enter characteristics of the first event:\n";
	//cin >> event1;

	Event event2;
	cout << "Enter characteristics of the second event:\n";
	//cin >> event2;

	// Using the equality operator (==) for events
	if (event1 == event2) {
		cout << "The two events are the same.\n";
	}
	else {
		cout << "The two events are different.\n";
	}
	//testing operators
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

	int seatsnr[5] = { 20, 25, 30, 25, 20 };

	Location location1(100, 5, "Teatrul X", seatsnr);

	// Accessing and using the indexing operator []
	int seatsInRow3 = location1[2];  // Accessing seats in row 3 index 2

	// Checking if an error occurred during indexing
	if (seatsInRow3 != -1) {
		cout << "Number of seats in Row 3: " << seatsInRow3 << endl;
	}
	int seatsInInvalidRow = location1[10];  //  displays an error message

	string concertName, concertDate, concertTime, headliningArtist, genre;
	cout << "Enter characteristics of the concert:\n";
	cout << "Concert Name: ";
	//cin.ignore(); // Clearing the newline character left in the stream after the previous cin
	//getline(cin, concertName);
	cout << "Concert Date (YYYY-MM-DD): ";
	//getline(cin, concertDate);
	cout << "Concert Time (HH:MM): ";
	//getline(cin, concertTime);
	cout << "Headlining Artist: ";
	//getline(cin, headliningArtist);
	cout << "Genre: ";
	//getline(cin, genre);

	Concert concert(concertName, concertDate, concertTime, headliningArtist, genre);

	// Display concert information
	cout << "\nConcert Details:\n";
	concert.display();
	cout << "\n";




	//Binary files
	cout << "======================" << endl;
	cout << "Binary files " << endl;
	Ticket t1;
	t1.serialization("exampleBinFile.bin");
	cout << "The object is written in the binary file" << endl;
	Ticket binaryT;
	binaryT.deserialization("exampleBinFile.bin");
	cout << binaryT << endl;
	cout << "======================" << endl;
	cout << "======================" << endl;
	cout << "======================" << endl;
	cout << "======================" << endl;
	Manageable m;
	cout << m << endl;

	Ticket vTicket[3] = { originalTicket, t1,otherTicket };

	Manageable m1(3, vTicket);
	cout << m1 << endl;
	m1.addTicket(originalTicket);
	cout << m1 << endl;

	cout << endl << endl << endl << endl;

	int option;
	do {
		cout << endl << endl << endl << endl;

		menu();
		cout << "Select an option: ";
		cin >> option;

		switch (option) {
		case 1:
			cout << "Enter characteristics of the location:\n";
			cin >> location;
			break;
		case 2:
			cout << "Enter characteristics of the event:\n";
			cin >> event;
			break;
		case 3:
			cout << "Enter the number of tickets to generate: ";
			cin >> numTickets;
			break;
		case 4:
			for (int i = 0; i < numTickets; ++i) {
				Ticket ticketType;
				cout << "Enter ticket type for Ticket " << i + 1 << " (VIP, Lawn, Tribune, Box, etc.): ";
				cin >> ticketType;


				Ticket ticket(ticketType);


				ticketsString += "Ticket Type: " + ticket.getTicketType() + ", Ticket ID: " + ticket.getTicketID() + "\n";
			}

			// Display generated tickets
			cout << "\nGenerated Tickets:\n" << ticketsString;
			break;
		case 5:
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "Invalid option. Please select a valid option." << endl;
		}

		if (option != 5) {
			char choice;
			cout << "Do you want to continue? (y/n): ";
			cin >> choice;

			if (tolower(choice) != 'y') {
				break; // Exit the loop if the user doesn't want to continue
			}
		}

	} while (option != 5);



}
//https://github.com/tanaseroberta/cppproject