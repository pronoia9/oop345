//
//  w1_lab.cpp
//  workshop1
//
//  Created by Jay Ansin on 2017-01-12.
//  Copyright © 2017 Jay Ansin. All rights reserved.
//  cansin@myseneca.ca  |  123081150
//

#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;

class CString
{
    char str[MAX + 1]; // +1 for the \0
public:
    CString (char * s)
    {
        if (s == nullptr)
        {
            str[0] = '\0';
            return;
        }
        strncpy(str, s, MAX);
        str[MAX] = '\0';
        
        //cout << "CString(" << s << ") stored ->" << str << "<-" << endl;
    }
    
    void display (ostream& os)
    {
        os << str;
    }
};

ostream& operator << (ostream& os, CString& cs)
{
    static int count = 0;
    
    os << count << ": ";
    count++;
    
    cs.display(os);
    
    return os;
}

void process (char * s)
{
    //cout << "process(" << s << ")" << endl;
    CString cs(s);
    cout << cs << endl;
}

int main (int argc, const char * argv[])
{
    /*cout << "argc=" << argc << endl;
     
     for (int arg = 0; arg < argc; arg++)
     {  cout << "argv[" << arg << "] = -->" << argv [arg] << "<--" << endl;  }*/
    
    cout << "Command Line :" << endl;
    for (int arg = 0; arg < argc; arg++)
    {  cout << " " << argv [arg];  } // client wants this way >_<
    cout << endl;
    
    if (argc == 1)
    {
        cerr << "Insufficient number of arguments (min 1)" << endl;
        return 1;
    }
    
    for (int arg = 1; arg < argc; arg++)
    {  process(argv [arg]);  }
    
    return 0; // everything OK
}
