/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:26:42 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/10 20:29:03 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_ext(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strncmp(path + length - 4, ".ber", 4) != 0)
	{
		throw_error("Invalid file extension");
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

char	**generate_map(t_game *game, char *path)
{
	int		fd;
	char	*map;
	char	**map_array;
	char	**map_array_copy;

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
	map_array = ft_split(map, '\n');
	map_array_copy = ft_split(map, '\n');
	free(map);
	game->map = map_array;
	game->map_copy = map_array_copy;
	set_map_boundaries(game);
	return (map_array);
}
