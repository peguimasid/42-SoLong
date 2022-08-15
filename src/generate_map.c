/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:26:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/15 15:24:52 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ext_validator(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(path + length - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid file extension\n");
		return (0);
	}
	return (1);
}

int	has_sequence_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("Error\nMap format is wrong\n");
			return (1);
		}
		i++;
	}
	return (0);
}

char	*read_file(int fd)
{
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	if (!map)
		return (NULL);
	while (42)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map = ft_strjoin(map, tmp);
		free(tmp);
	}
	close(fd);
	if (!*map)
	{
		throw_error("Map is empty\n");
		free(map);
		return (NULL);
	}
	return (map);
}

void	set_map_boundaries(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i])
		i++;
	game->map_num_rows = i * SPRITE_SIZE;
	game->map_num_cols = (ft_strlen(game->map[0])) * SPRITE_SIZE;
}

char	**generate_map(t_game *game, char *path)
{
	int		fd;
	char	*map;
	char	**map_array;

	if (!ext_validator(path))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile not found\n");
		return (NULL);
	}
	map = read_file(fd);
	if (!map)
		return (NULL);
	if (has_sequence_newline(map))
	{
		free(map);
		return (NULL);
	}
	map_array = ft_split(map, '\n');
	free(map);
	game->map = map_array;
	set_map_boundaries(game);
	return (map_array);
}
