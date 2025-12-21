#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <functional>

// https://www.glfw.org/documentation.html
int GlfwTestCode();

int main()
{
    return GlfwTestCode();
}

int GlfwTestCode()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Das verde (werde) Spiel!", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); // Red
            glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 1.0f, 0.0f); // Green
            glVertex2f(0.5f, -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f); // Blue
            glVertex2f(0.0f, 0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

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
    inline bool Loop(std::function<void()> renderCallback)
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