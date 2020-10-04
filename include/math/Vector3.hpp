#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Matrix3;

struct Vector3
{
   // CONSTRUCTORS
   Vector3();
   Vector3(float in);
   Vector3(float _x, float _y, float _z);
   Vector3(const Vector3& other);

   ~Vector3();

   void print();

   // OPERATOR OVERLOADS
   Vector3 &operator=(const Vector3& other);

   Vector3 operator+(const Vector3& other);
   Vector3 operator+(float a);

   Vector3 operator-(const Vector3& other);
   Vector3 operator-(float a);

   float  operator*(const Vector3& other); // Dot
   Vector3 operator*(const Matrix3& other);
   Vector3 operator*(float a);             // Element Wise Scalar

   Vector3 operator/(const Vector3& other);
   Vector3 operator/(float a);

   Vector3 operator^(const Vector3& other); // Cross

   // DATA
   float x;
   float y;
   float z;
};

// UTILITY FUNCTIONS
float Mag(Vector3 a);
float Dot(Vector3 a, Vector3 b);
Vector3 ElementMult(Vector3 a, Vector3 b);
Vector3 Cross(Vector3 a, Vector3 b);
Vector3 Proj(Vector3 a, Vector3 b);

#endif
