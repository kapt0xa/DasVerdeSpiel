#include "my_GLFW/glfw.h"

#include <vector>

int GlfwTestCode();

;

int main()
{
    auto app = GLFW();
    while(app.Loop([](){
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex2f(0.5f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex2f(0.0f, 0.5f);
    }));
    return 0;
}
