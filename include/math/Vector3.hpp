#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Matrix3;

struct Vector3
{
   // CONSTRUCTORS
   Vector3();
   Vector3(double in);
   Vector3(double _x, double _y, double _z);
   Vector3(const Vector3& other);

   ~Vector3();

   void print();

   // OPERATOR OVERLOADS
   Vector3 &operator=(const Vector3& other);

   Vector3 operator+(const Vector3& other);
   Vector3 operator+(double a);

   Vector3 operator-(const Vector3& other);
   Vector3 operator-(double a);

   double  operator*(const Vector3& other); // Dot
   Vector3 operator*(const Matrix3& other);
   Vector3 operator*(double a);             // Element Wise Scalar

   Vector3 operator/(const Vector3& other);
   Vector3 operator/(double a);

   Vector3 operator^(const Vector3& other); // Cross

   // DATA
   double x;
   double y;
   double z;
};

// UTILITY FUNCTIONS
double Mag(Vector3 a);
double Dot(Vector3 a, Vector3 b);
Vector3 ElementMult(Vector3 a, Vector3 b);
Vector3 Cross(Vector3 a, Vector3 b);
Vector3 Proj(Vector3 a, Vector3 b);

#endif
