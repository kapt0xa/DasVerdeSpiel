#include "glfw.h"
#include "mesh.h"

int main()
{
    Mesh mesh;
    mesh.AddVert(Vec3f{-0.5f, -0.5f, 0.0f}, Vec3f{1.0f, 0.0f, 0.0f}); // Red
    mesh.AddVert(Vec3f{0.5f, -0.5f, 0.0f}, Vec3f{0.0f, 1.0f, 0.0f});  // Green
    mesh.AddVert(Vec3f{0.0f, 0.5f, 0.0f}, Vec3f{0.0f, 0.0f, 1.0f});   // Blue
    mesh.AddTriangle(Vec3i{0, 1, 2});

    auto app = GLFW();
    while(app.Loop([&mesh](){
        mesh.Render();
    }));
    return 0;
}
