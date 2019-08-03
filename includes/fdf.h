#ifndef FDF_H

# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>//to do delete this library
# include <errno.h>
#include <math.h>
# include "../minilibx_macos/mlx.h"
#include "string.h"


# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250
//2 part
# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))



typedef enum
{
	false,
	true
}	t_bool;

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct			s_coord_val
{
	int					z;
	int					color;
	struct s_coord_val	*next;
}						t_coord_val;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;


//to do
//ramake s_camera struct
typedef struct			s_pos
{
	t_projection		projection;
	int					zoom;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_pos;


typedef struct 			s_angles
{
	double 				alpha;
	double				beta;
	double 				gamma;
}						t_angles;

typedef struct			s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					*colors_arr;
	int					z_min;
	int					z_max;
	int					z_range;
}						t_map;

typedef struct			s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_pos				*pos;
	t_angles 			*angles;
	t_map				*map;
	t_mouse				*mouse;
}						t_fdf;

t_map *map_init(void);
int read_map(const int fd, t_coord_val **coords_stack, t_map *map);
void parse_line(char **coords_line, t_coord_val *coords_stack, t_map *map);
void push(t_coord_val **coords_stack, t_coord_val *new);
t_fdf *fdf_init(t_map *map);
void stack_to_arrays(t_coord_val **coords_stack, t_map *map);

//2 part
void ft_draw_background(t_fdf *fdf);
void ft_put_pixel(t_fdf *fdf, int x, int y, int colour);
void ft_print_menu(t_fdf *fdf);
void ft_draw_line(t_point f, t_point s, t_fdf *fdf);
void drawer(t_map *map, t_fdf *fdf);
void	ft_iso_projection(int *x, int *y, int z);
t_point projection(t_point point, t_fdf *fdf);
int		get_index(int x, int y, int width);
t_point	new_point(int x, int y, t_map *map);
void	ft_bzero(void *s, size_t n);
t_pos	*set_pos(t_fdf *fdf);
void	*ft_memalloc(size_t size);
void	setup_controls(t_fdf *fdf);
int			mouse_move(int x, int y, void *param);
int			mouse_release(int button, int x, int y, void *param);
int			mouse_press(int button, int x, int y, void *param);
void	change_projection(int key, t_fdf *fdf);
void	flatten(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	zoom(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
t_angles 	*set_angles();
t_pos	*set_pos(t_fdf *fdf);


//keys
# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_THIRD_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_0			82
# define NUM_PAD_1			83
# define NUM_PAD_2			84
# define NUM_PAD_3			85
# define NUM_PAD_4			86
# define NUM_PAD_5			87
# define NUM_PAD_6			88
# define NUM_PAD_7			89
# define NUM_PAD_8			91
# define NUM_PAD_9			92
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35
# define MAIN_PAD_0			29
# define MAIN_PAD_1			18
# define MAIN_PAD_2			19
# define MAIN_PAD_3			20
# define MAIN_PAD_4			21
# define MAIN_PAD_5			23
# define MAIN_PAD_6			22
# define MAIN_PAD_7			26
# define MAIN_PAD_8			28
# define MAIN_PAD_9			25
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_LESS		43
# define MAIN_PAD_MORE		47


#endif