/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:13:18 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/11 10:25:19 by gmasid           ###   ########.fr       */
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
# define PERSON_BACK "./img/person_w.xpm"
# define PERSON_FRONT "./img/person_s.xpm"
# define FLOOR "./img/dirt.xpm"
# define WALL "./img/wall.xpm"
# define COIN "./img/coin.xpm"
# define EXIT "./img/exit.xpm"

# define SPRITE_SIZE 32

typedef struct s_player
{
	int			x_pos;
	int			y_pos;
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
	char		**map_copy;
	int			moves_count;
	int			collectibles_count;
	int			reachable_collectibles_count;
	int			players_count;
	int			exits_count;
	int			reachable_exits_count;
	int			finish_game;
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
int				throw_error(char *error);
int				is_valid_map(t_game *game);
int				set_game_config(t_game *game);
int				handle_keypress(int keycode, t_game *game);

int				map_respect_num_of_elements(t_game *game);

void			map_free(char **map);
void			init_vars(t_game *game);
void			print_steps(t_game *game);
void			count_map_elements(t_game *game);
void			count_map_reachable_elements(t_game *game, int px, int py);
void			display_finish_game_message(void);
void			put_img(int x, int y, t_game *game, void *img);

void			*load_img(t_game *game, char *path);

int				is_valid_ext(char *path);
char			**generate_map(t_game *game, char *path);

#endif
