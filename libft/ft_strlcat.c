/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:49:03 by student           #+#    #+#             */
/*   Updated: 2020/05/22 20:49:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;

	len = ft_strlen(dst);
	if (size < len)
		return (size + ft_strlen(src));
	while (*src && len < size - 1)
	{
		dst[len] = *src;
		src++;
		++len;
	}
	dst[len] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
