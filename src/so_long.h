/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:13:18 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/14 11:32:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define PERSON_RIGHT "./img/person_d.xpm"
# define PERSON_LEFT "./img/person_a.xpm"
# define FLOOR "./img/dirt.xpm"
# define WALL "./img/wall.xpm"
# define COIN "./img/coin.xpm"
# define EXIT "./img/exit.xpm"

# define SPRITE_SIZE 32

typedef struct s_player
{
	int			x_pos;
	int			y_pos;
	int			coins;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*person;
	void		*floor;
	void		*wall;
	void		*coin;
	void		*exit;
	char		**map;
	int			map_num_cols;
	int			map_num_rows;
	t_player	player;
}				t_game;

enum			e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

enum			e_eventcode
{
	E_KEYPRESS = 2,
	E_CLOSE_WINDOW = 17
};

int				print_map(t_game *game);
int				close_game(t_game *game);
int				is_valid_map(t_game *game);
int				set_game_config(t_game *game);
int				handle_keypress(int keycode, t_game *game);

void			map_free(char **map);
void			put_img(int x, int y, t_game *game, void *img);

void			*load_img(t_game *game, char *path);

char			**generate_map(t_game *game, char *path);

#endif
