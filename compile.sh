#compile 
g++ -o example \
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