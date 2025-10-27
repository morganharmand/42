/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	chr;

	len = ft_strlen(s);
	chr = (char)c;
	if (chr == '\0')
	{
		return ((char *)&s[len]);
	}
	while (len > 0)
	{
		if (s[len] == chr)
		{
			return ((char *)&s[len]);
		}
		len--;
	}
	if (s[0] == chr)
	{
		return ((char *)s);
	}
	return (NULL);
}
