#include <iostream>
#include "Vector3.h"

void testVector3()
{
   //
   // TEST VECTOR3
   //
   Vector3 a(1,2,3);
   Vector3 b(7,6,5);
   Vector3 c;
   float  d;

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

   // DIVIDE
   a.print();
   std::cout << "/" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   c = a^b;
   c.print();
   std::cout << "\n\n" << std::endl;

   // DOT
   a.print();
   std::cout << "DOT" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   d = Dot(a,b);
   std::cout << d << std::endl;
   std::cout << "\n\n" << std::endl;

   // CROSS
   a.print();
   std::cout << "CROSS" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   c = Cross(a,b);
   c.print();
   std::cout << "\n\n" << std::endl;

   // PROJ
   a.print();
   std::cout << "PROJ" << std::endl;
   b.print();
   std::cout << "=" << std::endl;
   c = Proj(a,b);
   c.print();
   std::cout << "\n\n" << std::endl;

   // ELEMENTWISE
   a.print();
   std::cout << "Element Wise Multiplication" << std::endl;;
   b.print();
   std::cout << "=" << std::endl;
   c = ElementMult(a, b);
   c.print();
   std::cout << "\n\n" << std::endl;
}
