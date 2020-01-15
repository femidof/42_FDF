/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:19:21 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/09 18:24:00 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

int count_values(char *line)
{
    int num_value;
    char **splitted_value;

    num_value = 0;
    splitted_value = ft_strsplit(line, ' ');
    while (*splitted_value)
    {

        printf("Here i have my line output: %s\n", line);
    //     // i need to use strsplit and atoi to get the values and count with that

    //     // and within  the 
        num_value++;
        splitted_value++;
    }
    printf("this is my column number here - %d", num_value);
    return (num_value);
}

int line_count(char *argv, t_fdf *fdf)
{
    int rows;
    int cols;
    int len;
    int fd;
    char *line;

    
    if ((fd = open(argv, O_RDONLY)) < 0)
    {
        ft_puterror("Error opening file!", 1);
    }
    rows = 0;
    cols = 0;
    while (get_next_line(fd, &line) == 1)
    {
        if (((len = count_values(line)) > cols) && (cols == 0))
            cols = len;
        (cols == len) ? rows += 1 : ft_puterror("Not a valid file!", 4);
        free(line);
    }
    return (rows);
}

void validate_lines(char *line, t_fdf *fdf)
{
    int i;

    char **split;

    if ((split = ft_strsplit(line, ' ')))
    {
        i = 0;
        while (split[i])
        {

        }
    }
}

void    fdf_read(char *argv, t_fdf *fdf)
{
    int fd;
    int x;
    char *line;
    int y;

    fdf->map.breadth = line_count(argv, fdf);
    if ((fd = open(argv, O_RDONLY)) < 0)
    {
        ft_puterror("Error opening file!", 1);
    }
    while (get_next_line(fd, &line) == 1)
    {
        
        ft_putendl(line);
        validate_lines(line, fdf);
        free(line);
    }
}



void read_lines(char *argv, t_fdf *fdf)
{
    if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			ft_puterror("Memory Allocation failed!", 3);
    fdf_read(argv, fdf);
    // nomalize_map(fdf);

}
