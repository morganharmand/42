/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	ft_free_array(char **str, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_get_next_word(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	len;

	start = *i;
	len = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		*i = *i + 1;
		len++;
	}
	return (ft_substr(s, start, len));
}

static char	**ft_allocate_words(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			result[j] = ft_get_next_word(s, c, &i);
			if (!result[j])
			{
				ft_free_array(result, j);
				return (NULL);
			}
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
	{
		return (NULL);
	}
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
	{
		return (NULL);
	}
	return (ft_allocate_words(s, c, result));
}
