// Workshop 5 - Containers
// Notifications.cpp
// Jay Ansin  |  123 08 1150  |  cansin@myseneca.ca

#include "Notifications.h"

using namespace std;
namespace w5
{
	// default constructor - empty
	Notifications::Notifications() : messageTable(nullptr), messageCount(0)
	{
	}


	// copy constructor
	Notifications::Notifications(const Notifications & rhs) : messageTable(nullptr), messageCount(0)
	{
		if (rhs.messageTable)
		{
			messageTable = new Message[MAX_SIZE];

			messageCount = rhs.messageCount;

			// deep copy
			for (int i = 0; i < messageCount; i++)
			{
				messageTable[i] = rhs.messageTable[i];
			}
		}

		//clog << "[INFO] - copy constructor - messageCount = " << messageCount << "\n";
	}


	// copy assignment operator
	Notifications & Notifications::operator=(const Notifications & rhs)
	{
		if (this != &rhs && rhs.messageTable)
		{
			if (messageTable)
				delete[] messageTable;
			messageTable = new Message[MAX_SIZE];

			messageCount = rhs.messageCount;

			// deep copy
			for (int i = 0; i < messageCount; i++)
			{
				messageTable[i] = rhs.messageTable[i];
			}
		}

		//clog << "[INFO] - copy assignment operator - messageCount = " << messageCount << "\n";

		return *this;
	}


	// move constructor
	Notifications::Notifications(Notifications && rhs) : messageTable(rhs.messageTable), messageCount(rhs.messageCount) // steal brains
	{
		rhs.messageCount = 0;
		rhs.messageTable = nullptr;  // makes rhs a 'zombie'

		//clog << "[INFO] - move constructor - messageCount = " << messageCount << "\n";
	}


	// move assignment operator
	Notifications && Notifications::operator=(Notifications && rhs)
	{
		if (this != &rhs && rhs.messageTable)
		{
			if (messageTable)
				delete[] messageTable;  // delete our 'brains' (if we have any)

			// steal brains
			messageCount = rhs.messageCount;
			messageTable = rhs.messageTable;

			// makes rhs a 'zombie'
			rhs.messageCount = 0;
			rhs.messageTable = nullptr;
		}

		//clog << "[INFO] - move assignment operator - messageCount = " << messageCount << "\n";

		return move(*this);
	}


	// destructor
	Notifications::~Notifications()
	{
		delete[] messageTable;
	}


	// adds msg to the set 
	void Notifications::operator+=(const Message & msg)
	{
		if (messageTable == nullptr)
		{
			messageTable = new Message[MAX_SIZE];
		}

		if (messageCount < MAX_SIZE)
		{
			messageTable[messageCount] = msg;
			messageCount++;
		}

		//clog << "[INFO] - adds msg to the set - messageCount = " << messageCount << "\n";
	}


	// inserts the Message objects to the os output stream
	void Notifications::display(ostream & os) const
	{
		for (int i = 0; i < messageCount; i++)
		{
			messageTable[i].display(os);
		}

		//clog << "[INFO] - display(ostream & os) - messageCount = " << messageCount << "\n";
	}
}
