#include <iostream>
#include <math.h>
#include "Vector3.h"

// CONSTRUCTORS
Vector3::Vector3()
{
   x = 0.0;
   y = 0.0;
   z = 0.0;

}

Vector3::Vector3(float in)
{
   x = in;
   y = in;
   z = in;

}

Vector3::Vector3(float _x, float _y, float _z)
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

Vector3::~Vector3()
{
}

void Vector3::print()
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

Vector3 Vector3::operator+(float a)
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

Vector3 Vector3::operator-(float a)
{
   Vector3 v;
   v.x = this->x - a;
   v.y = this->y - a;
   v.z = this->z - a;

   return v;
}

float Vector3::operator*(const Vector3& other)
{
   float d;
   d =  this->x*other.x + this->y*other.y + this->z*other.z;
   
   return d;
}

Vector3 Vector3::operator*(float a)
{
   Vector3 v;
   v.x = this->x*a;
   v.y = this->y*a;
   v.z = this->z*a;

   return v;
}

Vector3 Vector3::operator/(const Vector3& other)
{
   Vector3 v;
   v.x = this->x/other.x;
   v.y = this->y/other.y;
   v.z = this->z/other.z;

   return v;
}

Vector3 Vector3::operator/(float a)
{
   Vector3 v;
   v.x = this->x/a;
   v.y = this->y/a;
   v.z = this->z/a;

   return v;
}

Vector3 Vector3::operator^(const Vector3& other)
{
   float x;
   float y;
   float z;

   x = this->y*other.z - this->z*other.y;
   y = this->z*other.x - this->x*other.z;
   z = this->x*other.y - this->y*other.x;

   Vector3 v(x, y, z);
   
   return v;
}

// UTILITY FUNCTIONS
float Mag(Vector3 a)
{
   float out = pow(a.x*a.x + a.y*a.y + a.z*a.z,0.5);

   return out;
}

float Dot(Vector3 a, Vector3 b)
{
   float out;
   out = a.x*b.x + a.y*b.y + a.z*b.z;

   return out;
}

Vector3 ElementMult(Vector3 a, Vector3 b)
{
   Vector3 v;
   v.x = a.x*b.x;
   v.y = a.y*b.y;
   v.z = a.z*b.z;

   return v;
}

Vector3 Cross(Vector3 a, Vector3 b)
{
   float x;
   float y;
   float z;

   x = a.y*b.z - a.z*b.y;
   y = a.z*b.x - a.x*b.z;
   z = a.x*b.y - a.y*b.x;

   Vector3 v(x, y, z);
   
   return v;
}

Vector3 Proj(Vector3 a, Vector3 b)
{
   float magB  = Mag(b);
   float aDotB = Dot(a, b);
   Vector3 v = (b*aDotB)/(magB*magB);   
   
   return v;
}
