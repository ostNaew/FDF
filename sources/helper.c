#include "../includes/fdf.h"

int		get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;
	
	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	//point.color = (map->colors_arr[index] == -1) ?
	//		get_default_color(point.z, map) : map->colors_arr[index];
	return (point);
}