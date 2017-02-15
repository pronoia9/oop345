#pragma once

#include <fstream>
#include <iostream>

namespace w5
{
	//const int MAX_TWEET = 140;
	class Message
	{
	private:
		std::string name, reply, tweet;

	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream& os) const;
		void out(std::ostream& os) const;
	};
}