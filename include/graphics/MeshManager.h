#ifndef MESH_MANAGER_HPP
#define MESH_MANAGER_HPP

#include <vector>
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
   /* void Scale(Vector3 in);    */
   /* void Translate(Vector3 in); */
   /* void Rotate();  */
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
   Mesh(std::vector<Triple> trisIn, char* nameIn);
   /* Mesh(char* filePath, char* name); */

   /* ~Mesh(); */
   // UTILITY FUNCTIONS
   void Render();
   void addTri(Triple tri);
   /* void loadMesh(char* filePath, char* name);    */

   // DATA
   unsigned int triCount;
   Triple tris[1000];
   Vector3 center;
   char* name;
};

struct MeshManager
{
   // CONSTRUCTORS
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
   void addMesh(Mesh in);

   // DATA
   WindowManager *winManager{nullptr};
   unsigned int meshCount;
   Mesh meshes[10];
   Mesh projMeshes[10];
   /* Mesh clipMeshes[10]; */
   /* Mesh depthClipMeshes[256]; */
};
#endif


