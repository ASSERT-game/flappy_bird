/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:55:48 by home              #+#    #+#             */
/*   Updated: 2020/07/03 22:26:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	draw_player(t_game_context *game_state, t_display *display)
{
	SDL_Rect	dest;

	dest.h = TILE_SIZE;
	dest.w = TILE_SIZE;
	dest.x = 40;
	dest.y = game_state->player_loc_y;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[game_state->player_animation]), &(dest));
}
