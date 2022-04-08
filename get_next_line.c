/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebetrix <ebetrix@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:26:57 by ebetrix           #+#    #+#             */
/*   Updated: 2022/04/08 12:32:53 by ebetrix          ###   ########.ch       */
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

char	*get_next_line(int fd)		//La fonction principale
{
	char	c;			//Un caractère
	char	*line;			//La ligne renvoyée

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256 || read(fd, 0, 0) < 0) //La gestion d'erreur
		return (NULL);
	if (read(fd, &c, 1) == 0)	//On lit un caractère, si le fichier est vide, la fonction renvoie 0 et s'arrête.
		return (NULL);
	line = malloc(sizeof(char) * 1); //On assigne la ligne avec malloc.
	if (!line)			//Gestion d'erreur du malloc.
		free(line);
	line[0] = '\0';			//Le premier et unique caractère de cette ligne ne contient rien, pour être sûr qu'il n'a rien stocké de random.
	line = ft_strjoin_gnl(line, c);	//On crée la ligne avec le premier caractère lu.
	if (c == '\n')			//Si ce premier caractère est un retour à la ligne, on renvoie la ligne.
		return (line);
	while (read(fd, &c, 1) != 0)	//On boucle tant qu'il y a de quoi lire.
	{
		if (c == 0)		//Gestion d'erreur - pas sûre qu'elle soit nécessaire ici.
			return (NULL);
		line = ft_strjoin_gnl(line, c); //On crée la ligne caractère par caractère.
		if (c == '\n')		//Dès que le caractère est un retour à la ligne, on renvoie la ligne et la fonction s'arrête.
			return (line);
	}
	if (line)			//Renvoie la dernière la ligne - pas sûre qu'il faille un "if".
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
