#ifndef MESH_MANAGER_HPP
#define MESH_MANAGER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "WindowManager.h"
#include "Vector3.h"
#include "Rotation.h"

struct Triple
{
   // CONSTRUCTORS
   Triple();
   Triple(Vector3 in1, Vector3 in2, Vector3 in3);

   ~Triple();

   // UTILITY FUNCTIONS
   void Render();
   void Update();
   void Update(Triple in);

   void Scale(float in);
   void Translate(Vector3 in);
   void Rot(float angle, unsigned int axis);
   void Rot(float angle, Vector3 rotPoint, unsigned int axis);
   
   // DATA
   Vector3 p1;
   Vector3 p2;
   Vector3 p3;

   Vector3 center;
   Vector3 normal;
};

struct Mesh
{
   // CONSTRUCTORS
   Mesh();
   Mesh(std::string nameIn);
   Mesh(std::vector<Triple> trisIn, std::string nameIn);
   /* Mesh(char* filePath, char* name); */

   /* ~Mesh(); */
   // UTILITY FUNCTIONS
   void Render();
   void Update();
   void addTri(Triple tri);

   void Scale(float in);
   void Translate(Vector3 in);
   void Rot(float angle, unsigned int axis);
   void Rot(float angle, Vector3 rotPoint, unsigned int axis);   

   /* void loadMesh(char* filePath, char* name);    */

   // DATA
   unsigned int triCount;
   Triple tris[1000];
   Vector3 center;
   std::string name;
};

struct MeshManager
{
   // Constructors
   /* MeshManager(); */
   /* MeshManager(std::vector<char*> meshPaths); */
   MeshManager(WindowManager* winMgr);
   /* MeshManager(/\* WindowManager* winMgr, *\/ std::vector<Mesh> meshesIn); */

   /* ~MeshManager(); */
   // Utility Functions
   void Project();
   /* void Clip(); */
   /* void DepthClip(); */
   void Render();
   
   void Scale(std::string meshName, float in);
   void Translate(std::string meshName, Vector3 in);
   void Rot(std::string meshName, float angle, unsigned int axis);
   void Rot(std::string meshName, float angle, Vector3 rotPoint, unsigned int axis);   
   void addMesh(Mesh in);
   void addBox(Vector3 center, float width, float height, float depth, std::string name);

   // DATA
   WindowManager *winManager{nullptr};
   unsigned int meshCount;
   Mesh meshes[10];
   std::vector<std::string> meshNames;
   Mesh projMeshes[10];
   /* Mesh clipMeshes[10]; */
   /* Mesh depthClipMeshes[256]; */
};
#endif


