#include <iostream>
#include "Matrix3.hpp"

void testMatrix3()
{
   //
   // TEST VECTOR3
   //
   double in{5};
   Matrix3 testDblIn(in);
   Matrix3 a(Vector3(1,2,3));
   Matrix3 b(Vector3(7,6,5));
   Matrix3 c;

   // ADD
   a.print();
   std::cout<< "+" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   c = a + b;
   c.print();
   std::cout << "\n\n" << std::endl;

   // SUBTRACT
   a.print();
   std::cout << "-" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   c = a - b;
   c.print();
   std::cout << "\n\n" << std::endl;

   // MULTIPLY
   a.print();
   std::cout << "*" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   c = a*b;
   c.print();
   std::cout << "\n\n" << std::endl;

   // DIVIDE
   a.print();
   std::cout << "/" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   c = a/b;
   c.print();
   std::cout << "\n\n" << std::endl;
}

