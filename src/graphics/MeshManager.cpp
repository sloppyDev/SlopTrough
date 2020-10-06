#include <GLFW/glfw3.h>
#include "GraphicsConstants.h"
#include "MeshManager.h"

#include <iostream>
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
   // glColor3i(1.0, 1.0, 1.0);

   glVertex3f(p1.x, p1.y, p1.z);
   glVertex3f(p2.x, p2.y, p2.z);

   glVertex3f(p2.x, p2.y, p2.z);
   glVertex3f(p3.x, p3.y, p3.z);

   glVertex3f(p3.x, p3.y, p3.z);
   glVertex3f(p1.x, p1.y, p1.z);

   glEnd();
   glPointSize(3.0);   
   glBegin(GL_POINTS);

   glVertex3f(center.x, center.y, center.z);
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

void Triple::Rot()
{
   p1 = Rotate(p1, 0.01, Vector3(0.0, 0.0, -1.2),3);
   p2 = Rotate(p2, 0.01, Vector3(0.0, 0.0, -1.2),3);
   p3 = Rotate(p3, 0.01, Vector3(0.0, 0.0, -1.2),3);
   p1 = Rotate(p1, 0.01, Vector3(0.0, 0.0, -1.2),2);
   p2 = Rotate(p2, 0.01, Vector3(0.0, 0.0, -1.2),2);
   p3 = Rotate(p3, 0.01, Vector3(0.0, 0.0, -1.2),2);
   p1 = Rotate(p1, 0.01, Vector3(0.0, 0.0, -1.2),1);
   p2 = Rotate(p2, 0.01, Vector3(0.0, 0.0, -1.2),1);
   p3 = Rotate(p3, 0.01, Vector3(0.0, 0.0, -1.2),1);     


   Update();
}

//
// MESH
//
// CONSTRUCTORS
Mesh::Mesh()
{
   center = Vector3();
   triCount = 0;
}

Mesh::Mesh(std::vector<Triple> trisIn, char* nameIn)
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

void Mesh::Rot()
{
   for (unsigned int i{0}; i < triCount; i++)
   {
      tris[i].Rot();
   }
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
      projMeshes[i].Render();


      glBegin(GL_POINTS);
      glVertex3f(projMeshes[i].center.x,
                 projMeshes[i].center.y,
                 projMeshes[i].center.z);
      glEnd();
         
   }
}

void MeshManager::Project()
{
   for (unsigned int i{0}; i < meshCount; i++)
   {
      projMeshes[i].triCount = 0;
      for (unsigned int j{0}; j < meshes[i].triCount; j++)
      {
         Vector3 v1;
         Vector3 v2;
         Vector3 v3;         
         float fFov{1/tan(winManager->windowFOV/2)};

         // p1
         v1.x = -meshes[i].tris[j].p1.x*(fFov/meshes[i].tris[j].p1.z);
         v1.y = -winManager->windowAspectRatio*meshes[i].tris[j].p1.y*
            (fFov/meshes[i].tris[j].p1.z);
         v1.z = meshes[i].tris[j].p1.z*(-FAR_Z/(FAR_Z-NEAR_Z)) -
            (FAR_Z*NEAR_Z)/(FAR_Z-NEAR_Z);

         // p2
         v2.x = -meshes[i].tris[j].p2.x*(fFov/meshes[i].tris[j].p2.z);
         v2.y = -winManager->windowAspectRatio*meshes[i].tris[j].p2.y*
            (fFov/meshes[i].tris[j].p2.z);
         v2.z = meshes[i].tris[j].p2.z*(-FAR_Z/(FAR_Z-NEAR_Z)) -
            (FAR_Z*NEAR_Z)/(FAR_Z-NEAR_Z);

         // p3
         v3.x = -meshes[i].tris[j].p3.x*(fFov/meshes[i].tris[j].p3.z);
         v3.y = -winManager->windowAspectRatio*meshes[i].tris[j].p3.y*
            (fFov/meshes[i].tris[j].p3.z);
         v3.z = meshes[i].tris[j].p3.z*(-FAR_Z/(FAR_Z-NEAR_Z)) -
            (FAR_Z*NEAR_Z)/(FAR_Z-NEAR_Z);

         Triple projTri(v1, v2, v3);

         projMeshes[i].addTri(projTri);

      }
   }
}
// void Clip();
// void DepthClip();

void MeshManager::Rot()
{
   meshes[0].Rot();
}
void MeshManager::addMesh(Mesh in)
{
   meshes[meshCount] = in;
   meshCount++;
}
