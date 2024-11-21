/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:41:44 by oukhanfa          #+#    #+#             */
/*   Updated: 2024/11/07 16:35:59 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*last = NULL;
	unsigned char	a;

	a = (unsigned char)c;
	while (*s)
	{
		if (*s == a)
			last = s;
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return ((char *)last);
}
