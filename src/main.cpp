// #include "testOpenGL.cpp"

#include "testVector3.cpp"
// #include "testMatrix3.cpp"

#include "unistd.h"
#include "WindowManager.h"
#include "Rotation.h"
#include "math.h"
#include "MeshManager.h"

int main()
{
   WindowManager WinManager(600, 400, "my window!");

   Vector3 boxCenter(0.0, 0.0, 3.0);
   float width{1.0};
   float height{1.0};
   float depth{1.0};
   
   MeshManager meshMgr(&WinManager);   
   meshMgr.addBox(boxCenter, width, height, depth, "box");
   while (!glfwWindowShouldClose(WinManager.window))
   {
      float currTime = glfwGetTime();
      WinManager.beginRender();
      meshMgr.Translate("box", Vector3(0.05*sin(6*currTime*0.5),
                                       0.05*cos(6*currTime*0.5),
                                       0.0));
      // meshMgr.Scale("box", 1.001);
      // meshMgr.Rot("box", 0.05, 2);
      // meshMgr.Rot("box", 0.025, 1);       
      meshMgr.Render();
      WinManager.finishRender();
   } 

   return 0;
}
