/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:02:57 by idait-el          #+#    #+#             */
/*   Updated: 2025/12/17 16:03:02 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	len = 0;
	len = ft_strlen(str);
	return (write(1, str, len));
}
