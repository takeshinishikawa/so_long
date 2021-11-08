/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/08 11:30:51 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_line(char *line, size_t len)
{
	size_t needle;

	needle = 0;
	while(needle < len)
	{
		if (line[needle] == '1')
			needle++;
		else
			return (0);
	}
	return (1);
}

int	check_mid_line(char *line, size_t len)
{
	//check if line limits is a Wall
	if (line[0] == '1' && line[len - 1] == '1')
		return (1);
	return (0);
}

int	parse_map(char *map)
{
	int	needle;

	needle = 0;
	while (map[needle])
	{
		if (map[needle] != '0' && map[needle] != '1' && map[needle] != 'C' && map[needle] != 'E' && map[needle] != 'P')
			return (1);
		needle++;
	}
	return (0);
}

int get_map(char *argv)
{
	int		fd;
	char 	*line;
	int 	line_n; //Must be passed to game struct
	int 	gnl_status;
	int		valid_map;
	size_t	line_len;//must be passed to game struct
	char	*map;

	map = malloc(sizeof(char) * MAP_SIZE);
	if (map == NULL)
	{
		ft_printf("Failed to store the map. Please, try again.\n");
		free(map);
		return (0);
	}
	*map = 0;

	//get_fd function
	fd = open(argv, O_RDONLY);

	if (fd == -1)
	{
		ft_printf("Failed to open the file.\n");
		return (0);
	}
	line_n = 0;
	/*VALIDATE BORDERS*/

	//First line
	if ((gnl_status = get_next_line(fd, &line)) > 0)
	{
		ft_printf("%s\n", line);
		line_len = ft_strlen(line);
		valid_map = check_wall_line(line, line_len);
		if (valid_map == 0)
			ft_printf("A wall is missing in the first line.\n");
	}
	//Following lines
	while (gnl_status > 0)
	{
		line_n++;
		if ((valid_map = check_mid_line(line, line_len)) != 1)
			ft_printf("A wall is missing at the edges.\n");
		//Check if mid_len has the correct line_size
		if (ft_strlen(line) != line_len)
			ft_printf("All lines must have the same number of chars.\n");
		ft_strcat(map, line);
		free (line);
		line = 0;
		gnl_status = get_next_line(fd, &line);
		if (gnl_status == 0)
		{
			valid_map = check_wall_line((map + ft_strlen(map) - line_len), line_len);
			if (valid_map == 0)
			{
				if (!*line)
					ft_printf("A wall is missing in the last line.\n");
				ft_strcat(map, line);
				free (line);
				line = 0;
			}
		}
		ft_printf("%s\n", line); //remove
	}
	ft_printf("%i lines\n", line_n); //remove
	ft_printf("%i chars per line\n", line_len); //remove

	/*VALIDATE QTT OF LINE/COLUMNS AT LEAST 4X4*/
	if (line_len < 4 || line_n < 4)
		ft_printf("Valid map must have at least 4 lines/columns.\n");

	/*VALIDATE CENTER*/
	//0 IS EMPTY SPACE
	//1 WALL
	//C COLLECTIBLE
	//E MAP EXIT
	//P PLAYER
	if (parse_map(map) == 1)
		ft_printf("Valid map must be composed by 0, 1, C, E and P.\n");

	//AT LEAST 1 C
	//AT LEAST 1 E
	//AT LEAST 1 P


	close(fd);
	free(map);
	return (0);
}


int	main(int argc, char **argv)
{
	t_game	game;

	ft_printf("%i %s %s\n", argc, *argv, *(argv + 1)); //apagar
	if (check_map(argc, argv) != 0)
		return (-1);
	if (get_map(argv[1]) != 0)
		return (-1);


	return (0);
}
