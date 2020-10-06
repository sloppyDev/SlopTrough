#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <GLFW/glfw3.h>
#include "GraphicsConstants.h"

struct WindowManager
{
   // CONSTRUCTORS
   WindowManager();
   WindowManager(unsigned int windowSize);
   WindowManager(unsigned int windowSize, const char* name);   
   WindowManager(unsigned int width, unsigned int height);
   WindowManager(unsigned int width, unsigned int height, const char* name);
   ~WindowManager();

   // RENDERING FUNCTIONS
   void beginRender();
   void finishRender();

   // CALLBACKS
   static void errorCallback(int error, const char *description);
   static void closeKeyCallback(GLFWwindow *window, int key,
                                int scancode, int action, int mods);
   // MEMBER VARIABLES
   GLFWwindow *window;
   
   int windowWidth;
   int windowHeight;
   float windowAspectRatio;
   float windowFOV;
   char* windowName;
   
};

#endif
