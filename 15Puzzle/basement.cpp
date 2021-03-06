#include "basement.h"

const string WINDOW_TITLE = "15 puzzle";

void logSDLError(ostream& os, const string& msg, bool fatal) {
	os << msg << "Error: " << SDL_GetError() << endl;
	if (fatal) {
		SDL_Quit();
		exit(1);
	}
}

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		logSDLError(cout, "SDL_Init", true);
	window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) logSDLError(cout, "Create Window", true);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if (renderer == nullptr) logSDLError(cout, "Create Renderer", true);
	//music
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) logSDLError(cout, "Mixer", true);
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}