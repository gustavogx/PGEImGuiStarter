# PGEImGuiStarter
A starter project with olcPixelGameEngine, DearImGui and olcPGEDearImGui as submodules. 
        https://github.com/ocornut/imgui v. 1.88
        https://github.com/OneLoneCoder/olcPixelGameEngine v. 2.17
        https://github.com/dandistine/olcPGEDearImGui

and all requirements therein, such as an OpenGL implementation (like mesa).

Don't forget to clone the submodules as well:

    git clone --recurse-submodules https://github.com/gustavogx/PGEImGuiStarter 

Under linux, you may compile it like this:

$ g++ -o example \
    example.cpp \
    modules/imgui/imgui.cpp \
    modules/imgui/imgui_demo.cpp \
    modules/imgui/imgui_draw.cpp \
    modules/imgui/imgui_widgets.cpp \
    modules/imgui/imgui_tables.cpp \
    modules/imgui/backends/imgui_impl_opengl2.cpp \
    -Imodules/imgui -Imodules/imgui/backends \
    -Imodules/olcPGEDearImGui \
    -Imodules/olcPixelGameEngine \
    -lX11 -lGL -lpthread -lpng -lstdc++fs \
    -std=c++17 -O3

OR just
$ source compile.sh

Before using it, please consult the Licences on each submodule.
