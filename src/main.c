/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/03 20:52:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state, t_display *display)
{
	game_state->active = true;

	game_state->texture = IMG_LoadTexture(display->renderer, "resources/flappy_bird.png");
	game_state->src_rect = carve_flappy_bird_texture();

	game_state->pipe_capacity = 10;
	game_state->current_pipe_amount = 0;

	game_state->pipes = malloc(sizeof(*(game_state->pipes)) * (10));
	bzero(game_state->pipes, sizeof(*(game_state->pipes)) * (10));
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	SDL_Rect		dest;

	dest.h = 15;
	dest.w = 12;
	dest.x = 100;
	dest.y = 10;

	SDLU_start(&display);
	game_context_initialize(&game_state, &display);

	game_state.pipes[1].active = true;
	game_state.pipes[1].loc_x = 400;
	game_state.pipes[1].loc_y = 400;

	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game_state(&game_state);
		draw_pipes(&(game_state), &(display));

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

	}
	SDLU_close(&display);
	return (0);
}
