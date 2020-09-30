#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Vector3
{
   Vector3();
   Vector3(double in);
   Vector3(double x, double y, double z);

   Vector3 operator=(const Vector3& v);
   
   Vector3 operator+(const Vector3& v);
   Vector3 operator+(double a);
   
   Vector3 operator-(const Vector3& v);
   Vector3 operator-(double a);
   
   double x;
   double y;
   double z;
};

#endif // #define VECTOR3_HPP
