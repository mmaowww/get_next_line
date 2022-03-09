/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebetrix <ebetrix@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:26:57 by ebetrix           #+#    #+#             */
/*   Updated: 2022/03/09 17:08:42 by ebetrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char c)
{
	char	*line;
	int		i;

	if (!s1 || !c)
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen_gnl(s1) + 2);
	if (!line)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		line[i] = s1[i];
		i++;
	}
	line[i] = c;
	line[++i] = '\0';
	if (s1)
		free(s1);
	return (line);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256 || read(fd, 0, 0) < 0)
		return (NULL);
	if (read(fd, &c, 1) == 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		free(line);
	line[0] = '\0';
	line = ft_strjoin_gnl(line, c);
	if (c == '\n')
		return (line);
	while (read(fd, &c, 1) != 0)
	{
		if (c == 0)
			return (NULL);
		line = ft_strjoin_gnl(line, c);
		if (c == '\n')
			return (line);
	}
	if (line)
		return (line);
	return (0);
}

/*int	main(int argc, char **argv)
{
	int	fd;
	char	*str;
	(void)	argc;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("open failure");
		return (1);
	}
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	str = get_next_line(fd);
//	printf("%s", str);
	str = get_next_line(fd);
//	printf("%s", str);
	str = get_next_line(fd);
//	printf("%s", str);
	str = get_next_line(fd);
//	printf("%s", str);
	str = get_next_line(fd);
//	printf("%s", str);
	str = get_next_line(fd);
//	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = NULL;
	close(fd);
	return (0);
}*/
