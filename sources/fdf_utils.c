#include "fdf.h"

t_fdf *fdf_init(t_map *map)
{
	t_fdf *fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel), &(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	return (fdf);
}

t_pos *set_pos(t_fdf *fdf)
{
	t_pos *pos;

	if (!(pos = (t_pos *)ft_memalloc(sizeof(pos))))
		exit (1);
	pos->zoom = FT_MIN((WIDTH - MENU_WIDTH) / fdf->map->width / 2,
												HEIGHT / fdf->map->height / 2);
	//camera->alpha = 0;
	//camera->beta = 0;
	//camera->gamma = 0;
	pos->z_divisor = 1;
	pos->x_offset = 0;
	pos->y_offset = 0;
	return (pos);
}

t_angles *set_angles()
{
	t_angles *angles;

	if (!(angles = (t_angles *)ft_memalloc(sizeof(t_angles))))
		exit (1);
	angles->alpha = 0;
	angles->beta = 0;
	angles->gamma = 0;
	return (angles);
}