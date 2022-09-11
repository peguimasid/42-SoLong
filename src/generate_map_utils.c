/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:04:18 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/10 21:05:39 by gmasid           ###   ########.fr       */
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
