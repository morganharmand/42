/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// --- Prototypes des fonctions d'impression (Conversions) ---

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_dec(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char format);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_percent(void);

// --- Utilitaires ---

size_t	ft_strlen(const char *s);
long	ft_abs_l(long n);
int		ft_putstr_local(char *s);

// --- Fonctions principales ---

int		ft_vprintf(const char *format, va_list args);
int		ft_handle_conversion(char specifier, va_list args);
int		ft_printf(const char *format, ...);

#endif