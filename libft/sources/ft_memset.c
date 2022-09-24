/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <gf.black.tv@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:40:28 by muganiev          #+#    #+#             */
/*   Updated: 2022/06/04 23:35:12 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t	i;

// 	if (!b)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		*(unsigned char *)(b + i) = (unsigned char)c;
// 		i++;
// 	}
// 	return (b);
// }

void	*ft_memset(void *buf, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)buf;
	while (len > i)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (buf);
}
