/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebetrix <ebetrix@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:14:38 by ebetrix           #+#    #+#             */
/*   Updated: 2022/03/21 15:18:19 by ebetrix          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     main(int argc, char **argv)
{
        int     fd;
        char    *str;
        (void)  argc;

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
/*      str = get_next_line(fd);
//      printf("%s", str);
        str = get_next_line(fd);
//      printf("%s", str);
        str = get_next_line(fd);
//      printf("%s", str);
        str = get_next_line(fd);
//      printf("%s", str);
        str = get_next_line(fd);
//      printf("%s", str);
        str = get_next_line(fd);
//      printf("%s", str);
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
        printf("%s", str);*/
        free(str);
        str = NULL;
        close(fd);
        return (0);
}
