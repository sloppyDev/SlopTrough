#include "Rotation.hpp"

Vector3 Rotate(Vector3 point, float angle, unsigned int axis)
{
   Vector3 v;
   Matrix3 rotMat;

   switch (axis)
   {
   case 1:
   {
      rotMat.row1 = Vector3(1.0, 0.0, 0.0);
      rotMat.row2 = Vector3(0.0, cos(angle), -sin(angle));
      rotMat.row3 = Vector3(0.0, sin(angle), cos(angle));      
   }
   break;
   case 2:
   {
      rotMat.row1 = Vector3(cos(angle), 0.0, sin(angle));
      rotMat.row2 = Vector3(0.0, 1.0, 0.0);
      rotMat.row3 = Vector3(-sin(angle), 0.0, cos(angle));            
   }
   break;
   case 3:
   {
      rotMat.row1 = Vector3(cos(angle), -sin(angle), 0.0);
      rotMat.row2 = Vector3(sin(angle), cos(angle), 0.0);
      rotMat.row3 = Vector3(0.0, 0.0, 1.0);            
   }
   }

   v = rotMat*point;

   return v;
}
