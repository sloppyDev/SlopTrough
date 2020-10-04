#ifndef MATRIX3_HPP
#define MATRIX3_HPP

#include "Vector3.hpp"

struct Matrix3
{
   // CONSTRUCTORS
   Matrix3();
   Matrix3(double in);
   Matrix3(Vector3 in);
   Matrix3(Vector3 row1, Vector3 row2, Vector3 row3);
   Matrix3(double in1, double in2, double in3,
           double in4, double in5, double in6,
           double in7, double in8, double in9);
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
   Matrix3 operator+(double a);

   Matrix3 operator-(const Matrix3& other);
   Matrix3 operator-(double a);

   Matrix3 operator*(const Matrix3& other);
   Vector3 operator*(const Vector3& other);
   Matrix3 operator*(double a);

   Matrix3 operator/(const Matrix3& other);
   Matrix3 operator/(double a);

   // DATA
   Vector3 row1;
   Vector3 row2;
   Vector3 row3;

};

#endif
