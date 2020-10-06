#ifndef MATRIX3_HPP
#define MATRIX3_HPP

#include "Vector3.h"

struct Matrix3
{
   // CONSTRUCTORS
   Matrix3();
   Matrix3(float in);
   Matrix3(Vector3 in);
   Matrix3(Vector3 row1, Vector3 row2, Vector3 row3);
   Matrix3(float in1, float in2, float in3,
           float in4, float in5, float in6,
           float in7, float in8, float in9);
   Matrix3(const Matrix3& other);

   ~Matrix3();

   // UTILITY FUNCTIONS
   Vector3 col1() const;
   Vector3 col2() const;
   Vector3 col3() const;
   
   void print();

   // OPERATOR OVERLOADS
   Matrix3 &operator=(const Matrix3& other);

   Matrix3 operator+(const Matrix3& other);
   Matrix3 operator+(float a);

   Matrix3 operator-(const Matrix3& other);
   Matrix3 operator-(float a);

   Matrix3 operator*(const Matrix3& other);
   Vector3 operator*(const Vector3& other);
   Matrix3 operator*(float a);

   Matrix3 operator/(const Matrix3& other);
   Matrix3 operator/(float a);

   // DATA
   Vector3 row1;
   Vector3 row2;
   Vector3 row3;

};

#endif
