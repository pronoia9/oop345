// Jay Ansin
// cansin@myseneca.ca
// 123 08 1150
// Workshop 2 - unsigned int, Enumerations, String Class and File I/O
// Stations.cpp

#include <string>
#include <fstream>

using namespace w2;
using namespace std;

//
Stations::Stations(char* f)
{
	clog << "f=" << f << endl;

	fstream is(f, ios::in);

	if (is.is_open())
	{
		string line; 

		getline(is, line);

		clog << "line= '" << line << "'" << endl;

		stationCount = 0;
		size_t index = 0;

		while (index < line.size())
		{
			if (isdigit(line[index]))
			{
				stationCount = 10 * stationCount + (line[index] - '0');
				index++;
			}
			else break;
		}

		clog << "stationCount=" << stationCount << endl;

		if (line[index] != ';')
		{
			cerr << "line '" << line << "' is missing a ';' after the station count" << endl;
			exit (3);
		}

		stationTable = new Station [stationCount]; // need a class Station now, w/ contructor for it

		for (int s = 0; s < stationCount; s++)
		{
			stationTable[s] = Station(is);
		}
	}
	else
	{
		cerr << "Cannot open file '" << f << "'" << endl;
		exit(2); // cannot continue --- kill the process 
	}
}

// Accepts the number of passes sold and updates the data for each station in turn
void Stations::update() const
{
	cout << "Passes Sold :"
		 << "-------------";
}

// Accepts the number of passes added and updates the data for each station in turn
void Stations::restock() const
{
}

// Reports the number of passes currently available at each station
void Stations::report() const
{
	cout << "Passes in Stock : Student Adult" << endl 
		 << "-------------------------------" << endl;

	for (int s = 0; s < stationCount; s++)
	{
		stationTable[s].getSales();
	}
}