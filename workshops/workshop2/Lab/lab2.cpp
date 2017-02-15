#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
namespace w2
{
	// PassType is an enumeration type that identifies pass types.
	enum PassType { PASS_STUDENT, PASS_ADULT, PASS_COUNT };

	class Station
	{
	private:
		string stationName;
		unsigned passes[PASS_COUNT];

	public:
		// A default constructor that initializes the instance variables through an initialization list
		Station()
		{
			//
		}

		// A contructor that reads an fstream file, storing the station data in this class.
		Station(fstream& is)
		{
			string line;
			getline(is, line);
			clog << "line=" << line << endl;

			size_t index = 0;

			string name;

			while (index < line.size())
			{
				if (line[index] != ';')
				{
					name += line[index];
					index++;
				}
				else break;
			}

			clog << "name=" << name << endl;

			if (index == line.size())
			{
				cerr << "end-of-line encountered, no ';' on line ->'" << line << endl;
				exit (4);
			}
			if (line[index] != ';')
			{
				cerr << "Station name not followed by a ';'" << endl;
				exit (5);
			}

			index++; // skip ';'

			int student = 0;

			while (index < line.size()) // while we're in the string
			{
				if (isdigit(line[index])) // if the character is a digit
				{
					student = 10 * stationCount + (line[index] - '0'); //.......
					index++;
				}
				else break;		
			}
			clog << "student=" << stationCount << endl;

			if (line[index] != ' ')
			{
				cerr << "Station student count not followed by a ';'" << endl;
				cerr << "followed by a " << line[index] << endl;
				exit (6);
			}

			index++; // skip ' '

			int adult = 0;

			while (index < line.size()) // while we're in the string
			{
				if (isdigit(line[index])) // if the character is a digit
				{
					adult = 10 * stationCount + (line[index] - '0'); //.......
					index++;
				}
				else break;		
			}
			clog << "adult=" << stationCount << endl;

			if (index != line.size())
			{
				cerr << "Station adult count followed by unknown characters" << endl;
				exit (7);
			}

			set(name, student, adult);
		}

		// Sets the instance variables to the values received in its parameters
		void set(const std::string& name, unsigned student, unsigned adult) 
		{
			stationName          = name;
			passes[PASS_STUDENT] = student;
			passes[PASS_ADULT]   = adult;
		}

		// Updates the number of passes - sold if negative, added if positive
		void update(PassType pt, int change)
		{
			passes[pt] += change;
		}

		// Returns the number of passes of the requested type
		unsigned inStock(PassType pt) const
		{
			return passes[pt];
		}

		// Returns a reference to a string object holding the name of the station
		const std::string& getName() const
		{
			return stationName;
		}

		void processUpdate()
		{
			cout << stationName <<
				 << "Student Passes sold :";
			int student;
			cin >> student;
			cout << "Adult   Passes sold :";
			int adult;
			cin >> adult;

			update[PASS_STUDENT, student];
			update[PASS_ADULT,   student];
		}

		void report()
		{
			cout << "name, student, adult="
				 << stationName << ","
				 << passes[PASS_STUDENT] << ","
				 << passes[PASS_ADULT]  << endl;

			cout << "Passes in Stock : Student Adult" << endl
				 << "-------------------------------" << endl 
				 << stationName << "," 
				 << passes[PASS_STUDENT] << "," 
				 << passes[PASS_ADULT]  << endl;
		}
	}

	class Stations
	{
	private:
		int stationCount;
		Station* stationTable;

	public:
		Stations(char* f)
		{
			clog << "Stations(" << f << ")" << endl;

			fstream is(f, ios::in);

			if (is.is_open())
			{
				string line;
				getline(is, line);

				clog  << "line=" << line << endl;

				stationCount = 0;
				size_t index = 0;

				while (index < line.size()) // while we're in the string
				{
					if (isdigit(line[index])) // if the character is a digit
					{
						stationCount = 10 * stationCount + (line[index] - '0'); //.......
						index++;
					}
					else break;
				}
				clog << "stationCount=" << stationCount << endl;

				if (line[index] != ';')
				{
					cerr << "Station count not followed by a ';'" << endl;
					cerr << "followed by a " << line[index] << endl;
					exit (2);
				}

				stationTable = new Station [stationCount];

				for (int s = 0; s < stationCount; s++)
				{
					stationTable[s] = Station(is);
				}

				is.close();
			}
			else
			{
				cerr << "cannot open file '" << f << "'" << endl;
				exit (3);
			}
		}

		void report()
		{
			cout << "Passes in Stock : Student Adult" << endl
				 << "-------------------------------" << endl 
				 << stationName << "," 
				 << passes[PASS_STUDENT] << "," 
				 << passes[PASS_ADULT]  << endl;
		}
	}
}