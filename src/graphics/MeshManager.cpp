#include <GLFW/glfw3.h>
#include "GraphicsConstants.h"
#include "MeshManager.h"

//
// TRIPLE
//
// CONSTRUCTORS
Triple::Triple()
{
   p1 = Vector3();
   p2 = Vector3();
   p3 = Vector3();

   Update();
}

Triple::Triple(Vector3 in1, Vector3 in2, Vector3 in3)
{
   p1 = in1;
   p2 = in2;
   p3 = in3;

   Update();
}

Triple::~Triple()
{
}

// UTILITY FUNCTIONS
void Triple::Render()
{
   glBegin(GL_LINES);

   glVertex2f(p1.x, p1.y);
   glVertex2f(p2.x, p2.y);

   glVertex2f(p2.x, p2.y);
   glVertex2f(p3.x, p3.y);

   glVertex2f(p3.x, p3.y);
   glVertex2f(p1.x, p1.y);

   glEnd();
}

void Triple::Update()
{
   // Get Center
   float cx;
   float cy;
   float cz;

   cx = (p1.x + p2.x + p3.x)/3;
   cy = (p1.y + p2.y + p3.y)/3;
   cz = (p1.z + p2.z + p3.z)/3;

   center = Vector3(cx, cy, cz);

   // Get Normal
   Vector3 v1 = p1 - p2;
   Vector3 v2 = p2 - p3;

   Vector3 normal_ = Cross(v1, v2);
   normal = normal_/Mag(normal_);
}

void Triple::Update(Triple in)
{
   // Change Coordinates
   p1 = in.p1;
   p2 = in.p2;
   p3 = in.p3;

   // Get Center
   float cx{};
   float cy{};
   float cz{};

   cx = (p1.x + p2.x + p3.x)/3;
   cy = (p1.y + p2.y + p3.y)/3;
   cz = (p1.z + p2.z + p3.z)/3;

   center = Vector3(cx, cy, cz);

   // Get Normal
   Vector3 v1 = p1 - p2;
   Vector3 v2 = p3 - p2;

   Vector3 normal_ = Cross(v1, v2);
   normal = normal_/Mag(normal_);
}

void Triple::Scale(float in)
{
   p1 = p1*in;
   p2 = p2*in;
   p3 = p3*in;

   Update();
}

void Triple::Translate(Vector3 in)
{
   p1 = p1 + in;
   p2 = p2 + in;
   p3 = p3 + in;

   Update();
}

void Triple::Rot(float angle, unsigned int axis)
{
   p1 = Rotate(p1, angle, axis);
   p2 = Rotate(p2, angle, axis);
   p3 = Rotate(p3, angle, axis);

   Update();
}

void Triple::Rot(float angle, Vector3 rotPoint, unsigned int axis)
{
   p1 = Rotate(p1, angle, rotPoint, axis);
   p2 = Rotate(p2, angle, rotPoint, axis);
   p3 = Rotate(p3, angle, rotPoint, axis);

   Update();
}

//
// MESH
//
// CONSTRUCTORS
Mesh::Mesh()
{
   name     = "Mesh";
   center   = Vector3();
   triCount = 0;
}

Mesh::Mesh(std::string nameIn)
{
   name     = nameIn;
   center   = Vector3();
   triCount = 0;
}

Mesh::Mesh(std::vector<Triple> trisIn, std::string nameIn)
{
   name = nameIn;

   for (Triple tri : trisIn)
   {
      tris[triCount] = tri;
      triCount++;
   }

   Update();
}

// Mesh::Mesh(char* filePath, char* name)
// {

// }

// UTILITY FUNCTIONS
void Mesh::Render()
{
   for (unsigned int i=0; i < triCount; i++)
   {
      tris[i].Render();
   }
}

