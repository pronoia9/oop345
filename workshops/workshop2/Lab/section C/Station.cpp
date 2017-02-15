// Jay Ansin
// cansin@myseneca.ca
// 123 08 1150
// Workshop 2 - unsigned int, Enumerations, String Class and File I/O
// Station.cpp

#include <string>

using namespace w2;
using namespace std;

// A default constructor that initializes the instance variables through an initialization list
Station::Station()
{

}

// A contructor that reads an fstream file, storing the station data in this class.
Station::Station(fstream& is)
{
	string line;

	getline(is, line);

	clog << "line= '" << line << "'" << endl;

	string name;
	size_t index = 0;

	// For Station Name
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

	if (line[index] != ';')
	{
		cerr << "line '" << line << "' is missing a ';' after the station name" << endl;
		exit(4);
	}

	index++; // skip the ';'

	// For Student Pass Number
	int student = 0;

	while (index < line.size())
	{
		if (isdigit(line[index]))
		{
			student = 10 * student + (line[index] - '0');
			index++;
		}
		else break;
	}

	if (line[index] != ' ')
	{
		cerr << "line '" << line << "' is missing a ' ' after the station student count" << endl;
		exit(5);
	}

	index++; // skip the ' '

	// For Adult Pass Number
	int adult = 0;

	while (index < line.size())
	{
		if (isgidit(line[index]))
		{
			adult = 10 * adult + (line[index] - '0');
			index++;
		}
		else break;
	}

	clog << "adult=" << adult << endl;

	if (index != line.size())
	{
		cerr << "line '" << line << "' is " << endl;
		exit(6);
	}
}

// Sets the instance variables to the values received in its parameters
void Station::set(const string& name, unsigned student, unsigned adult)
{
	stationName          = name;
	passes[PASS_STUDENT] = student;
	passes[PASS_ADULT]   = adult;
}

// Updates the number of passes - sold if negative, added if positive
void Station::update(PassType pt, int change)
{
	passes[pt] += change;
}

// Returns the number of passes of the requested type
unsigned Station::inStock(PassType pt) const
{
	return passes[pt];
}

// Returns a reference to a string object holding the name of the station
const string& Station::getName() const
{
	return stationName;
}

void Station::getSales() // DO IOMANIP
{
	cout << getName() << ", " << endl;
	cout << "Student Passes sold : ";
	int student;
	cin >> student;
	cout << "Adult Passes sold : ";
	int adult;
	cin >> adult;

	update(PASS_STUDENT, -student);
	update(PASS_ADULT, -adult);
}

void Station::report() // DO IOMANIP
{
	cout << getName() << ", "
		 << inStock(PASS_STUDENT) << ", "
		 << inStock(PASS_ADULT)  << endl;
}