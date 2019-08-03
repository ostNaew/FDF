#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

void push(t_coord_val **coords_stack, t_coord_val *new)
{
	if (coords_stack) 
	{
		if (new)//to do need validate check
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

t_coord_val *pop(t_coord_val **coords_stack)
{
	t_coord_val *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return top;
}

void stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val *coord;
	int i;
	int arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *)malloc(arr_size);
	map->colors_arr = (int *)malloc(arr_size);
	i = map->width * map->height - 1;
	while ((coord = pop(coords_stack)) && i >= 0)
	{
		map -> coords_arr[i] = coord->z;
		map -> colors_arr[i] = coord->color;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}