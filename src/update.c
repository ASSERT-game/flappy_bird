/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2020/07/03 20:54:47 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void		update_active_pipes(t_game_context *game_state)
{
	int	i;

	i = 0;
	while (i < game_state->pipe_capacity)
	{
		if (game_state->pipes[i].active == true)
			game_state->pipes[i].loc_x -= 1;
		i++;
	}
}

void		update_game_state(t_game_context *game_state)
{
	update_active_pipes(game_state);
}
