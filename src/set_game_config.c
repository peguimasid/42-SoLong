/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:05:50 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/17 13:58:40 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_img(t_game *game, char *path)
{
	int		x;
	int		y;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
	if (img == NULL)
	{
		ft_printf("Error\nImage not found\n");
		exit(1);
	}
	return (img);
}

int	set_game_config(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_num_cols,
			game->map_num_rows, "so_long");
	game->person = load_img(game, PERSON_RIGHT);
	game->floor = load_img(game, FLOOR);
	game->wall = load_img(game, WALL);
	game->coin = load_img(game, COIN);
	game->exit = load_img(game, EXIT);
	return (0);
}
