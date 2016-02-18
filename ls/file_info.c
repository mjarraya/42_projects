/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 22:31:52 by mjarraya          #+#    #+#             */
/*   Updated: 2016/02/18 08:16:14 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

char	*file_owner(struct stat buf)
{
	struct passwd	*pw;

	pw = getpwuid(buf.st_uid);
	return (pw->pw_name);
}

char	*file_group(struct stat buf)
{
	struct group	*gr;

	gr = getgrgid(buf.st_gid);
	return (gr->gr_name);
}

char	file_type(struct stat buf)
{
	if ((buf.st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((buf.st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((buf.st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((buf.st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	if ((buf.st_mode & S_IFMT) == S_IFREG)
		return ('-');
	else
		return ('-');
}

char		*file_perms(struct stat buf)
{
	char	*perm;

	perm = ft_strnew(10);
	perm[0] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
	perm[1] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
	perm[2] = (buf.st_mode & S_IXUSR) ? 'x' : '-';
	perm[3] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	perm[4] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
	perm[5] = (buf.st_mode & S_IXGRP) ? 'x' : '-';
	perm[6] = (buf.st_mode & S_IROTH) ? 'r' : '-';
	perm[7] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
	perm[8] = (buf.st_mode & S_IXOTH) ? 'x' : '-';
	perm[9] = '\0';
	return (perm);
}

t_files		*ft_fill_s_files(char **filename)
{
	t_files		*file;
	struct stat	buf;
	int		i = 0;

	while (filename[i])
	{
	if (stat(filename[i], &buf) == -1)
		return (NULL);
	file = (t_files *)ft_memalloc(sizeof(t_files));
	file->size = buf.st_size;
	file->type = file_type(buf);
	file->perms = file_perms(buf);
	file->links = buf.st_nlink;
	file->owner = file_owner(buf);
	file->group = file_group(buf);
	/*file->time_acc = ft_strndup(&(ctime(&buf.st_atime))[4], 12);
	file->time_mod = ft_strndup(&(ctime(&buf.st_mtime))[4], 12);
	file->time_sta = ft_strndup(&(ctime(&buf.st_ctime))[4], 12);*/
	file->device = buf.st_rdev;
	file->name = ft_strdup(filename);
	file->next = NULL;
	}
	return (file);
}

