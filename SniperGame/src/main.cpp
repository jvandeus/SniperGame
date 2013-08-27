/* ------------------------------------------------------------------------ */
/* Project Name - SniperGame												*/
/* Author - Joe Van Deusen													*/
/*																			*/
/* This is a game made using SDL 2.0.0. The inspiration for this project 	*/
/* is games such as Material Sniper. The player will shoot various as if	*/
/* They were a stationary sniper shooting from a distance. This is a small  */
/* project focused on learning SDL and game programming with possible 		*/
/* expansion in the future into a full independant game.					*/
/* The project uses the following extensions to SDL as well:				*/
/* SDL2_image-2.0.0, SDL2_mixer-2.0.0, SDL2_ttf-2.0.12						*/
/*																			*/
/* There is no current functionality as of yet.							 	*/
/* Current goals include the following:										*/
/* - Custom cursor to facilitate crosshair and/or scope.					*/
/* - Background gets a "scoped" or "zoomed" effect, in a circular shape		*/
/* - After this is acheived, other sprites and should also be zoomed in the	*/
/*	 scoped circle when hovering over location with the mouse.				*/
/* - Clicking the mouse simulates firing the projectile.					*/
/* - Other generally usefull effects such as outlining a sprite in a 		*/
/*   certain color to show focus or that they are behing an object.			*/
/* - Possible line effect similar to Legend of Dragoon For reloading or 	*/
/*   combos of some kind. This means that lines come from outside the		*/
/*   screen to center in on a target.										*/
/*																			*/
/* This  has the subsystem Console by default for debug proposes.			*/
/* change the subsytem for all configurations to windows when distributing.	*/
/* This is set to x86 architecture. Running may require the runtime			*/
/* to be added to the executable's directory, Found in the					*/
/* SDL2-2.0.0-win32-x86 folder												*/
/*																			*/
/* ------------------------------------------------------------------------ */

#include "library.h"

void clean_up(){	
	//Call functions to clean up resources used in objects
	SDL_Quit();
}

int main(int argc, char **argv){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		//std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		logSDLError(std::cout, "SDL_Init");
		return 1;
	}
	std::string caption = PROJECT_NAME + " - testing";
	SDL_Window *window = SDL_CreateWindow(caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	//for a Fullscreen reselution with a scaled up window, use: 
	/*
	SDL_Window *window = SDL_CreateWindow(caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0,
		SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(sdlRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	*/
	if (window == nullptr){
		//std::cout << "CreateWindow Error: " << SDL_GetError() << std::endl;
		logSDLError(std::cout, "CreateWindow");
		return 2;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		logSDLError(std::cout, "CreateRenderer");
		return 3;
	}

	// Create background
	SDL_Texture *background = loadTexture(IMG_PATH+"bgGrid16by16.bmp", renderer);
	
	// Create black image
	SDL_Texture *black = loadTexture(IMG_PATH+"black.bmp", renderer);

	//If something went wrong, escape with error.
	if (background == nullptr || black == nullptr){
		return 4;
	}

	//Clear the screen to black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	//get dimentions of image and store for render of background
	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	//render texture at postion 0,0 - top left.
	renderTexture(background, renderer, 0, 0);

	//Draw Black Square in front
	int iW, iH;
	SDL_QueryTexture(black, NULL, NULL, &iW, &iH);
	//set coordinated to middle of the screen
	int x = SCREEN_WIDTH / 2 - iW / 2;
	int y = SCREEN_HEIGHT / 2 - iH / 2;
	//render at middle
	renderTexture(black, renderer, x, y);

	//Attempt to Draw a rhombus, usining the SDL draw lines functions
	SDL_Point corners[5];
	corners[0].x = SCREEN_WIDTH/2;
	corners[1].x = SCREEN_WIDTH;
	corners[2].x = SCREEN_WIDTH/2;
	corners[3].x = 0;
	corners[4].x = SCREEN_WIDTH/2;
	corners[0].y = 0;
	corners[1].y = SCREEN_HEIGHT/2;
	corners[2].y = SCREEN_HEIGHT;
	corners[3].y = SCREEN_HEIGHT/2;
	corners[4].y = 0;
	//Set the color of the line to green and render.
	SDL_SetRenderDrawColor(renderer, 0, 225, 0, 255);
	SDL_RenderDrawLines(renderer, corners, 5);

	//present the Frame to the screen
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	//Clean up resources
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(black);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	clean_up();
	
	return 0;
}