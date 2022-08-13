/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:34:49 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/13 17:34:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(int x, int y, t_game *game, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	print_map_aux(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		put_img(y * SPRITE_SIZE, x * SPRITE_SIZE, game, game->wall);
	if (game->map[x][y] == '0')
		put_img(y * SPRITE_SIZE, x * SPRITE_SIZE, game, game->floor);
	if (game->map[x][y] == 'P')
	{
		game->player.x_pos = x;
		game->player.y_pos = y;
		put_img(y * SPRITE_SIZE, x * SPRITE_SIZE, game, game->person);
	}
	if (game->map[x][y] == 'E')
		put_img(y * SPRITE_SIZE, x * SPRITE_SIZE, game, game->exit);
	if (game->map[x][y] == 'C')
		put_img(y * SPRITE_SIZE, x * SPRITE_SIZE, game, game->coin);
}

int	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			print_map_aux(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
