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

   MeshManager meshMgr(&WinManager);   
   Mesh mesh;

   Vector3 fbl(-0.2, -0.2, -1.0);
   Vector3 fbr(0.2, -0.2, -1.0);
   Vector3 ftl(-0.2, 0.2, -1.0);
   Vector3 ftr(0.2, 0.2, -1.0);
   Vector3 rbl(-0.2, -0.2, -1.4);
   Vector3 rbr(0.2, -0.2, -1.4);
   Vector3 rtl(-0.2, 0.2, -1.4);
   Vector3 rtr(0.2, 0.2, -1.4);
   
   Triple front1(fbl, ftl, fbr);
   mesh.addTri(front1);

   Triple front2(ftl, ftr, fbr);
   mesh.addTri(front2);

   Triple right1(fbr, ftr, rbr);
   mesh.addTri(right1);

   Triple right2(ftr, rtr, rbr);
   mesh.addTri(right2);

   Triple back1(rbr, rtr, rbl);
   mesh.addTri(back1);

   Triple back2(rtr, rtl, rbl);
   mesh.addTri(back2);

   Triple left1(rbl, rtl, fbl);
   mesh.addTri(left1);

   Triple left2(rtl, ftl, fbl);
   mesh.addTri(left2);

   Triple top1(ftl, rtl, ftr);
   mesh.addTri(top1);

   Triple top2(rtl, rtr, ftr);
   mesh.addTri(top2);

   Triple bottom1(rbl, fbl, rbr);
   mesh.addTri(bottom1);

   Triple bottom2(fbl, fbr, rbr);
   mesh.addTri(bottom2);      
   
   meshMgr.addMesh(mesh);

   while (!glfwWindowShouldClose(WinManager.window))
   {
      WinManager.beginRender();
      meshMgr.Rot();
      meshMgr.Render();
      WinManager.finishRender();
   } 

   return 0;
}
