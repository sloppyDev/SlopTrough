// #include "testOpenGL.cpp"

#include "testVector3.cpp"
// #include "testMatrix3.cpp"

#include "unistd.h"
#include "WindowManager.hpp"
#include "Rotation.hpp"

int main()
{
   WindowManager WinManager(600, 400, "my window!");

   
   Vector3 square1[4];
   Vector3 square2[4];
   square1[0] = Vector3(-0.6, -0.6, 0.3);
   square1[1] = Vector3(-0.6, 0.6, 0.3);
   square1[2] = Vector3(0.6, 0.6, 0.3);
   square1[3] = Vector3(0.6, -0.6, 0.3);
   square2[0] = Vector3(-0.6, -0.6, -0.3);
   square2[1] = Vector3(-0.6, 0.6, -0.3);
   square2[2] = Vector3(0.6, 0.6, -0.3);
   square2[3] = Vector3(0.6, -0.6, -0.3);

   while (!glfwWindowShouldClose(WinManager.window))
   {
      square1[0] = Rotate(square1[0], 0.01, 2);
      square1[1] = Rotate(square1[1], 0.01, 2);
      square1[2] = Rotate(square1[2], 0.01, 2);
      square1[3] = Rotate(square1[3], 0.01, 2);

      square2[0] = Rotate(square2[0], 0.01, 2);
      square2[1] = Rotate(square2[1], 0.01, 2);
      square2[2] = Rotate(square2[2], 0.01, 2);
      square2[3] = Rotate(square2[3], 0.01, 2);
      
      WinManager.beginRender();

      glBegin(GL_LINES);

      for (unsigned int i = 0; i < 4; i++)
      {
         glVertex3f(square1[i%4].x, square1[i%4].y, square1[i%4].z);
         glVertex3f(square1[(i+1)%4].x, square1[(i+1)%4].y, square1[(i+1)%4].z);

         glVertex3f(square2[i%4].x, square2[i%4].y, square2[i%4].z);
         glVertex3f(square2[(i+1)%4].x, square2[(i+1)%4].y, square2[(i+1)%4].z);         
      }

      glVertex3f(square1[1].x, square1[1].y, square1[1].z);
      glVertex3f(square1[3].x, square1[3].y, square1[3].z);

      glVertex3f(square2[1].x, square2[1].y, square2[1].z);
      glVertex3f(square2[3].x, square2[3].y, square2[3].z);      
      glEnd();

      WinManager.finishRender();

   }

   return 0;
}
