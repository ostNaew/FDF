#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

t_map *map_init(void)
{
	t_map *map;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = -2147483648;//to do need constant
	map->z_max = 2147483647;//to do need constant
	map->z_range = 0;
	return (map);
}

int read_map(const int fd, t_coord_val **coords_stack, t_map *map)
{
	char *line;
	int result;
	char **coords_line;
	
	/*int i;
	i = 0;
	get_next_line(fd, &line);
	printf("line1: %s\n", line);
	get_next_line(fd, &line);
	printf("line2: %s\n", line);
	get_next_line(fd, &line);
	printf("line3: %s\n", line);
	coords_line = ft_strsplit(line, ' ');
	printf("%s\n", coords_line[2]);*/
	while ((result = get_next_line(fd, &line)) == 1)
	{
		coords_line = ft_strsplit(line, ' ');//to do need check if result != 1
		parse_line(coords_line, coords_stack, map);
		map->height++;
	}
	printf("read_map result: %d\n", result);
	return result;
}
