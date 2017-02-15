// Workshop 2 - unsigned int, Enumerations, String Class and File I/O 
// Station.cpp

#include "Station.h"
#include <string>
//#include <cctype>
#include <fstream>
//#include <stdlib.h>

using namespace std;
namespace w2
{
	// A default constructor that initializes the instance variables through an initialization list
	Station::Station()
	{
		//clog << "[INFO]  -  Station::Station()" << endl;

		stationName[0] = '\0';
		passes[PASS_STUDENT] = 0;
		passes[PASS_ADULT] = 0;
	}


	// A contructor that reads an fstream file, storing the station data in this class.
	Station::Station(std::fstream & is)
	{
		//clog << "[INFO]  -  Station::Station(std::fstream & is)" << endl;
		string name;
		int stud, adlt;

		// For station name
		getline(is, name, ';');

		is >> stud;
		is >> adlt;
		is.ignore(100, '\n');

		set(name, stud, adlt);
	}


	// Sets the instance variables to the values received in its parameters
	void Station::set(const string & name, unsigned student, unsigned adult)
	{
		//clog << "[INFO]  -  Station::set(const string & name, unsigned student, unsigned adult)" << endl;

		stationName = name;
		passes[PASS_STUDENT] = student;
		passes[PASS_ADULT] = adult;
	}


	// Updates the number of passes - sold if negative, added if positive
	void Station::update(PassType pt, int num)
	{
		//clog << "[INFO]  -  Station::update(PassType pt, int num)" << endl;

		passes[pt] += num;
	}


	// Returns the number of passes of the requested type
	unsigned Station::inStock(PassType pt) const
	{
		//clog << "[INFO]  -  Station::inStock(PassType pt) const" << endl;

		return passes[pt];
	}


	// Returns a reference to a string object holding the name of the station
	const string & Station::getName() const
	{
		//clog << "[INFO]  -  Station::getName() const" << endl;

		return stationName;
	}
}