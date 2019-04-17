/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 17:38:52 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 15:54:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_convert_array(t_param *param, t_lines *lines)
{
	t_lines	*tmp;
	int		i;
	int		j;

	if (!(param->result = (t_result*)malloc(sizeof(*param->result) * 	\
	param->nb_columns * param->nb_lines)))
		ft_error("Malloc error");
	tmp = lines;
	i = -1;
	while (++i < param->nb_lines)
	{
		j = -1;
		while (++j < param->nb_columns)
		{
			param->result[i * param->nb_columns + j].x = 				\
			j - param->nb_columns / 2;
			param->result[i * param->nb_columns + j].y = 				\
			i - param->nb_lines / 2;
			param->result[i * param->nb_columns + j].z = tmp->z[j];
			param->result[i * param->nb_columns + j].color = 			\
			ft_color_hex_to_rgb(tmp->color[j]);
		}
		tmp = tmp->next;
	}
}

static void	ft_list_push_back(t_lines **lines, t_lines *new)
{
	t_lines *orig;

	if (!*lines)
		*lines = new;
	else
	{
		orig = *lines;
		while (orig->next)
			orig = orig->next;
		orig->next = new;
	}
}

void		ft_insert_list(t_param *param, char **line, t_lines **lines)
{
	int		i;
	char	**tmp;
	t_lines	*new;

	if (!(new = malloc(sizeof(t_lines))) || 						\
	!(new->z = (int *)malloc(sizeof(int) * param->nb_columns)) || 	\
	!(new->color = (char **)malloc(sizeof(char *) * param->nb_columns)))
		ft_error("error");
	i = -1;
	while (++i < param->nb_columns)
	{
		if (!(tmp = ft_strsplit(line[i], ',')))
			ft_error("Split error");
		new->z[i] = ft_atoi(tmp[0]);
		new->color[i] = ft_strdup(tmp[1]);
		ft_splitdel(&tmp);
	}
	new->next = NULL;
	ft_list_push_back(lines, new);
}

static void	ft_list_del(t_param *param, char *line, char **split, 	\
t_lines **lines)
{
	param->nb_lines++;
	ft_insert_list(param, split, lines);
	if (line)
		free(line);
	ft_splitdel(&split);
}

void		ft_read_file(t_param *param, char *file, t_lines **lines)
{
	int		fd;
	char	*line;
	int		tmp;
	int		gnl;
	char	**split;

	tmp = 0;
	param->nb_lines = 0;
	param->nb_columns = 0;
	fd = open(file, O_RDONLY);
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl < 0)
			ft_error("File error");
		if (!(split = ft_strsplit(line, ' ')))
			ft_error("Split error");
		while (split[param->nb_columns])
			param->nb_columns++;
		if (tmp && tmp != param->nb_columns)
			ft_error("Map error");
		tmp = param->nb_columns;
		ft_list_del(param, line, split, lines);
	}
	free(line);
	close(fd);
}
