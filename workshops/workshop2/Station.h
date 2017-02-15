#pragma once
#include <iostream>

namespace w2
{
	enum PassType { PASS_STUDENT, PASS_ADULT, PASS_COUNT }; // PassType is an enumeration type that identifies pass types. 

	class Station
	{
	private: // The information stored in each Station object includes:
		std::string stationName; // the name of the station - stored as a string object
		unsigned passes[PASS_COUNT]; // the number of student & adult passes - stored as an unsigned int

	public: // Your class design includes the following member functions:
		Station();
		Station(std::fstream& is);
		void set(const std::string& name, unsigned stud, unsigned adul);
		void update(PassType pt, int num);
		unsigned inStock(PassType pt) const;
		const std::string& getName() const;
	};
}