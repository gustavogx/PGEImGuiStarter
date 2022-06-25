/****************************************************************************************
 An "Hello world" example of the DearImGui implementation for the olc::PixelGameEngine
 by Dandistine, available at https:github.com/dandistine/olcPGEDearImGui
 If you found this in a fork repository, please acknowledge the original author.

 This example requires the following sources (and is compatible with the versions)
       https:github.com/ocornut/imgui v. 1.86
       https:github.com/OneLoneCoder/olcPixelGameEngine v. 2.16
 and all requirements therein, such as an OpenGL implementation (like mesa).

 Clone DearImGui source in a folder (imgui) alongside this example.
 From the PGE, you just need olcPixelGameEngine.h

 Your folder should look like this:

 imgui
 compile.sh
 example.cpp
 imgui_impl_pge.h
 olcPixelGameEngine.h

 Under linux, you may compile it like this:
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

 Based on original example by Dandistine (author of imgui_impl_pge.h)
 If you choose to bind the drawing functions yourself, follow the in-code comments.
 ****************************************************************************************/

#include "imgui.h"
#include "imgui_internal.h"
#include "imstb_rectpack.h"
#include "imstb_textedit.h"
#include "imstb_truetype.h"
#include "imgui_impl_opengl2.h"

#define OLC_PGEX_DEAR_IMGUI_IMPLEMENTATION
#define PGE_GFX_OPENGL33
#include "imgui_impl_pge.h"

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine
{
	olc::imgui::PGE_ImGUI mImGui;
	std::uint8_t mGameLayer;

public:
	
	// PGE_ImGui can automatically call the SetLayerCustomRenderFunction by passing true into the constructor.  
	// false is the default value.
	Example() : mImGui(true)
	{
		sAppName = "Dear ImGui Demo";
	}

public:

	bool OnUserCreate() override
	{

		//Create a new Layer which will be used for the game
		mGameLayer = CreateLayer();

		//The layer is not enabled by default,  so we need to enable it
		EnableLayer(mGameLayer, true);

		//Set a custom render function on layer 0.  Since DrawUI is a member of
		//our class, we need to use std::bind
		//If the mImGui was constructed with _register_handler = true, this line is not needed (see lines 61 and 100)
		//SetLayerCustomRenderFunction(0, std::bind(&Example::DrawUI, this));

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		//Change the Draw Target to not be Layer 0
		SetDrawTarget(mGameLayer);
		
		//Game Drawing code here (called once per frame)
		//Lets fill the window with random noise
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));	

		//Create and react to your UI here, it will be drawn during the layer draw function
		ImGui::ShowDemoWindow();
		return true;
	}


/*
	// If the mImGui was constructed with _register_handler = true, this method is not needed (see lines 61 and 80)
	void DrawUI(void) {

		//This finishes the Dear ImGui and renders it to the screen
		mImGui.ImGui_ImplPGE_Render();
	}
*/

};

// Much like any PGE example
int main() {
	Example demo;
	if (demo.Construct(640, 360, 2, 2))
		demo.Start();
	return 0;
}
