/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:30:52 by student           #+#    #+#             */
/*   Updated: 2020/05/22 20:30:55 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_i;

	i = 0;
	s_i = (unsigned char*)s;
	while (i != n)
	{
		*(s_i + i) = (unsigned char)c;
		i++;
	}
	return (s_i);
}
