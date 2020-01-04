/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:13:42 by oldurosi          #+#    #+#             */
/*   Updated: 2019/10/21 00:58:05 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/get_next_line.h"

static int	ft_append_line(char **s, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		temp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	ft_output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
	{
		return (-1);
	}
	else if (ret == 0 && s[fd] == NULL)
	{
		return (0);
	}
	else
	{
		return (ft_append_line(&s[fd], line));
	}
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char	*s[MAXFD];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
		{
			s[fd] = ft_strdup(buff);
		}
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ft_output(s, line, ret, fd));
}
