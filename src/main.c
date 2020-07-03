/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/02 22:38:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state)
{
	game_state->active = true;
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	int				i;
	SDL_Rect		dest;

	i = 0;
	dest.h = 15;
	dest.w = 12;
	dest.x = 100;
	dest.y = 10;

	SDLU_start(&display);
	game_context_initialize(&game_state);
	while (game_state.active == true)
	{
		process_user_input(&game_state);

		// update_game_state(&game_state);
		itow(i, dest, &display);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);
		i++;
	}
	SDLU_close(&display);
	return (0);
}
