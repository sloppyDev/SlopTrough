#include <stdlib.h>
#include <stdio.h>
#include "WindowManager.hpp"

#define DEFAULT_HEIGHT 400
#define DEFAULT_WIDTH  600

// CONSTRUCTORS
WindowManager::WindowManager()
{
   windowWidth       = DEFAULT_WIDTH;
   windowHeight      = DEFAULT_HEIGHT;
   windowAspectRatio = windowWidth/(float)windowHeight;
   windowName        = (char*)"Window";
   
   glfwSetErrorCallback(errorCallback);
   
   if (!glfwInit())
   {
      exit(EXIT_FAILURE);
   }

   window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, "Window", NULL, NULL);

   if (!window)
   {
      glfwTerminate();
      exit(EXIT_FAILURE);
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, closeKeyCallback);

   
}

WindowManager::WindowManager(unsigned int windowSize)
{
   windowWidth       = windowSize;
   windowHeight      = windowSize;
   windowAspectRatio = windowWidth/(float)windowHeight;
   windowName        = (char*)"Window";
   
   glfwSetErrorCallback(errorCallback);
   
   if (!glfwInit())
   {
      exit(EXIT_FAILURE);
   }

   window = glfwCreateWindow(windowSize, windowSize, "Window", NULL, NULL);
   if (!window)
   {
      glfwTerminate();
      exit(EXIT_FAILURE);
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, closeKeyCallback);   
}

WindowManager::WindowManager(unsigned int windowSize, const char* name)
{
   windowWidth       = windowSize;
   windowHeight      = windowSize;
   windowAspectRatio = windowWidth/(float)windowHeight;
   windowName        = (char*)name;
   
   glfwSetErrorCallback(errorCallback);
   
   if (!glfwInit())
   {
      exit(EXIT_FAILURE);
   }

   window = glfwCreateWindow(windowSize, windowSize, name, NULL, NULL);
   if (!window)
   {
      glfwTerminate();
      exit(EXIT_FAILURE);
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, closeKeyCallback);   
}

WindowManager::WindowManager(unsigned int width, unsigned int height)
{
   windowWidth       = width;
   windowHeight      = height;
   windowAspectRatio = windowWidth/(float)windowHeight;
   windowName        = (char*)"Window";
   
   glfwSetErrorCallback(errorCallback);
   
   if (!glfwInit())
   {
      exit(EXIT_FAILURE);
   }

   window = glfwCreateWindow(width, height, "Window", NULL, NULL);
   if (!window)
   {
      glfwTerminate();
      exit(EXIT_FAILURE);
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, closeKeyCallback);   
}

WindowManager::WindowManager(unsigned int width, unsigned int height, const char* name)
{
   windowWidth       = width;
   windowHeight      = height;
   windowAspectRatio = windowWidth/(float)windowHeight;
   windowName        = (char*)name;
      
   glfwSetErrorCallback(errorCallback);
   
   if (!glfwInit())
   {
      exit(EXIT_FAILURE);
   }

   window = glfwCreateWindow(width, height, name, NULL, NULL);
   if (!window)
   {
      glfwTerminate();
      exit(EXIT_FAILURE);
   }

   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, closeKeyCallback);   
}

WindowManager::~WindowManager()
{
   glfwDestroyWindow(window);
   glfwTerminate();
   exit(EXIT_SUCCESS);
}

// CALLBACKS
void WindowManager::errorCallback(int error, const char* description)
{
   error++;
   fputs(description, stderr);
}

void WindowManager::closeKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
   scancode++;
   mods++;
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
   {
      glfwSetWindowShouldClose(window, GL_TRUE);
   }
}

// RENDERING FUNCTIONS
void WindowManager::beginRender()
{
   int width, height;

   glfwGetFramebufferSize(window, &width, &height);

   glViewport(0, 0, width, height);
   glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::finishRender()
{
   glfwSwapBuffers(window);
   glfwPollEvents();
}
