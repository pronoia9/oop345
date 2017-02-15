// Workshop 2 - unsigned int, Enumerations, String Class and File I/O 
// Stations.cpp

#include "Stations.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
namespace w2
{
	Stations::Stations(char * f)
	{
		//clog << "[INFO]  -  Stations::Stations(char * f)" << endl;

		fstream is(f, ios::in);

		if (is.is_open())
		{
			is >> stationCount;

			char c = ' ';
			is.get(c);
			if (c != ';')
			{
				cerr << "Syntax error line 1: expected ';' found " << c << endl;
				exit(3);
			}

			is.ignore(100, '\n');

			stationsTable = new Station[stationCount];

			for (int i = 0; i < stationCount; i++)
			{
				stationsTable[i] = Station(is);
			}

			is.close();
		}
		else
		{
			cerr << "Cannot open file '" << f << "'" << endl;
			exit(2); // cannot continue --- kill the process 
		}
	}


	Stations::~Stations()  // 'NULLPTR' WAS NOT DECLARED IN THIS SCOPE ON MATRIX
	{
		//clog << "[INFO]  -  Stations::~Stations()" << endl;

		/*if (stationsTable == nullptr)
		{
			delete[] stationsTable;
			stationsTable = nullptr;
		}*/
	}


	// accepts the number of passes sold and updates the data for each station in turn
	void Stations::update() const
	{
		//clog << "[INFO]  -  Stations::update() const" << endl;

		cout << endl;
		cout << "Passes in Sold :" << endl;
		cout << "---------------:" << endl;

		for (int i = 0; i < stationCount; i++)
		{
			int studentP, adultP;

			cout << stationsTable[i].getName() << endl;
			cout << " Student Passes sold : ";
			cin >> studentP;
			cout << " Adult   Passes sold : ";
			cin >> adultP;

			stationsTable[i].update(PASS_STUDENT, -studentP);
			stationsTable[i].update(PASS_ADULT, -adultP);
		}
		cout << endl;
	}


	// accepts the number of passes added and updates the data for each station in turn
	void Stations::restock() const
	{
		//clog << "[INFO]  -  Stations::restock() const" << endl;

		cout << "Passes in Added :" << endl;
		cout << "---------------:" << endl;

		for (int i = 0; i < stationCount; i++)
		{
			int studentP, adultP;

			cout << stationsTable[i].getName() << endl;
			cout << " Student Passes added : ";
			cin >> studentP;
			cout << " Adult   Passes added : ";
			cin >> adultP;

			stationsTable[i].update(PASS_STUDENT, studentP);
			stationsTable[i].update(PASS_ADULT, adultP);
		}
		cout << endl;
	}


	// reports the number of passes currently available at each station
	void Stations::report() const
	{
		//clog << "[INFO]  -  Stations::report() const" << endl;

		cout << "Passes in Stock : Student Adult" << endl
			<< "-------------------------------" << endl;
		
		for (int i = 0; i < stationCount; i++)
		{
			cout << left  << setw(17) << stationsTable[i].getName();
			cout << right << setw(8)  << stationsTable[i].inStock(PASS_STUDENT);
			cout << right << setw(6)  << stationsTable[i].inStock( PASS_ADULT ) << endl;
		}
	}
}