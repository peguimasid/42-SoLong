/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:55:41 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/10 19:33:53 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	throw_error(char *error)
{
	ft_printf("\033[0;31m\n");
	ft_printf("Error\n%s\n", error);
	ft_printf("\033[0m");
	return (1);
}

void	display_finish_game_message(void)
{
	ft_printf("\033[0;32m\n");
	ft_printf("YOU WIN!!!\n\n");
	ft_printf("Press ESC or click in X button to close window!\n");
	ft_printf("\033[0m");
}

void	print_steps(t_game *game)
{
	game->moves_count++;
	ft_printf("Steps: %d\n", game->moves_count);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->person);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	map_free(game->map);
	map_free(game->map_copy);
	exit(0);
	return (0);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
