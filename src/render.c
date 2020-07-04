/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2020/07/04 02:42:51 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	draw_score(t_game_context *game_state, t_display *display)
{
	SDL_Rect	dest;

	dest.h = 5 * 4;
	dest.w = 4 * 4;
	dest.x = 400;
	dest.y = 48;
	itow(game_state->ticks, dest, display);
}
