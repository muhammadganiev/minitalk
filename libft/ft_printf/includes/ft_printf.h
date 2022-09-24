/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:41:03 by muganiev          #+#    #+#             */
/*   Updated: 2022/09/24 14:36:10 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../includes/libft.h"

int	ft_printf(const char *s, ...);
int	print_char(va_list args);
int	print_str(va_list args);
int	print_int(va_list args);
int	print_uint(va_list args);
int	print_hex(va_list args, char c);
int	print_pointer(va_list args);

#endif
