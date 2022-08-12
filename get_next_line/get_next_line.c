/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:13:17 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/12 16:57:22 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*read_file_until_find_next_line(int fd, char *work_str)
{
	int		read_bytes_amount;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes_amount = 1;
	while (!gnl_strchr(work_str, '\n') && read_bytes_amount != 0)
	{
		read_bytes_amount = read(fd, buff, BUFFER_SIZE);
		if (read_bytes_amount == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes_amount] = '\0';
		work_str = gnl_strjoin(work_str, buff);
	}
	free(buff);
	return (work_str);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*work_str;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	work_str = read_file_until_find_next_line(fd, work_str);
	if (!work_str)
		return (NULL);
	result = get_part_before_next_line_from_work_string(work_str);
	work_str = get_part_after_next_line_from_work_string(work_str);
	return (result);
}
