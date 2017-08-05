#include "LaniaEngine.hpp"

using namespace Lania;

void LaniaEngine::initialize()
{
	timer.initialize();

	runtime.windowTitle = "Lania Engine";
	runtime.aspectRatio = (16.0 / 9.0);
	runtime.windowHeightPixels = 480;
	runtime.windowWidthPixels = (int)(runtime.windowHeightPixels * 
		runtime.aspectRatio);
	runtime.targetFPS = 60;
	runtime.state = GAMEPLAY;
	runtime.frameCount = 1;
	runtime.isRunning = true;

	performance.passedFrames = 0;
	performance.fpsRefreshDelay = 1.0;

	const char *title = runtime.windowTitle.c_str();

	if (SDL_Init(SDL_INIT_EVERYTHING))
		SDL_Log("SDL could not initialize because: %s", SDL_GetError());

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		runtime.windowWidthPixels,
		runtime.windowHeightPixels,
		SDL_WINDOW_OPENGL);

	if (window == NULL)
		SDL_Log("SDL could not create the window because: %s", SDL_GetError());

	context = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1);
}

void LaniaEngine::runSimulationLoop()
{
	do
	{
		messages = eventSystem.handleSDLEvents();

		runtime.isRunning = messages.isRunning;
		*inputSystem.keyboardBuffer = *messages.keyboardBuffer;

		timer.updateCurrentTime();
		timer.updateEngineTime();

		if (runtime.state != PAUSED)
		{
			timer.updateSimulationTime(runtime.frameCount,
				runtime.targetFPS);
			//Script, processing and runtime to be added.
			runtime.frameCount++;
			performance.passedFrames++;
		}

		if (timer.calculateElapsedTime() >= performance.fpsRefreshDelay)
		{
			performance.calculateFPS(timer.currentTime, timer.sampledTime);
			performance.passedFrames = 0;
			timer.updateSampledTime();
		}

		/*Outputs and processing lists.*/
		console.printFPS(performance.FPS);
		SDL_GL_SwapWindow(window);
		timer.idle((int)(1000 / runtime.targetFPS));

	} while (runtime.isRunning);
}

void LaniaEngine::shutdown()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
