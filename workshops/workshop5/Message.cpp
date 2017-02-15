// Workshop 5 - Containers
// Message.cpp
// Jay Ansin  |  123 08 1150  |  cansin@myseneca.ca

#include "Message.h"
#include <string>

using namespace std;
namespace w5
{
	Message::Message()
	{
	}


	// constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object.  
	// c is the character that delimits each record
	Message::Message(std::ifstream & in, char c)
	{
		string line;

		getline(in, line, c);

		auto cr = line.find('\r');
		if (cr != string::npos)
		{
			line.erase(cr);
		}
		//clog << "[INFO] - size -->" << line.size() << "<--" << "\n";
		if (line.size() < 1) return;
		//clog << "[INFO] - line -->" << line << "<--" << "\n";

		size_t index = 0;

		// NAME
		while (index < line.size())
		{
			if (line[index] == ' ') break;
			name += line[index];
			index++;
		}
		index++; // skip the space ' '
		//clog << "[INFO] - name -->" << name << "<--" << "\n";

		// REPLY
		if (index < line.size() && line[index] == '@')
		{
			index++; // skip the '@'
			while (index < line.size())
			{
				if (line[index] == ' ') break;
				reply += line[index];
				index++;
			}
			index++; // skip the space ' '
		}
		//clog << "[INFO] - reply -->" << reply << "<--" << "\n";

		// TWEET
		while (index < line.size())
		{
			tweet += line[index];
			index++;
		}
		//clog << "[INFO] - tweet -->" << tweet << "<--" << "\n";
	}


	// returns true if the object is in a safe empty state
	bool Message::empty() const
	{
		return tweet.empty();
	}


	// displays the Message objects within the container
	void Message::display(std::ostream & os) const
	{
		os << "Message" << "\n";
		os << " User  : " << name << "\n";
		if (!reply.empty())
			os << " Reply : " << reply << "\n";
		os << " Tweet : " << tweet << "\n";
		os << "\n";
	}


	void Message::out(std::ostream & os) const
	{
		clog << "[INFO] - name -->" << name << "<--" << "\n";
		clog << "[INFO] - reply -->" << reply << "<--" << "\n";
		clog << "[INFO] - tweet -->" << tweet << "<--" << "\n\n";
	}
}