#pragma once

#include <fstream>
#include <iostream>
#include <string>

//using namespace std;
namespace w5
{
	class Message
	{
	private:
		std::string name, reply, tweet;

	public:
		Message(std::ifstream& in, char c) // constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object.  c is the character that delimits each record
		{
			std::string line;
			getline(in, line, c);

			auto cr = line.find( '\r' );
			if (cr != std::string::npos)
			{
				line.erase( cr );
			}

			//std::clog << "line ->" << line << "<--" << std::endl;

			size_t index = 0;

			while (index < line.size())
			{
				if (line[index] == ' ') break;
				name += line[index];
				index++;
			}
			//std::clog << "name = '" << name << "'" << std::endl;

			//std::clog << "line[index] = '" << line[index] << std::endl;
			index++; // skip the ' '

			if (index < line.size() && line[index] == '@') // we have a @reply
			{
				index++; // skip the '@'

				while (index < line.size())
				{
					if (line[index] == ' ') break;
					reply += line[index];
					index++;
				}
				//std::clog << "reply = '" << reply << "'" << std::endl;
				index++; // skip the ' '	
			}
			
			while (index < line.size())
			{
				tweet += line[index];
				index++;
			}
			//std::clog << "tweet = '" << tweet << "'" << std::endl;
		}
		
		bool empty() const // returns true if the object is in a safe empty state
		{
			return tweet.empty();
		}
		
		void display(std::ostream& os) const // displays the Message objects within the container
		{
			os << "Message" << std::endl;
			os << " User  : " << name << std::endl;
			if (!reply.empty())
			os << " Reply : " << reply << std::endl;
			os << " Tweet :" << tweet << std::endl;
			os << std::endl;
		}
	};
}