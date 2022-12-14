/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:26:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/10 21:05:17 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	has_sequence_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (throw_error("Map format is wrong"));
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
		throw_error("Map is empty");
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

char	**fill_map(t_game *game, char *map)
{
	char	**map_array;
	char	**map_array_copy;

	map_array = ft_split(map, '\n');
	map_array_copy = ft_split(map, '\n');
	game->map = map_array;
	game->map_copy = map_array_copy;
	return (map_array);
}

char	**generate_map(t_game *game, char *path)
{
	int		fd;
	char	*map;
	char	**map_array;

	if (!is_valid_ext(path))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		throw_error("File not found");
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
	map_array = fill_map(game, map);
	free(map);
	set_map_boundaries(game);
	return (map_array);
}
