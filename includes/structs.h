/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/07/03 20:03:46 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef struct	s_pipe
{
	bool		active;
	int			loc_x;
	int			loc_y;
}				t_pipe;

typedef struct	s_game_context
{
	bool		active;

	SDL_Texture	*texture;
	SDL_Rect	*src_rect;

	int			pipe_capacity;
	int			current_pipe_amount;
	t_pipe		*pipes;
}				t_game_context;

#endif
