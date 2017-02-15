#include "CString.h"
#include "process.h"

using namespace std;

int main (int argc, char* argv[])
{
    cout << "Command Line :";
    
    for (int arg = 0; arg < argc; arg++)
    {
        cout << " " << argv[arg];
    }
    cout << endl;
    
    if (argc == 1)
    {
        cerr << "Insufficient number of arguments (min 1)" << endl;
        return 1;
    }
    
    cout << "Maximum number of characters stored : " << w1::MAX << endl;
    
    for (int arg = 1; arg < argc; arg++)
    {
        process(argv[arg]);
    }
    
    return 0;
}