void Mesh::Update()
{
   float cx{};
   float cy{};
   float cz{};
   for (unsigned int i{0}; i < triCount; i++)
   {
      cx += tris[i].center.x;
      cy += tris[i].center.y;
      cz += tris[i].center.z;

   }

   center = Vector3(cx/triCount, cy/triCount, cz/triCount);
}

void Mesh::Scale(float in)
{
   for (unsigned int i{0}; i < triCount; i++)
   {
      tris[i].Scale(in);
   }

   Update();
}
void Mesh::Translate(Vector3 in)
{
   for (unsigned int i{0}; i < triCount; i++)
   {
      tris[i].Translate(in);
   }

   Update();
}
void Mesh::Rot(float angle, unsigned int axis)
{
   for (unsigned int i{0}; i < triCount; i++)
   {
      tris[i].Rot(angle, center, axis);
   }

   Update();
}

void Mesh::Rot(float angle, Vector3 rotPoint, unsigned int axis)
{
   for (unsigned int i{0}; i < triCount; i++)
   {
      tris[i].Rot(angle, rotPoint, axis);
   }

   Update();
}

void Mesh::addTri(Triple tri)
{
   tris[triCount] = tri;
   triCount++;

   Update();
}
// void loadMesh(char* filePath, char* name);

//
// MESH MANAGER
//
// CONSTRUCTORS
MeshManager::MeshManager(WindowManager* winMgr)
{
   winManager = winMgr;
   meshCount = 0;
}

// MeshManager::MeshManager(// WindowManager* winMgr,
//                          std::vector<Mesh> meshesIn)
// {
//    // winManager = winMgr;
//    for (Mesh &meshIn: meshesIn)
//    {
//       meshes[meshCount] = meshIn;
//       meshCount++;
//    }
// }

// Utility Functions

void MeshManager::Render()
{
   Project();
   for (unsigned int i{0}; i < meshCount; i++)
   {
      // meshes[i].Render();
      projMeshes[i].Render();


      glBegin(GL_POINTS);
      // glVertex3f(meshes[i].center.x,
      //            meshes[i].center.y,
      //            meshes[i].center.z);
      glVertex3f(projMeshes[i].center.x,
                 projMeshes[i].center.y,
                 projMeshes[i].center.z);

      glEnd();

   }
}

void MeshManager::Project()
{
   float x;
   float y;
   float z;
   float aspect = winManager->windowAspectRatio;
   float fFov{1/tan(winManager->windowFOV/2)};
   float q = FAR_Z/(FAR_Z - NEAR_Z);
   Vector3 v1;
   Vector3 v2;
   Vector3 v3;
   
   for (unsigned int i{0}; i < meshCount; i++)
   {
      projMeshes[i].triCount = 0;
      for (unsigned int j{0}; j < meshes[i].triCount; j++)
      {
         // p1
         x = meshes[i].tris[j].p1.x;
         y = meshes[i].tris[j].p1.y;
         z = meshes[i].tris[j].p1.z;
         if (j == 0) std::cout << z << std::endl;
         if (j == 0) meshes[i].tris[j].p1.print();


         v1.x = aspect*x*fFov;
         v1.y = y*fFov;
         v1.z = (z*q - NEAR_Z*q);

         if (j == 0) v1.print();
         if (z != 0)
         {
            v1.x /= z;
            v1.y /= z;              
         }
         if (j == 0) v1.print();
         if (j == 0) std::cout << std::endl;
         // p2
         
         x = meshes[i].tris[j].p2.x;
         y = meshes[i].tris[j].p2.y;
         z = meshes[i].tris[j].p2.z;

         v2.x = aspect*x*fFov;
         v2.y = y*fFov;
         v2.z = (z*q - NEAR_Z*q);

         if (z != 0)
         {
            v2.x /= z;
            v2.y /= z;              
         }
         // p3
         x = meshes[i].tris[j].p3.x;
         y = meshes[i].tris[j].p3.y;
         z = meshes[i].tris[j].p3.z;

         v3.x = aspect*x*fFov;
         v3.y = y*fFov;
         v3.z = (z*q - NEAR_Z*q);

         if (z != 0)
         {
            v3.x /= z;
            v3.y /= z;              
         }
         
         Triple projTri(v1, v2, v3);

         projMeshes[i].addTri(projTri);

      }
   }
}
// void Clip();
// void DepthClip();

