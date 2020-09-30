#include <iostream>
#include "Vector3.hpp"

// CONSTRUCTORS
Vector3::Vector3()
{
   x = 0.0;
   y = 0.0;
   z = 0.0;
}

Vector3::Vector3(double in)
{
   x = in;
   y = in;
   z = in;
}

Vector3::Vector3(double _x, double _y, double _z)
{
   x = _x;
   y = _y;
   z = _z;
}

Vector3::Vector3(const Vector3& other)
{
   x = other.x;
   y = other.y;
   z = other.z;
}

// UTILITY FUNCTIONS
void Vector3::printVector()
{
   std::cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}

// OPERATOR OVERLOADS
Vector3 &Vector3::operator=(const Vector3& other)
{
   this->x = other.x;
   this->y = other.y;
   this->z = other.z;

   return *this;
}

Vector3 Vector3::operator+(const Vector3& other)
{
   Vector3 v;
   v.x = this->x + other.x;
   v.y = this->y + other.y;
   v.z = this->z + other.z;

   return v;
}

Vector3 Vector3::operator+(double a)
{
   Vector3 v;
   v.x = this->x + a;
   v.y = this->y + a;
   v.z = this->z + a;

   return v;   
}
   
Vector3 Vector3::operator-(const Vector3& other)
{
   Vector3 v;
   v.x = this->x - other.x;
   v.y = this->y - other.y;
   v.z = this->z - other.z;

   return v;   
}

Vector3 Vector3::operator-(double a)
{
   Vector3 v;
   v.x = this->x - a;
   v.y = this->y - a;
   v.z = this->z - a;

   return v;
}
