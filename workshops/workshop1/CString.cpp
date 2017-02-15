// Workshop 1 - From One Translation Unit to Another 
// CString.cpp

#include <iostream>
#include <cstring>
//#include <cstdlib>
#include "CString.h"

using namespace std;
namespace w1
{
    // Stores the first MAX characters of the string.  Check for receipt of the null address.  Store an empty string in that case.
    CString::CString (char* s)
    {
        if (s == NULL)
        {
            str[0] = '\0';
            return;
        }
        strncpy(str, s, MAX);
        str[MAX] = '\0';
    }
    
    // Displays the string as stored in your CString object.
    void CString::display(ostream& os)
    {
        os << str;
    }
    
    // Inserts the stored string into the left ostream operand.  This operator prefaces the string with the number of the insertion and increment that number.
    std::ostream& operator << (std::ostream& os, CString & cs)
    {
        static int count = 0;
        
        os << count << ": ";
        count++;
        
        cs.display(os);
        
        return os;
    }
}