void MeshManager::Scale(std::string meshName, float in)
{
   unsigned int nameIdx;
   std::vector<std::string>::iterator itr = std::find(meshNames.begin(),
                                                      meshNames.end(),
                                                      meshName);
   if (itr != meshNames.cend())
   {
      nameIdx = std::distance(meshNames.begin(), itr);
      meshes[nameIdx].Scale(in);
   }
   else
   {
      std::cout << "Warning in MeshManager::Scale(): Mesh name" << meshName << " not found.\n";
   }
   
}

void MeshManager::Translate(std::string meshName, Vector3 in)
{
   unsigned int nameIdx;
   std::vector<std::string>::iterator itr = std::find(meshNames.begin(),
                                                      meshNames.end(),
                                                      meshName);
   if (itr != meshNames.cend())
   {
      nameIdx = std::distance(meshNames.begin(), itr);
      meshes[nameIdx].Translate(in);
   }
   else
   {
      std::cout << "Warning in MeshManager::Translate(): Mesh name" << meshName << " not found.\n";
   }
}

void MeshManager::Rot(std::string meshName, float angle, unsigned int axis)
{
   unsigned int nameIdx;
   std::vector<std::string>::iterator itr = std::find(meshNames.begin(),
                                                      meshNames.end(),
                                                      meshName);
   if (itr != meshNames.cend())
   {
      nameIdx = std::distance(meshNames.begin(), itr);
      meshes[nameIdx].Rot(angle, axis);
   }
   else
   {
      std::cout << "Warning in MeshManager::Rot(): Mesh name" << meshName << " not found.\n";
   }
}

void MeshManager::Rot(std::string meshName, float angle, Vector3 rotPoint, unsigned int axis)
{
   unsigned int nameIdx;
   std::vector<std::string>::iterator itr = std::find(meshNames.begin(),
                                                      meshNames.end(),
                                                      meshName);
   if (itr != meshNames.cend())
   {
      nameIdx = std::distance(meshNames.begin(), itr);
      meshes[nameIdx].Rot(angle, rotPoint, axis);
   }
   else
   {
      std::cout << "Warning in MeshManager::Rot(): Mesh name" << meshName << " not found.\n";
   }
}

void MeshManager::addMesh(Mesh in)
{
   meshes[meshCount] = in;
   meshNames.push_back(in.name);
   meshCount++;
}

void MeshManager::addBox(Vector3 center, float width, float height, float depth, std::string name)
{
   Mesh mesh(name);
   Vector3 fbl = Vector3(center.x - (width/2),
                         center.y - (height/2),
                         center.z - (depth/2));
   Vector3 ftl = Vector3(center.x - (width/2),
                         center.y + (height/2),
                         center.z - (depth/2));
   Vector3 ftr = Vector3(center.x + (width/2),
                         center.y + (height/2),
                         center.z - (depth/2));
   Vector3 fbr = Vector3(center.x + (width/2),
                         center.y - (height/2),
                         center.z - (depth/2));
   Vector3 rbr = Vector3(center.x + (width/2),
                         center.y - (height/2),
                         center.z + (depth/2));
   Vector3 rtr = Vector3(center.x + (width/2),
                         center.y + (height/2),
                         center.z + (depth/2));
   Vector3 rtl = Vector3(center.x - (width/2),
                         center.y + (height/2),
                         center.z + (depth/2));
   Vector3 rbl = Vector3(center.x - (width/2),
                         center.y - (height/2),
                         center.z + (depth/2));

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

   addMesh(mesh);
}
