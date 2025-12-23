#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <functional>

class GLFW
{
private:
    GLFWwindow* window;
    int width;
    int height;
    std::string title;
public:
    inline GLFW(int w = 854, int h = 480, const std::string& t = "GLFW Window")
        : width(w), height(h), title(t)
    {
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            throw std::runtime_error("GLFW Initialization Failed");
        }

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            std::cerr << "Failed to create GLFW window" << std::endl;
            throw std::runtime_error("GLFW Window Creation Failed");
        }

        glfwMakeContextCurrent(window);
    }
    inline ~GLFW()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    inline bool Loop(const std::function<void()> renderCallback)
    {
        if(glfwWindowShouldClose(window))
            {return false;}
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
            renderCallback();
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        return true;
    }

    GLFW(const GLFW&) = delete;
    GLFW& operator=(const GLFW&) = delete;
    GLFW(GLFW&&) = delete;
    GLFW& operator=(GLFW&&) = delete;
};