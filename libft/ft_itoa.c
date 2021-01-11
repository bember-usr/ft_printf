/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:54:52 by student           #+#    #+#             */
/*   Updated: 2020/05/27 22:44:21 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_numlength(int nbr)
{
	int				size;
	int				m;

	size = 0;
	m = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0 && nbr > -2147483648)
	{
		m = 1;
		nbr *= (-1);
		size++;
	}
	else if (nbr == -2147483648)
		return (11);
	while (nbr >= 1)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int nbr)
{
	char			*str;
	int				i;
	int				m;
	unsigned int	u_n;
	int				size;

	i = 1;
	m = (nbr < 0 ? 1 : 0);
	size = f_numlength(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	u_n = (nbr < 0 ? -nbr : nbr);
	if (u_n == 0)
		str[u_n] = '0';
	while (u_n >= 1)
	{
		str[size - i] = '0' + u_n % 10;
		u_n /= 10;
		i++;
	}
	if (m)
		*str = '-';
	str[size] = '\0';
	return (str);
}
