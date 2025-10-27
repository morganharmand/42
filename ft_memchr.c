/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*str;
	unsigned char	chr;

	i = 0;
	str = (const char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if ((unsigned char)str[i] == chr)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
