/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP_tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:36:16 by yabokhar          #+#    #+#             */
/*   Updated: 2025/09/11 13:37:09 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>

static void print_error_and_exit_failure(void);

int main(void)
{
    std::string line;
    float point_coords[8];

    if (!std::getline(std::cin, line))
		return (1);
	std::cout << line << std::endl;
    if (!std::getline(std::cin, line))
        return (1);

    char *c_string_cus_im_idiot = strdup(line.c_str());
    for (uint8_t i = 0; i < 8; i++)
        point_coords[i] = strtof(c_string_cus_im_idiot, &c_string_cus_im_idiot);

    if (SDL_Init(SDL_INIT_VIDEO) ^ 0)
        print_error_and_exit_failure();

    SDL_Window *window = SDL_CreateWindow(
        "BSP_tester",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 600,
        SDL_WINDOW_SHOWN
    );
    if (!window)
        print_error_and_exit_failure();

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        print_error_and_exit_failure();

    const std::vector<SDL_Vertex> triangle_points_coords =
    {
        { SDL_FPoint{point_coords[0], point_coords[1]}, SDL_Color{30,144,255,255}, SDL_FPoint{0, 0} },
        { SDL_FPoint{point_coords[2], point_coords[3]}, SDL_Color{30,144,255,255}, SDL_FPoint{0, 0} },
        { SDL_FPoint{point_coords[4], point_coords[5]}, SDL_Color{30,144,255,255}, SDL_FPoint{0, 0} },
    };

    SDL_FRect rect = {point_coords[6], point_coords[7], 2, 2};

    bool running = true;
    while (running)
    {
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
               	running = false;
            if (ev.type == SDL_KEYDOWN && ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                running = false;
        }
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderGeometry(renderer, nullptr, triangle_points_coords.data(), 3, nullptr, 0);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRectF(renderer, &rect);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

static void print_error_and_exit_failure(void)

{
	std::cerr << SDL_GetError() << std::endl;
	exit(1);
}
