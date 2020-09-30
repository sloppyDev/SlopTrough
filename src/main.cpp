#include <iostream>
#include <string>
#include "Vector3.hpp"

int main()
{
   double inDouble;
   std::cout << "Hello there!  Enter a value to make a vector out of!" << std::endl;

   std::cin >> inDouble;

   Vector3 vec(inDouble);
   Vector3 vecBig(1000.0);
   Vector3 vecSmol(0.1, 0.5, 1.2345);
   Vector3 sum;
   Vector3 diff;
   
   vecBig.printVector();
   vec.printVector();   
   sum = vecBig + vec;
   sum.printVector();
   diff = sum - vecSmol;
   diff.printVector();
   vec = diff;
   vec.printVector();
   return 0;
}
