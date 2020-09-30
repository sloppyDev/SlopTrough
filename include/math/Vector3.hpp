#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Vector3
{
   Vector3();
   Vector3(double in);
   Vector3(double _x, double _y, double _z);
   Vector3(const Vector3& other);

   Vector3 &operator=(const Vector3& other);
   
   Vector3 operator+(const Vector3& other);
   Vector3 operator+(double a);
   
   Vector3 operator-(const Vector3& other);
   Vector3 operator-(double a);

   void printVector();
   
   double x;
   double y;
   double z;
};
#endif // #define VECTOR3_HPP
