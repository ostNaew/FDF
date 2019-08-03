#include "../includes/fdf.h"

static void ft_rotator(int *x, int *y, int *z,t_angles *angles)
{
	int previous_x;
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(angles->alpha) + *z * sin(angles->alpha);
	*z = -previous_y * sin(angles->alpha) + *z * cos(angles->alpha);

	previous_x = *x;
	*x = previous_x * cos(angles->beta) + *z * sin(angles->beta);
	*z = -previous_x * sin(angles->beta) + *z * cos(angles->beta);

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angles->gamma) - previous_y * sin(angles->gamma);
	*y = previous_x * sin(angles->gamma) + previous_y * cos(angles->gamma);
}
//projections

void	ft_iso_projection(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void ft_zoomer(t_point *p , t_fdf *fdf)
{
	p->x *= fdf->pos->zoom;
	p->y *= fdf->pos->zoom;
	p->z *= fdf->pos->zoom / fdf->pos->z_divisor;
	//to-do
	//additional function
	p->x -= (fdf->map->width * fdf->pos->zoom) / 2;
	p->y -= (fdf->map->height * fdf->pos->zoom) / 2;
} 

t_point projection(t_point point, t_fdf *fdf)
{
	ft_zoomer(&point, fdf);
	ft_rotator(&point.x, &point.y, &point.z, fdf->angles);
	if (fdf->pos->projection == ISO)
		ft_iso_projection(&point.x, &point.y, point.z);
	point.x += (WIDTH - MENU_WIDTH) / 2 + fdf->pos->x_offset + MENU_WIDTH;
	point.y += (HEIGHT + fdf->map->height * fdf->pos->zoom) / 2
												+ fdf->pos->y_offset;
	return (point);
}