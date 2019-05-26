// test_1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "SDL.h"
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	const Sint16 width = 640, height = 480;
	double x1, x2, x, y, y1, y2;
	Sint16 x0scr, y0scr, xscr, yscr;
	double dx, mx, my;

	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter x2: ";
	cin >> x2;

	y1 = (1 / sin(exp(x1)));
	y2 = (1 / sin(exp(x2)));
	dx = 0.0001;//(abs(x2 - x1))/(width*100);
	mx = 490;//width / abs(x2 - x1);
	my = 90;//height / abs(y2 - y1);
	x0scr = floor(-1*x1 * mx);
	y0scr = height/2;

	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;
			while (!done) {
				SDL_Event event;
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

				for (int i = 0; i < width; i++) {
					SDL_RenderDrawPoint(renderer,width/2, i);
					SDL_RenderDrawPoint(renderer,i, height/2);
				}

				SDL_SetRenderDrawColor(renderer, 5, 255, 255, SDL_ALPHA_OPAQUE);

				for (x = x1; x <= x2; x+=dx) {
					if ((fabs(x) - 1e-4) > 0) { /*исключение нуля */ 
							y = (1 / sin(exp(x)));
							xscr = x0scr + floor(x * mx);
							yscr = y0scr - floor(y * my);

							if (0 <= xscr && xscr < width && 0 <= yscr && yscr < height) {
								SDL_RenderDrawPoint(renderer, xscr, yscr);
							}
						}
				}
				SDL_RenderPresent(renderer);
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
					}
				}
			}
		}
		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	return 0;
}

