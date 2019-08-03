#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

static t_coord_val *new_coord(char *s)
{
	t_coord_val *coord;
	char **parts;

	coord = (t_coord_val *)malloc(sizeof(t_coord_val));
	coord->z = ft_atoi(s);
	coord->color = -1;
	coord->next = NULL;
	return coord;
}

void parse_line(char **coords_line, t_coord_val *coords_stack, t_map *map)
{
	int width;
	char *result_str;

	width = 0;
	while(*coords_line)
	{
		push(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	//printf("coord z: %d\n", new_coord(coords_line[0])->z);//print z coordinate
	//printf("%d\n", width);//print width
}
