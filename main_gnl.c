/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:11:24 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/03 15:18:53 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_line(char *line, int len)
{
	int needle;

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

int	check_mid_line(char *line, int len)
{
	if (line[0] == '1' && line[len - 1] == '1')
		return (1);
	return (0);
}

int main(void)
{
	int		fd;
	char 	*line;
	int 	line_n; //Must be passed to game struct
	int 	gnl_status;
	int		valid_map;
	int		line_len;//must be passed to game struct
	char	*map;

	map = malloc(sizeof(char) * MAP_SIZE);
	if (map == NULL)
	{
		ft_printf("Failed to store the map. Please, try again.\n");
		return (0);
	}
	line_n = 0;
	//get_fd function
	fd = open("./map/map.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Failed to open the file.\n");
		return (0);
	}
	//first line
	if ((gnl_status = get_next_line(fd, &line)) > 0 && line_n == 0)
	{
		line_len = ft_strlen(line);
		valid_map = check_wall_line(line, line_len);
		ft_strlcat(map, line, line_len + 1);
		ft_printf("%s\n", map);
		free(line);
		line_n++;
		//check if map is valid
		if (valid_map == 0)
			ft_printf("A wall is missing in the first line.\n");
	}
	//mid lines
	while ((gnl_status = get_next_line(fd, &line)) > 0)
	{
		valid_map = check_mid_line(line, line_len);
		map = ft_strjoin(map, line);
		ft_printf("%s\n", map);
		free(line);
		if (valid_map == 0)
		{
			ft_printf("A wall is missing between first and last line.\n");
			break;
		}
		line_n++;
	}
	if ((gnl_status = get_next_line(fd, &line)) <= 0 && line_n != 1)
	{
		valid_map = check_wall_line(map + (line_len * (line_n - 1)), line_len);
		//ft_strlcat(map, line, line_len);
		ft_printf("%s\n", map);
		//check if map is valid
		if (valid_map == 0)
			ft_printf("A wall is missing in the last line.\n");
	}

	close(fd);
	/*
	if (i == -1)
		printf ("\nError in Function - Returned -1\n");
	else if (j == 9)
		printf("\nRight number of lines\n");
	else if (j != 9)
		printf("\nNot Good - Wrong Number Of Lines\n");*/
	return (0);
}

