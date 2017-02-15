// Workshop 1 - From One Translation Unit to Another 
// process.cpp

#include "process.h"
#include "CString.h"
#include <iostream>

// Uses an object of your CString class to store a possibly truncated version of the string.
void process (char * s)
{
    // Construct a CString object from the string received
    w1::CString cs(s);
    
    // Insert the CString object into the std::cout object and terminate with a newline
    std::cout << cs << std::endl;
}