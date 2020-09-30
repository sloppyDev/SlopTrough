#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Vector3
{
   // CONSTRUCTORS
   Vector3();
   Vector3(double in);
   Vector3(double _x, double _y, double _z);
   Vector3(const Vector3& other);

   // UTILITY FUNCTIONS
   double Mag(Vector3 a);
   double Dot(Vector3 a, Vector3 b);
   Vector3 Cross(Vector3 a, Vector3 b);
   Vector3 Proj(Vector3 a, Vector3 b);
   
   void print();
   
   // OPERATOR OVERLOADS
   Vector3 &operator=(const Vector3& other);
   
   Vector3 operator+(const Vector3& other);
   Vector3 operator+(double a);
   
   Vector3 operator-(const Vector3& other);
   Vector3 operator-(double a);
   Vector3 operator*(const Vector3& other);
   Vector3 operator*(double a);

   Vector3 operator/(const Vector3& other);
   Vector3 operator/(double a);

   // DATA
   double x;
   double y;
   double z;
};
#endif // #define VECTOR3_HPP
