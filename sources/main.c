#include "../includes/fdf.h"



int main(int argc, char const *argv[])
{
	/*t_bool boolean; 
   	boolean = true;
   	printf("%d", boolean);
   
   	t_coord_val *head = malloc(sizeof(t_coord_val));
   	head = malloc(sizeof(t_coord_val));
   	head -> z = 5;
   	head -> next = malloc(sizeof(t_coord_val));
   	head -> next -> z = 6;
   	head -> next -> next = NULL;
   	printf("%d\n", head -> z);
   	printf("%d\n", head -> next -> z);
	t_projection test;
	t_projection test1;
	test = ISO;
	test1 = PARALLEL;
	printf("%d\n", test);
	printf("%d\n", test1);
	t_camera *testCamera = malloc(sizeof(t_camera));
	testCamera -> projection = PARALLEL;
	printf("%d\n", testCamera -> projection);*/


	/*t_map *map = malloc(sizeof(t_map));
	map -> coords_arr = malloc(sizeof(int) * 2);
	for (int i = 0; i < 2; i++)
		map -> coords_arr[i] = i;
	for (int i = 0; i < 2; i++)
		printf("%d\n", map -> coords_arr[i]);*/

	/*t_fdf *test = malloc(sizeof(t_fdf));
	t_mouse *testMouse = malloc(sizeof(t_mouse));
	test -> mouse = testMouse;
	testMouse -> x = 5;
	printf("%d\n", test -> mouse -> x);*/

	/*int	fd;
	char *line;
	t_map *map;
	t_coord_val	*coords_stack;*/

	/*errno = 0;
	coords_stack = NULL;*/
	/*if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(3, &line) == 1)
			ft_putstr(line);
		map = map_init();
		read_map(fd, &coords_stack, map);
		printf("\n");
		printf("map->width: %d\n", map->width);
	}
	else
	 	perror("Usage: ./fdf MAP_FILE");*/
	int			fd;
	t_map		*map;
	t_coord_val	*coords_stack;
	t_fdf		*fdf;

	errno = 0;
	coords_stack = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		map = map_init();//initialyze structure map
		read_map(fd, &coords_stack, map);
		/*printf("coords_stack_z1: %d\n", coords_stack -> z);
		printf("coords_stack_color1: %d\n", coords_stack -> color);
		printf("coords_stack_z2 %d\n", coords_stack -> next -> z);
		printf("coords_stack_color2: %d\n", coords_stack -> next -> color);*/


		/*printf("map width: %d\n", map->width);
		printf("map height: %d\n", map->height);*/
		fdf = fdf_init(map);
		fdf->pos = set_pos(fdf);
		fdf->angles = set_angles();
		//printf("fdf_map_z: %d\n", fdf->map->width);

		stack_to_arrays(&coords_stack, map);
		printf("map coords_arr[0]: %d\n", map->coords_arr[0]);
		printf("map coords_arr:\n");
		//for (int i = 0; i < 100; i++)
	//	{
//			printf("%d,", map->coords_arr[i]);
	//	}
		//рисуй
		drawer(fdf->map, fdf);
		setup_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	
	else
	 	perror("Usage: ./fdf MAP_FILE");
}
