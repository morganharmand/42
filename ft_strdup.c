/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
