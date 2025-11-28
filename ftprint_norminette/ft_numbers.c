/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long n, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += write(1, &base[n % base_len], 1);
	return (count);
}

int	ft_print_dec(int n)
{
	int		count;
	long	nb;

	count = 0;
	if (n == INT_MIN)
		return (ft_putstr_local("-2147483648"));
	nb = n;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = ft_abs_l(nb);
	}
	if (n == 0)
		return (write(1, "0", 1));
	count += ft_putnbr_base((unsigned long)nb, "0123456789");
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	return (ft_putnbr_base((unsigned long)n, "0123456789"));
}

int	ft_print_hex(unsigned int n, char format)
{
	char	*base;

	if (n == 0)
		return (write(1, "0", 1));
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_putnbr_base((unsigned long)n, base));
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr_local("0x");
	if (ptr == 0)
		count += write(1, "0", 1);
	else
		count += ft_putnbr_base(ptr, "0123456789abcdef");
	return (count);
}
