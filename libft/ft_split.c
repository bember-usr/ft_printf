/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:43:00 by student           #+#    #+#             */
/*   Updated: 2020/05/25 19:39:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	f_strlen(char const *s, char c, int i)
{
	size_t j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static char		**f_free(char **new_s, size_t j)
{
	while (j-- > 0)
		free(new_s[j]);
	free(new_s);
	return (NULL);
}

static char		**rec_arr(char **new_s, const char *s, char c)
{
	size_t i;
	size_t j;
	size_t size;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			size = f_strlen(s, c, i);
			new_s[j] = ft_substr(s, i, size);
			if (new_s[j] == NULL)
				return (f_free(new_s, j));
			i += size;
			j++;
		}
		else
			i++;
	}
	new_s[j] = NULL;
	return (new_s);
}

char			**ft_split(char const *s, char c)
{
	char	**new_s;
	int		size_s;
	int		i;

	i = 0;
	size_s = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			size_s++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	new_s = (char**)malloc(sizeof(char*) * (size_s + 1));
	if (new_s)
		return (rec_arr(new_s, s, c));
	return (NULL);
}
