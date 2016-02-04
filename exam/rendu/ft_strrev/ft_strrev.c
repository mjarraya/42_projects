/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:44:08 by mjarraya          #+#    #+#             */
/*   Updated: 2016/01/28 16:09:24 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	j = i;
	i = 0;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j - 1];
		str[j - 1] = tmp;
		i++;
		j--;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	printf("%s\n", ft_strrev(argv[1]));
	return (0);
}
