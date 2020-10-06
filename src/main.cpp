// #include "testOpenGL.cpp"

#include "testVector3.cpp"
// #include "testMatrix3.cpp"

#include "unistd.h"
#include "WindowManager.h"
#include "Rotation.h"
#include "math.h"
#include "MeshManager.h"

// Vector3 MapToScreen(Vector3 in, float aspect)
// {
//    Vector3 v;
   
//    float n{1};
//    float f{30};
//    float fFov{1/tan(3.14159f/4)};

//    v.x = in.x*(fFov/in.z);
//    v.y = aspect*in.y*(fFov/in.z);
//    v.z = in.z*(-f/(f-n)) - (f*n)/(f-n);

//    return v;
// }

int main()
{
   WindowManager WinManager(600, 400, "my window!");

   Vector3 p1(0.0, 0.0, -1.0);
   Vector3 p2(0.0, 0.2, -1.0);
   Vector3 p3(0.2, 0.0, -1.0);
   std::cout << "made points" << std::endl;   
   Triple front1(p1, p2, p3);
   std::cout << "made triple" << std::endl;
   Mesh mesh;
   std::cout << "made mesh" << std::endl;   
   mesh.addTri(front1);
   std::cout << "added tri to mesh" << std::endl;
   
   MeshManager meshMgr(&WinManager);
   meshMgr.addMesh(mesh);
   std::cout << "added mesh to mesh manager" << std::endl;   
   
   // Vector3 square1[4];
   // Vector3 square1Proj[4];
   // Vector3 square2[4];
   // Vector3 square2Proj[4];   

   // square1[0] = Vector3(-0.3, -0.3, -1.3);
   // square1[1] = Vector3(-0.3, 0.3, -1.3);
   // square1[2] = Vector3(0.3, 0.3, -1.3);
   // square1[3] = Vector3(0.3, -0.3, -1.3);

   // square1Proj[0] = Vector3(-0.3, -0.3, -1.3);
   // square1Proj[1] = Vector3(-0.3, 0.3, -1.3);
   // square1Proj[2] = Vector3(0.3, 0.3, -1.3);
   // square1Proj[3] = Vector3(0.3, -0.3, -1.3);   
   
   // square2[0] = Vector3(-0.3, -0.3, -1.9);
   // square2[1] = Vector3(-0.3, 0.3, -1.9);
   // square2[2] = Vector3(0.3, 0.3, -1.9);
   // square2[3] = Vector3(0.3, -0.3, -1.9);

   // square2Proj[0] = Vector3(-0.3, -0.3, -1.9);
   // square2Proj[1] = Vector3(-0.3, 0.3, -1.9);
   // square2Proj[2] = Vector3(0.3, 0.3, -1.9);
   // square2Proj[3] = Vector3(0.3, -0.3, -1.9);

   while (!glfwWindowShouldClose(WinManager.window))
   {
   //    square1[0] = Rotate(square1[0], 0.01, Vector3(0.0, 0.0, -1.6), 3);
   //    square1[1] = Rotate(square1[1], 0.01, Vector3(0.0, 0.0, -1.6), 3);
   //    square1[2] = Rotate(square1[2], 0.01, Vector3(0.0, 0.0, -1.6), 3);
   //    square1[3] = Rotate(square1[3], 0.01, Vector3(0.0, 0.0, -1.6), 3);

   //    square2[0] = Rotate(square2[0], 0.01, Vector3(0.0, 0.0, -1.6), 3);
   //    square2[1] = Rotate(square2[1], 0.01, Vector3(0.0, 0.0, -1.6), 3);
   //    square2[2] = Rotate(square2[2], 0.01, Vector3(0.0, 0.0, -1.6), 3);
   //    square2[3] = Rotate(square2[3], 0.01, Vector3(0.0, 0.0, -1.6), 3);
      
   //    square1Proj[0] = MapToScreen(square1[0], WinManager.windowAspectRatio);
   //    square1Proj[1] = MapToScreen(square1[1], WinManager.windowAspectRatio);
   //    square1Proj[2] = MapToScreen(square1[2], WinManager.windowAspectRatio);
   //    square1Proj[3] = MapToScreen(square1[3], WinManager.windowAspectRatio);

   //    square2Proj[0] = MapToScreen(square2[0], WinManager.windowAspectRatio);
   //    square2Proj[1] = MapToScreen(square2[1], WinManager.windowAspectRatio);
   //    square2Proj[2] = MapToScreen(square2[2], WinManager.windowAspectRatio);
   //    square2Proj[3] = MapToScreen(square2[3], WinManager.windowAspectRatio);


      
      
      WinManager.beginRender();
      meshMgr.Render();

      // glBegin(GL_LINES);

      // for (unsigned int i = 0; i < 4; i++)
      // {
         // glVertex3f(square1Proj[i%4].x, square1Proj[i%4].y, square1Proj[i%4].z);
         // glVertex3f(square1Proj[(i+1)%4].x, square1Proj[(i+1)%4].y, square1Proj[(i+1)%4].z);

         // glVertex3f(square2Proj[i%4].x, square2Proj[i%4].y, square2Proj[i%4].z);
         // glVertex3f(square2Proj[(i+1)%4].x, square2Proj[(i+1)%4].y, square2Proj[(i+1)%4].z);         
      // }

      // glVertex3f(square1Proj[1].x, square1Proj[1].y, square1Proj[1].z);
      // glVertex3f(square1Proj[3].x, square1Proj[3].y, square1Proj[3].z);

      // glVertex3f(square2Proj[1].x, square2Proj[1].y, square2Proj[1].z);
      // glVertex3f(square2Proj[3].x, square2Proj[3].y, square2Proj[3].z);      
      // glEnd();

      WinManager.finishRender();
   } 

   return 0;
}
