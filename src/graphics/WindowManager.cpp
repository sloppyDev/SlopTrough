#include <stdlib.h>
#include <stdio.h>
#include "WindowManager.hpp"

#define DEFAULT_HEIGHT 400
#define DEFAULT_WIDTH  600

// CONSTRUCTORS
WindowManager::WindowManager()
{
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
   float ratio;
   int width, height;

   glfwGetFramebufferSize(window, &width, &height);
   ratio = width/(float(height));

   glViewport(0, 0, width, height);
   glClear(GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
   glMatrixMode(GL_MODELVIEW);
}

void WindowManager::finishRender()
{
   glfwSwapBuffers(window);
   glfwPollEvents();
}

