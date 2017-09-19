// Workshop 6 - Lambda Expression
// Grades.h

#pragma once
#include <iostream>
#include <fstream>
#include <string>

//namespace w6
//{
	class Grades
	{
	private:
		// Each file record contains one student number and a grade, which may include a decimal value.
		std::string * studentNo;
		double * studentGrade;
		int studentCount;

	public:
		Grades() : studentNo(nullptr), studentGrade(nullptr), studentCount(0) {}


		// Upon instantiation, a Grades object receives the address of a C-style null-terminated string that contains the name of the file 
		// holding the grade information for all students in a course.
		Grades(char* str) : studentNo(nullptr), studentGrade(nullptr), studentCount(0)
		{
			std::ifstream file(str);

			if (file.is_open())
			{
				//clog << "GRADES(CHAR * STR)\n";
				std::string line;

				while (!file.eof())
				{
					getline(file, line);
					if (line.size() > 1)  studentCount++;  // number of records (lines)
				}
				//clog << "STUDENTCOUNT = " << studentCount << endl << endl;

				file.clear();   // clear flags
				file.seekg(0);  // change position to the start of the file

				studentNo = new std::string[studentCount];
				studentGrade = new double[studentCount];

				for (int i = 0; i < studentCount; i++)
				{
					file >> studentNo[i];
					file >> studentGrade[i];
					//clog << "studentNo    = " << studentNo[i] << endl;
					//clog << "studentGrade = " << studentGrade[i] << endl << endl;
				}
				file.close();
			}
			else
			{
				// If the object cannot open the file, the constructor throws an exception with a suitable message.
				std::clog << "No file found\n";
				exit(2);
			}
		}


		~Grades()
		{
			if (studentNo != nullptr) delete[] studentNo;
			if (studentGrade != nullptr) delete[] studentGrade;
		}


		// Receives a reference to the output stream object and the expression to be used in determining the letter grade.  
		// Your function displays the student number, the student grade, and the letter equivalent as shown below on the right.
		template <typename T>
		void displayGrades(std::ostream& os, T letter) const
		{
			if (studentCount > 0)  // && studentGrade != nullptr && studentNo != nullptr
			{
				for (int i = 0; i < studentCount; i++)
				{
					os << studentNo[i] << " "
						<< studentGrade[i] << " "
						<< letter(studentGrade[i]) << "\n";
				}
			}
		}


		// Your design prohibits copying, moving or assigning of a Grades object.
		Grades(const Grades&) = delete;
		void operator = (const Grades&) = delete;
	};
//}