#include <iostream>
#include <string>

#include "testOpenGL.cpp"

#include "testVector3.cpp"
#include "testMatrix3.cpp"

int main()
{
   testVector3();
   testMatrix3();
   testOpenGL();
   std::cout << "I'M OUT HERE" << std::endl;
   return 0;
}
