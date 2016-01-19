/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:04:28 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/19 19:36:57 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>

char	*file_type(struct stat sb)
{
	if ((sb.st_mode & S_IFMT) == S_IFBLK)
		return ("block");
	if ((sb.st_mode & S_IFMT) == S_IFCHR)
		return ("character special file");
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
		return ("directory");
	if ((sb.st_mode & S_IFMT) == S_IFIFO)
		return ("pipe");
	if ((sb.st_mode & S_IFMT) == S_IFLNK)
		return ("link");
	if ((sb.st_mode & S_IFMT) == S_IFSOCK)
		return ("socket");
	if ((sb.st_mode & S_IFMT) == S_IFREG)
		return ("regular file");
	else
		return ("unknown");
}

char	*file_perm(struct stat sb)
{
	char	*perm;

	perm = (char *)malloc(sizeof(char) * 11);
	perm[0] = (S_ISDIR(sb.st_mode) ? 'd' : '-');
	perm[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
	perm[10] = '\0';
	return (perm);
}

int		file_links(struct stat sb)
{
	return (sb.st_nlink);
}

char	*file_owner(struct stat sb)
{
	struct passwd	*pw;

	pw = getpwuid(sb.st_uid);
	return (pw->pw_name);
}

char	*file_group(struct stat sb)
{
	struct group	*gr;

	gr = getgrgid(sb.st_gid);
	return (gr->gr_name);
}

int		file_size(struct stat sb)
{
	return (sb.st_size);
}

char	*file_time(struct stat sb)
{

	return (ft_strndup(&(ctime(&sb.st_mtime))[4], 12));
}

int		main(int argc, char **argv)
{
	struct stat	sb;
	
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (stat(argv[1], &sb) == -1)
	{
		perror("stat");
		return (0);
	}
	ft_putstr("Nom: ");
	ft_putstr(argv[1]);
	ft_putstr("\nType: ");
	ft_putstr(file_type(sb));
	ft_putstr("\nPermissions: ");
	ft_putstr(file_perm(sb));
	ft_putstr("\nLinks: ");
	ft_putnbr(file_links(sb));
	ft_putstr("\nOwner: ");
	ft_putstr(file_owner(sb));
	ft_putstr("\nGroup: ");
	ft_putstr(file_group(sb));
	ft_putstr("\nSize: ");
	ft_putnbr(file_size(sb));
	ft_putstr("\nLast modified: ");
	ft_putstr(file_time(sb));
	ft_putstr("\n");
}
