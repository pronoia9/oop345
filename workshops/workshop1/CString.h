// Wrap your header file in a conditional macro that guards against repeated use.
#pragma once

#include <iostream>
//#define MAX 3

// Embed your class definition and its implementation in a namespace named w1.
namespace w1
{
    const int MAX = 3;  // A constant definition of the number of characters to be stored by an object of your class
    
    class CString
    {
    private:
        char str[MAX + 1];

    public:
        CString(char* s);  // A constructor that receives the address of a C-style null-terminated string
        void display(std::ostream& os);  // A member query named display() that receives a reference to an ostream object
    };
    std::ostream& operator << (std::ostream& os, CString & cs);  // A helper non-friend operator that inserts the stored string into the left ostream operand.
}