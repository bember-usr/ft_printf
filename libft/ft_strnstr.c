/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:27:42 by student           #+#    #+#             */
/*   Updated: 2020/05/27 00:11:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		i;

	if (to_find[0] == '\0')
		return ((char*)str);
	if (str == '\0' || n < 1)
		return (NULL);
	i = 0;
	while (i < n && to_find[i] == str[i] && str[i] != '\0')
	{
		i++;
		if (to_find[i] == '\0')
			return ((char*)str);
	}
	if (str[i] == '\0' || i == n)
		return (NULL);
	return (ft_strnstr(str + 1, to_find, n - 1));
}
