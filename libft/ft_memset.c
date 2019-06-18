/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:28:38 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/11 16:47:28 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	n;

	n = 0;
	while (n < len)
	{
		((unsigned char*)dest)[n] = (unsigned char)c;
		n++;
	}
	return (dest);
}
