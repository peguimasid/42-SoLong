

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>

# define PERSON "./img/person_a.xpm"
# define FLOOR "./img/dirt.xpm"
# define WALL "./img/wall.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*person;
	void	*floor;
	void	*wall;
	int		x_pos;
	int		y_pos;
}			t_game;

enum		e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

enum		e_eventcode
{
	E_KEYPRESS = 2,
	E_CLOSE_GAME = 17
};

int			handle_keypress(int keycode, t_game *game);
void		put_img(int x, int y, t_game *game, void *img);
int			close_game(t_game *game);

#endif