// g++ std=c++11 w3.cpp -o w3
#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace w3
{
	class Text
	{
	private:
		size_t count; // number of lines in the file
		string* lineTable;

	public:
		Text(char* f) : count(0)
		{
			fstream in(f, ios::in);

			if (in.is_open())
			{
				string line;

				while(getline(in, line))
				{
					count++;
				}
				cout << "file '" << f << "' countains " << count << " lines" << endl;

				lineTable = new string[count];

				{
					cout << in.good() << "<-- good: true if none of the flags is set" << endl;
					cout << in.fail() << "<-- fail: true if ios::failbit or ios::badbit is true" << endl;
					cout << in.eof()  << "<-- eof : true if ios::eof is true" << endl;
					cout << in.bad()  << "<-- bad : true if ios::badbit is true" << endl;

					cout << "clearing all status flags" << endl;
					in.clear(); // clear all flags

					cout << "after clearing all status flags"; << endl;
					cout << in.good() << "<-- good: true if none of the flags is set" << endl;
					cout << in.fail() << "<-- fail: true if ios::failbit or ios::badbit is true" << endl;
					cout << in.eof()  << "<-- eof : true if ios::eof is true" << endl;
					cout << in.bad()  << "<-- bad : true if ios::badbit is true" << endl;

					in.seekp(0);
				}

				for(size_t i = 0; i < count; i++)
				{
					getline(in, lineTable[i]);
				}
			}
			else
			{
				cerr << "Cannot open file '" << f << "'" << endl;
				exit(3);
			}
		}
		

		size_t size()
		{
			return count;
		}


		//Text move(Text&& rhs)
		

		void dump()
		{
			for(size_t i = 0; i < count; i++)
			{
				cout << "	line " << i+1 << " -->" << lineTable[i] << "<--" << endl;
				// i+1 to count from 1, not 0
			}
		}


		Text& opeator = (const Text& rhs)
		{
			if(this != &rhs)
				return *this;
		}


		Text&& opeator = (Text&& rhs)
		{
			if(this != &rhs)
				return move(*this);
		}
	};
}