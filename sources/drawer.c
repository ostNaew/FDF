#include "../includes/fdf.h"

void ft_draw_background(t_fdf *fdf)
{
	int i;
	int *image;

	i = 0;
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	while (i < HEIGHT * WIDTH) {
		image[i] = (i % WIDTH * HEIGHT) ? MENU_BACKGROUND : BACKGROUND;
		i++;
	}
}

void ft_put_pixel(t_fdf *fdf, int x, int y, int colour)
{
	int i;

	if (x > MENU_WIDTH && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i++] = colour;
		fdf->data_addr[i++] = colour >> 8;	//why?
		fdf->data_addr[i] = colour >> 16; // why?
	}
}

void ft_print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;

	//DEFINE
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "Controls");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Squeeze: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - 1/9");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");

	//use #define for mlx_string_put 
}


void ft_draw_line(t_point f, t_point s, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		ft_put_pixel(fdf, cur.x, cur.y, 0x9A1F6A);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void drawer(t_map *map, t_fdf *fdf)
{
	int x;
	int y;

	ft_draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				ft_draw_line(projection(new_point(x, y, map), fdf),
					projection(new_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				ft_draw_line(projection(new_point(x, y, map), fdf),
					projection(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0); 
	ft_print_menu(fdf);
}
