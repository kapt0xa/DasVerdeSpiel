#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <boost/qvm_lite.hpp>

using Vec2f = boost::qvm::vec<float, 2>;
using Vec3f = boost::qvm::vec<float, 3>;
using Vec4f = boost::qvm::vec<float, 4>;

using Vec2i = boost::qvm::vec<int, 2>;
using Vec3i = boost::qvm::vec<int, 3>;
using Vec4i = boost::qvm::vec<int, 4>;

using Mat2f = boost::qvm::mat<float, 2, 2>;
using Mat3f = boost::qvm::mat<float, 3, 3>;
using Mat4f = boost::qvm::mat<float, 4, 4>;

using Mat2i = boost::qvm::mat<int, 2, 2>;
using Mat3i = boost::qvm::mat<int, 3, 3>;
using Mat4i = boost::qvm::mat<int, 4, 4>;

using Quat = boost::qvm::quat<float>;

class Mesh
{
private:
    std::vector<Vec3f> verts;
    std::vector<Vec3i> triangles;
    std::vector<Vec3f> colors;
public:
    inline int AddVert(const Vec3f& v, const Vec3f& c = Vec3f{1.0f, 0.0f, 1.0f})
    {
        verts.push_back(v);
        colors.push_back(c);
        return static_cast<int>(verts.size()) - 1;
    }
    inline int AddTriangle(const Vec3i& tri)
    {
        triangles.push_back(tri);
        return static_cast<int>(triangles.size()) - 1;
    }
    inline void PopVert()
    {
        if(verts.empty())
            {return;}
        verts.pop_back();
        colors.pop_back();
    }
    inline void PopTriangle()
    {
        if(triangles.empty())
            {return;}
        triangles.pop_back();
    }
    inline int VertCount() const
    {
        return static_cast<int>(verts.size());
    }
    int TriangleCount() const
    {
        return static_cast<int>(triangles.size());
    }

    inline void Render() const
    {
        for(const auto& tri : triangles)
        {
            for(int i = 0; i < 3; ++i)
            {
                const auto& v = verts[tri.a[i]];
                const auto& c = colors[tri.a[i]];
                glColor3f(c.a[0], c.a[1], c.a[2]);
                glVertex3f(v.a[0], v.a[1], v.a[2]);
            }
        }
    }
};
