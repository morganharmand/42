/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static void	ft_rec_copy(char *d, const char *s, size_t i, size_t max_len)
{
	if (i < max_len)
	{
		d[i] = s[i];
		ft_rec_copy(d, s, i + 1, max_len);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	actual_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	actual_len = len;
	if (len > s_len - start)
		actual_len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (actual_len + 1));
	if (!substr)
		return (NULL);
	ft_rec_copy(substr, s + start, 0, actual_len);
	substr[actual_len] = '\0';
	return (substr);
}
