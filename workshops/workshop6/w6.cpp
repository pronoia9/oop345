// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}


	Grades grades(argv[1]);
	// define the lambda expression for letter
	auto letter = [](double mark) -> std::string
	{
		std::string letterGrade;
		     if (mark >= 90) letterGrade = "A+";
		else if (mark >= 80) letterGrade = "A";
		else if (mark >= 75) letterGrade = "B+";
		else if (mark >= 70) letterGrade = "B";
		else if (mark >= 65) letterGrade = "C+";
		else if (mark >= 60) letterGrade = "C";
		else if (mark >= 55) letterGrade = "D+";
		else if (mark >= 50) letterGrade = "D";
		else                 letterGrade = "F";
		return letterGrade;
	};

	grades.displayGrades(std::cout, letter);

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}