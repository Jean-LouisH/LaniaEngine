/**
*                          Lania Engine
*           https://jean-louish.github.io/LaniaEngine/
*
* Lania Engine, named after the Laniakea Supercluster
* (Hawaiian for "immeasurable heaven"), is a 2D/3D
* real-time simulation and game engine.
*
* Copyright (c) 2017-2018 Jean-Louis Haywood. All rights reserved.
* License: https://github.com/Jean-LouisH/LaniaEngine/blob/master/LICENSE
*/

#include "SDL.h"
#include <Rendering/GPU.hpp>
#include "Core/LaniaEngine.hpp"

int main(int argc, char* argv[])
{
	Lania::Core* core = new Lania::Core();
	Lania::Application* application = new Lania::Application();

	core->filepath = argv[0];
	
	Lania::initialize(core);
	if (core->state == Lania::RUNNING_APPLICATION)
		Lania::loop(core, application);
	Lania::shutdown(core, application);

	delete application;
	delete core;

	return 0;
}
