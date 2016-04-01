/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 23:48:46 by mjarraya          #+#    #+#             */
/*   Updated: 2016/04/01 00:44:27 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fillinfo(t_stat filestats, t_file **file)
{
	(*file)->type = ft_gettype(filestats);
	(*file)->rights = ft_getrights(filestats);
	(*file)->links = (int)(filestats.st_nlink);
	if (getpwuid(filestats.st_uid))
		(*file)->uname = (getpwuid(filestats.st_uid))->pw_name;
	else
		(*file)->uname = ft_strnew(1);
	if (getgrgid(filestats.st_gid) != NULL)
		(*file)->gname = (getgrgid(filestats.st_gid))->gr_name;
	else
		(*file)->gname = ft_strnew(1);
	if ((*file)->type != 'b' && (*file)->type != 'c')
		(*file)->size = filestats.st_size;
}

char	ft_gettype(t_stat filestats)
{
	if (S_ISFIFO(filestats.st_mode))
		return ('p');
	else if (S_ISCHR(filestats.st_mode))
		return ('c');
	else if (S_ISDIR(filestats.st_mode))
		return ('d');
	else if (S_ISBLK(filestats.st_mode))
		return ('b');
	else if (S_ISREG(filestats.st_mode))
		return ('-');
	else if (S_ISLNK(filestats.st_mode))
		return ('l');
	else if (filestats.st_mode & S_IFSOCK)
		return ('s');
	else
		return ('-');
}

char	*ft_getrights(t_stat filestats)
{
	char	*rights;

	rights = ft_strnew(10);
	rights[0] = (filestats.st_mode & S_IRUSR) ? 'r' : '-';
	rights[1] = (filestats.st_mode & S_IWUSR) ? 'w' : '-';
	rights[2] = (filestats.st_mode & S_IXUSR) ? 'x' : '-';
	rights[3] = (filestats.st_mode & S_IRGRP) ? 'r' : '-';
	rights[4] = (filestats.st_mode & S_IWGRP) ? 'w' : '-';
	rights[5] = (filestats.st_mode & S_IXGRP) ? 'x' : '-';
	rights[6] = (filestats.st_mode & S_IROTH) ? 'r' : '-';
	rights[7] = (filestats.st_mode & S_IWOTH) ? 'w' : '-';
	rights[8] = (filestats.st_mode & S_IXOTH) ? 'x' : '-';
	rights[9] = '\0';
	if (rights[2] != 'x')
		rights[2] = (filestats.st_mode & S_ISUID) ? 'S' : '-';
	if (rights[5] != 'x')
		rights[5] = (filestats.st_mode & S_ISGID) ? 'S' : '-';
	if (rights[8] != 'x')
		rights[8] = (filestats.st_mode & S_ISVTX) ? 'T' : '-';
	return (rights);
}

t_stat	ft_stat(char *path, char *filename, t_file **file)
{
	t_stat filestats;

	if ((lstat(path, &filestats)) == -1)
	{
		if ((lstat(filename, &filestats)) == -1)
			(*file)->denied = 1;
	}
	return (filestats);
}

t_file	*ft_putinfo(t_file *file, char *filename, char *dirname)
{
	ssize_t		i;
	t_stat		filestats;
	char		*path;
	char		buf[257];

	path = NULL;
	path = ft_strjoin(dirname, "/");
	path = ft_strjoin(path, filename);
	filestats = ft_stat(path, filename, &file);
	file->lnpath = ft_memalloc(ft_strlen(filename) + 1);
	ft_fillinfo(filestats, &file);
	ft_puttime(filestats, &file);
	file->dname = ft_strdup(filename);
	if (file->type == 'l')
	{
		if ((i = readlink(file->dname, buf, sizeof(buf) - 1)) != -1)
			buf[i] = '\0';
		else if ((i = readlink(path, buf, sizeof(buf) - 1)) != -1)
			buf[i] = '\0';
		file->lnpath = ft_strdup(buf);
	}
	ft_fill_major(filestats, &file);
	path = NULL;
	return (file);
}
