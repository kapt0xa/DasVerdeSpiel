# Das verde Spiel

```
OpenGL for 3d-graphics
tutorial:
https://www.youtube.com/watch?v=OR4fNpBjmq8&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=2
documentation: docs.GL

Bullet Physics or NVIDIA PhysX for physics
```

# Modules

GLFW 3.4 https://www.glfw.org/ https://github.com/glfw/glfw

```
    open .gitirnore and ctrl+F(glfw). whats where the include folder should be. include itseld doesnt split into x64 and x86, it has .h files directly
    tutorial:
        https://www.glfw.org/docs/latest/quick.html,
        https://www.glfw.org/docs/latest/compile.html,
        glfw's readme: Ctrl+F(Compiling)
    reference actions:
        on ubuntu i followed the tutorial of building the lib https://www.glfw.org/docs/latest/compile.html
        i built files into folder {project root path}/glfw-3.4/build
        
        (not done yet)
        after i build the lib, i read "building applications" https://www.glfw.org/docs/latest/build_guide.html

        somehow it worked on ubuntu, i didnt write down exact steps. now i dont remember.
```

GLEW 2.1.0 https://glew.sourceforge.net/ 
aaah NVM i abanden this. i will use GLFW only for graphics 

```
    can not install. because even if i proceed documentation, GL/glu.h can not be found.

    read cmakelists.txt, there is written something about GLEW installation issues
    by default try this:
    documentation: https://glew.sourceforge.net/install.html
    use 'sudo make install' to run makefile provided by glew lib and install the lib.
    it will be available for the cmake's find_package

    for ubuntu - install additional libs via "sudo apt install ..." as in offitial documentation

    !!! i got some problems with GL/glu.h (didnt exist)
    but somehow i fixed the issues with "sudo apt install libglu1-mesa-dev"
```
