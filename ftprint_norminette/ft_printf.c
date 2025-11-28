/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Implémente la fonction de base pour l'impression de caractère (%c)
int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

// Gère %%
int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}

// Gère %s (avec gestion NULL)
int	ft_print_str(char *str)
{
	int	size;

	if (str == 0)
	{
		return (ft_putstr_local("(null)"));
	}
	size = ft_strlen(str);
	return (write(1, str, size));
}

// Fonction qui exécute la boucle principale (pour ft_printf)
int	ft_vprintf(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_conversion(format[i], args);
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	size = ft_vprintf(format, args);
	va_end(args);
	return (size);
}
