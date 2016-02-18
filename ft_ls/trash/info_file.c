/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:04:28 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/27 11:10:13 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*char	*file_type(struct stat mystat)
{
	if ((mystat.st_mode & S_IFMT) == S_IFBLK)
		return ("block");
	if ((mystat.st_mode & S_IFMT) == S_IFCHR)
		return ("character special file");
	if ((mystat.st_mode & S_IFMT) == S_IFDIR)
		return ("directory");
	if ((mystat.st_mode & S_IFMT) == S_IFIFO)
		return ("pipe");
	if ((mystat.st_mode & S_IFMT) == S_IFLNK)
		return ("link");
	if ((mystat.st_mode & S_IFMT) == S_IFSOCK)
		return ("socket");
	if ((mystat.st_mode & S_IFMT) == S_IFREG)
		return ("regular file");
	else
		return ("unknown");
}
*/
char	*file_perm(struct stat mystat)
{
	char	*perm;

	perm = (char *)malloc(sizeof(char) * 11);
	perm[0] = (S_ISDIR(mystat.st_mode) ? 'd' : '-');
	perm[1] = (mystat.st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (mystat.st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (mystat.st_mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (mystat.st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (mystat.st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (mystat.st_mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (mystat.st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (mystat.st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (mystat.st_mode & S_IXOTH) ? 'x' : '-';
	perm[10] = '\0';
	return (perm);
}

int		file_links(struct stat mystat)
{
	return (mystat.st_nlink);
}

char	*file_owner(struct stat mystat)
{
	struct passwd	*pw;

	pw = getpwuid(mystat.st_uid);
	return (pw->pw_name);
}

char	*file_group(struct stat mystat)
{
	struct group	*gr;

	gr = getgrgid(mystat.st_gid);
	return (gr->gr_name);
}

int		file_size(struct stat mystat)
{
	return (mystat.st_size);
}

char	*file_time(struct stat mystat)
{

	return (ft_strndup(&(ctime(&mystat.st_mtime))[4], 12));
}

int		ft_ls_l(int argc, char **argv)
{
	struct stat		mystat;
	struct dirent	*myfile;
	DIR				*mydir;

	mydir = opendir(argv[2]);
	if (argc < 3)
		mydir = opendir(".");
	while ((myfile = readdir(mydir)) != NULL)
	{
	stat(myfile->d_name, &mystat);
	ft_putstr(file_perm(mystat));
	ft_putchar('\t');
	ft_putnbr(file_links(mystat));
	ft_putchar(' ');
	ft_putstr(file_owner(mystat));
	ft_putstr("  ");
	ft_putstr(file_group(mystat));
	ft_putstr(" ");
	ft_putnbr(file_size(mystat));
	ft_putchar(' ');
	ft_putstr(file_time(mystat));
	ft_putchar(' ');
	ft_putendl(myfile->d_name);
	}
	if (closedir(mydir) == -1)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	ft_ls_l(argc, argv);
}
