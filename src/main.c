/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/10/27 01:03:46 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state, t_display *display)
{
	game_state->active = true;

	game_state->texture = IMG_LoadTexture(display->renderer, "resources/flappy_bird.png");
	game_state->src_rect = carve_flappy_bird_texture();

	game_state->ticks = 0;
	game_state->game_over = false;

	game_state->pipe_capacity = 10;
	game_state->current_pipe_amount = 0;

	game_state->pipes = malloc(sizeof(*(game_state->pipes)) * (10));
	bzero(game_state->pipes, sizeof(*(game_state->pipes)) * (10));

	game_state->player_animation = FLAPPY_MID;
	game_state->player_vel_y = 0;
	game_state->player_loc_y = 100;

	srand(time(NULL));
}

#include <unistd.h>

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	SDLU_start(&display);
	game_context_initialize(&game_state, &display);
	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game_state(&game_state);

		draw_pipes(&(game_state), &(display));
		draw_player(&(game_state), &(display));
		draw_score(&(game_state), &(display));

		if (game_state.game_over == true)
			draw_game_over(&(game_state), &(display));

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);
		usleep(GAME_TICK);
	}
	SDLU_close(&display);
	return (0);
}
