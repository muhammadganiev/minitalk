/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <gf.black.tv@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:14:25 by muganiev          #+#    #+#             */
/*   Updated: 2022/06/04 22:42:28 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	len_s;

	if (!s)
		return (0);
	len_s = (unsigned int)ft_strlen(s);
	if (len > len_s)
		len = len_s - start;
	if (start >= len_s)
		return (ft_strdup(""));
	ptr = malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}
