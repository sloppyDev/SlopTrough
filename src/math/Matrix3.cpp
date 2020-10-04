#include "Matrix3.hpp"

// CONSTRUCTORS
Matrix3::Matrix3()
{
   row1 = Vector3();
   row2 = Vector3();
   row3 = Vector3();
}

Matrix3::Matrix3(float in)
{
   row1 = Vector3(in);
   row2 = Vector3(in);
   row3 = Vector3(in);
}

Matrix3::Matrix3(Vector3 in)
{
   row1 = in;
   row2 = in;
   row3 = in;
}

Matrix3::Matrix3(float in1, float in2, float in3,
           float in4, float in5, float in6,
           float in7, float in8, float in9)
{
   row1 = Vector3(in1, in2, in3);
   row2 = Vector3(in4, in5, in6);
   row3 = Vector3(in7, in8, in9);
}

Matrix3::Matrix3(const Matrix3& other)
{
   row1 = other.row1;
   row2 = other.row2;
   row3 = other.row3;
}

Matrix3::~Matrix3()
{
}

// UTILITY FUNCTIONS
Vector3 Matrix3::col1() const
{
   return Vector3(row1.x, row2.x, row3.x);
}

Vector3 Matrix3::col2() const
{
   return Vector3(row1.y, row2.y, row3.y);
}

Vector3 Matrix3::col3() const
{
   return Vector3(row1.z, row2.z, row3.z);
}

void Matrix3::print()
{
   row1.print();
   row2.print();
   row3.print();
}

// OPERATOR OVERLOADS
Matrix3 &Matrix3::operator=(const Matrix3& other)
{
   this->row1 = other.row1;
   this->row2 = other.row2;
   this->row3 = other.row3;

   return *this;
}

Matrix3 Matrix3::operator+(const Matrix3& other)
{
   Matrix3 m;
   m.row1 = this->row1 + other.row1;
   m.row2 = this->row2 + other.row2;
   m.row3 = this->row3 + other.row3;

   return m;
}

Matrix3 Matrix3::operator+(float a)
{
   Matrix3 m;
   Vector3 aVec(a);
   m.row1 = this->row1 + aVec;
   m.row2 = this->row2 + aVec;
   m.row3 = this->row3 + aVec;

   return m;
}

Matrix3 Matrix3::operator-(const Matrix3& other)
{
   Matrix3 m;
   m.row1 = this->row1 - other.row1;
   m.row2 = this->row2 - other.row2;
   m.row3 = this->row3 - other.row3;

   return m;
}

Matrix3 Matrix3::operator-(float a)
{
   Matrix3 m;
   Vector3 aVec(a);
   m.row1 = this->row1 + aVec;
   m.row2 = this->row2 + aVec;
   m.row3 = this->row3 + aVec;

   return m;
}

Matrix3 Matrix3::operator*(const Matrix3& other)
{
   Matrix3 m;

   m.row1 = Vector3(this->row1*other.col1(),
                    this->row1*other.col2(),
                    this->row1*other.col3());
   m.row2 = Vector3(this->row2*other.col1(),
                    this->row2*other.col2(),
                    this->row2*other.col3());
   m.row3 = Vector3(this->row3*other.col1(),
                    this->row3*other.col2(),
                    this->row3*other.col3());

   return m;
}

Vector3 Matrix3::operator*(const Vector3& other)
{
   Vector3 v;

   v.x = this->row1*other;
   v.y = this->row2*other;
   v.z = this->row3*other;

   return v;
}

Matrix3 Matrix3::operator*(float a)
{
   Matrix3 m;
   Vector3 aVec(a);

   m.row1 = this->row1*aVec;
   m.row2 = this->row2*aVec;
   m.row3 = this->row3*aVec;

   return m;
}

Matrix3 Matrix3::operator/(const Matrix3& other)
{
   Matrix3 m;

   m.row1 = this->row1/other.row1;
   m.row2 = this->row2/other.row2;
   m.row3 = this->row3/other.row3;

   return m;
}

Matrix3 Matrix3::operator/(float a)
{
   Matrix3 m;
   Vector3 aVec(a);

   m.row1 = this->row1/aVec;
   m.row2 = this->row2/aVec;
   m.row3 = this->row3/aVec;

   return m;
}
