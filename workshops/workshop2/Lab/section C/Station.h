// Jay Ansin
// cansin@myseneca.ca
// 123 08 1150
// Workshop 2 - unsigned int, Enumerations, String Class and File I/O 
// Station.h

#pragma once

#include <iostream>

namespace w2
{
	enum PassType { PASS_STUDENT, PASS_ADULT, PASS_COUNT };

	class Stations
	{
	private:
		string stationName;
		unsigned passes[PASS_COUNT];

	public:
		Station() // a default constructor that initializes the instance variables through an initialization list
		Station(fstream& is); //
		void set(const std::string&, unsigned, unsigned) // sets the instance variables to the values received in its parameters
		void update(PassType, int) // updates the number of passes - sold if negative, added if positive
		unsigned inStock(PassType) const // returns the number of passes of the requested type
		const std::string& getName() const // returns a reference to a string object holding the name of the station
	};
}