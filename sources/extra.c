#include "../includes/fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		fdf->pos->zoom++;
	else if (key == NUM_PAD_MINUS ||
		key == MAIN_PAD_MINUS ||
		key == MOUSE_SCROLL_DOWN)
		fdf->pos->zoom--;
	if (fdf->pos->zoom < 1)
		fdf->pos->zoom = 1;
	drawer(fdf->map, fdf);
}

/*
** Move map
*/

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->pos->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->pos->x_offset += 10;
	else if (key == ARROW_UP)
		fdf->pos->y_offset -= 10;
	else
		fdf->pos->y_offset += 10;
	drawer(fdf->map, fdf);
}

/*
** Rotate map
*/

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		fdf->angles->alpha += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		fdf->angles->alpha -= 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		fdf->angles->beta -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		fdf->angles->beta += 0.05;
	else if (key == NUM_PAD_1)
		fdf->angles->gamma += 0.05;
	else if (key == NUM_PAD_9 )
		fdf->angles->gamma -= 0.05;
	drawer(fdf->map, fdf);
}

/*
** Change z value. Make map more flatten
*/

void	flatten(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_LESS)
		fdf->pos->z_divisor -= 0.1;
	else if (key == MAIN_PAD_MORE)
		fdf->pos->z_divisor += 0.1;
	if (fdf->pos->z_divisor < 0.1)
		fdf->pos->z_divisor = 0.1;
	else if (fdf->pos->z_divisor > 10)
		fdf->pos->z_divisor = 10;
	drawer(fdf->map, fdf);
}

/*
** Change projection type
*/

void	change_projection(int key, t_fdf *fdf)
{
	fdf->angles->alpha = 0;
	fdf->angles->beta = 0;
	fdf->angles->gamma = 0;
	if (key == MAIN_PAD_I)
		fdf->pos->projection = ISO;
	else if (key == MAIN_PAD_P)
		fdf->pos->projection = PARALLEL;
	drawer(fdf->map, fdf);
}