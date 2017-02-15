#pragma once

#include <fstream>
#include <iostream>
#include "Message.h"

namespace w5
{
	const int MAX_SIZE = 10;
	class Notifications
	{
	private:
		Message* messageTable;
		int      messageCount;

	public:
		Notifications() // default constructor - empty
		 : messageTable(nullptr), messageCount(0)
		{
			std::clog << "Notification: " << std::endl;
		}


		Notifications(const Notifications&) // copy constructor
		 : messageTable(nullptr), messageCount(0)
		{
			std::clog << "Notification: ctor with arg" << std::endl;

			messageCount = rhs.messageCount;
			if (rhs.messageTable)
			{
				// deep copy
				for (int i = 0; i < messageCount; i++)
				{
					messageTable[i] = rhs.messageTable[i];
				}
			}
		}

		
		Notifications& operator=(const Notifications&) // copy assignment operator
		{
			if (this != &rhs)
			{
				delete [] messageTable; // delete our 'brains' (if we have any)

				if (rhs.messageTable)
				{
					// deep copy
					for (int i = 0; i < messageCount; i++)
					{
						messageTable = new Message[ MAX_SIZE ];

						// deep copy
						for (int i = 0; i < messageCount; i++)
						{
							messageTable[i] = rhs.messageTable[i];
						}
					}
				}
			}

			return std::move(*this);
		}
		

		Notifications(Notifications&& rhs) // move constructor
		 : messageTable(rhs.messageTable), messageCount(rhs.messageCount) // steal brains
		{
			rhs.messageTable = nullptr;  // makes rhs a 'zombie'
			rhs.messageCount = 0;
		}
		

		Notifications&& operator=(Notifications&& rhs) // move assignment operator
		{
			if (this != &rhs)
			{
				if (messageTable != nullptr)
					delete [] messageTable; // delete our 'brains' (if we have any)

				// steal brains
				messageTable = rhs.messageTable;
				messageCount = rhs.messageCount;

				// makes rhs a 'zombie'
				rhs.messageTable = nullptr;  
				rhs.messageCount = 0;
			}

			return std::move(*this);
		}
		

		~Notifications() // destructor
		{
		}

		
		void operator+=(const Message& msg) // adds msg to the set 
		{
			if (messageTable == nullptr)
			{
				messageTable = new Message[ MAX_SIZE ];
			}
			
			if (messageCount < MAX_SIZE)
			{
				messageTable[messageCount] = msg;
				messageCount++;
			}
		}
		

		void display(std::ostream& os) const // inserts the Message objects to the os output stream
		{
			for (int i = 0; i < messageCount; i++)
			{
				messageTable[i].display(os);
			}
		}
	};
}