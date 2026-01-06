/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idait-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:02:26 by idait-el          #+#    #+#             */
/*   Updated: 2025/12/17 16:02:28 by idait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_hex(unsigned int num, int is_upper);
int		ft_print_ptr(void *ptr_val);
int		ft_print_unsigned_decimal(unsigned int n);
int		ft_print_decimal(int n);
size_t	ft_strlen(const char *s);

#endif
