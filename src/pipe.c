/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:09:41 by home              #+#    #+#             */
/*   Updated: 2020/07/03 22:38:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

#define PIPE_GAP (256)
#define HALF_GAP (PIPE_GAP / 2)

void	draw_pipe(t_game_context *game_state, t_display *display, t_pipe pipe)
{
	SDL_Rect	top_dest;
	SDL_Rect	bottom_dest;

	top_dest.x = pipe.loc_x;
	top_dest.y = 0;
	top_dest.w = TILE_SIZE;
	top_dest.h = pipe.loc_y - (HALF_GAP);
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[PIPE_BODY]), &(top_dest));
	top_dest.y = top_dest.h;
	top_dest.h = TILE_SIZE;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[PIPE_END]), &(top_dest));

	bottom_dest.x = pipe.loc_x;
	bottom_dest.y = pipe.loc_y + (HALF_GAP);
	bottom_dest.w = TILE_SIZE;
	bottom_dest.h = (WIN_HEIGHT) - bottom_dest.y;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[PIPE_BODY]), &(bottom_dest));
	bottom_dest.y -= TILE_SIZE;
	bottom_dest.h = TILE_SIZE;
	SDL_RenderCopyEx(display->renderer, game_state->texture, &(game_state->src_rect[PIPE_END]), &(bottom_dest), 0, NULL, SDL_FLIP_VERTICAL);
}

void	draw_pipes(t_game_context *game_state, t_display *display)
{
	int		i;
	t_pipe	*pipes;

	i = 0;
	pipes = game_state->pipes;
	while (i < game_state->pipe_capacity)
	{
		if (pipes[i].active == true)
			draw_pipe(game_state, display, pipes[i]);
		i++;
	}
}
