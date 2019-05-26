// test_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "SDL.h"
#include <cmath>
#define SHAPE_SIZE 200

int main(int argc, char* argv[])
{
	SDL_Window* Main_Window;
	SDL_Renderer* Main_Renderer;
	SDL_Surface* Loading_Surf;
	SDL_Texture* Background_Tx;
	SDL_Texture* BlueShapes;

	/* Rectangles for drawing which will specify source (inside the texture)
	and target (on the screen) for rendering our textures. */
	SDL_Rect SrcR;
	SDL_Rect DestR;

	int dx, dy;
	int width = 640;
	int height = 380;

	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = SHAPE_SIZE;
	SrcR.h = SHAPE_SIZE;

	DestR.x = 0;//640 / 2 - SHAPE_SIZE / 2;
	DestR.y = 0;// 580 / 2 - SHAPE_SIZE / 2;
	DestR.w = SHAPE_SIZE;
	DestR.h = SHAPE_SIZE;


	/* Before we can render anything, we need a window and a renderer */
	Main_Window = SDL_CreateWindow("SDL_RenderCopy Example",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	Main_Renderer = SDL_CreateRenderer(Main_Window, -1, SDL_RENDERER_ACCELERATED);

	/* The loading of the background texture. Since SDL_LoadBMP() returns
	a surface, we convert it to a texture afterwards for fast accelerated
	blitting. */
	Loading_Surf = SDL_LoadBMP("fon.bmp");
	Background_Tx = SDL_CreateTextureFromSurface(Main_Renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf); /* we got the texture now -> free surface */

	/* Load an additional texture */
	Loading_Surf = SDL_LoadBMP("fly.bmp");
	BlueShapes = SDL_CreateTextureFromSurface(Main_Renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);

	/* now onto the fun part.
	This will render a rotating selection of the blue shapes
	in the middle of the screen */
	int i;
	int n;

	for (i = 0; i < 400; ++i) {
		
		for (n = 0; n < 4; ++n) {
			dx = rand() % 10 + 1;
			dy = rand() % 20 + 1;

			SrcR.x = SHAPE_SIZE* (i % 2);
			DestR.x = (SHAPE_SIZE/2) + i + dx;
			if (n > 1) {
				SrcR.y = SHAPE_SIZE;
				DestR.y = (SHAPE_SIZE/4)*sin(n + dy);//SHAPE_SIZE + n + dy ;
			}
			else {
				SrcR.y = 0;
			}

			/* render background, whereas NULL for source and destination
			rectangles just means "use the default" */
			SDL_RenderCopy(Main_Renderer, Background_Tx, NULL, NULL);

			/* render the current animation step of our shape */
			SDL_RenderCopy(Main_Renderer, BlueShapes, &SrcR, &DestR);
			SDL_RenderPresent(Main_Renderer);
			SDL_Delay(20);
		}
	
	}

	SDL_DestroyTexture(BlueShapes);
	SDL_DestroyTexture(Background_Tx);
	SDL_DestroyRenderer(Main_Renderer);
	SDL_DestroyWindow(Main_Window);
	SDL_Quit();

	return 0;
}

