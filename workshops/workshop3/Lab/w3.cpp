// Workshop 3 - Copy and Move Semantics
 // w3.cpp

 #include <iostream>
 #include <iomanip>
 #include <utility>
 #include <ctime>
 #include "Text.h"
 #define TIME(start, end) double((end) - (start)) / CLOCKS_PER_SEC

using namespace w3;
using namespace std;

 int main (int argc, char* argv[]) {
     if (argc == 1) {
         cerr << argv[0] << ": missing file operand\n";
         return 1;
     }
     else if (argc != 2) {
         cerr << argv[0] << ": too many arguments\n";
         return 2;
     }
     std::clock_t cs, ce;
     {
         cout << std::fixed << std::setprecision(3);
         cs = std::clock();
         Text a;
         ce = std::clock();
         cout << "Constructor      " << TIME(cs, ce) << " seconds"; 
         cout << " - a.size = " << a.size() << std::endl;

         cs = std::clock();
         Text b(argv[1]);
         ce = std::clock();
         cout << "Constructor      " << TIME(cs, ce) << " seconds";
         cout << " - b.size = " << b.size() << std::endl;

         cs = std::clock();
         a = b;
         ce = std::clock();
         std::cout << "Copy Assignment  " << TIME(cs, ce) << " seconds";
         std::cout << " - a.size = " << a.size() << std::endl;

         cs = std::clock();
         a = std::move(b);
         ce = std::clock();
         cout << "Move Assignment  " << TIME(cs, ce) << " seconds";
         cout << " - a.size = " << a.size() << std::endl;

         cs = std::clock();
         Text c = a;
         ce = std::clock();
         cout << "Copy Constructor " << TIME(cs, ce) << " seconds";
         cout << " - c.size = " << c.size() << std::endl;

         cs = std::clock();
         Text d = std::move(a);
         ce = std::clock();
         cout << "Move Constructor " << TIME(cs, ce) << " seconds";
         cout << " - d.size = " << d.size() << std::endl;

         cs = std::clock();
     }
     ce = std::clock();
     cout << "Destructor       " << TIME(cs, ce) << " seconds\n";
 }