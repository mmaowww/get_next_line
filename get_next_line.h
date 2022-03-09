/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebetrix <ebetrix@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:40:51 by ebetrix           #+#    #+#             */
/*   Updated: 2022/03/09 16:06:04 by ebetrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char c);

#endif
