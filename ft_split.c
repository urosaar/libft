/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhanfa <oukhanfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:51:06 by oukhanfa          #+#    #+#             */
/*   Updated: 2024/11/07 17:12:03 by oukhanfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
		{
			i = 0;
		}
		s++;
	}
	return (count);
}

static char	*std(const char *s, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	frll(char **split, int j)
{
	while (j--)
		free(split[j]);
	free(split);
}

static char	**norm(char **result, const char *s, char c, int j)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			len = i - start;
			result[j++] = std(s + start, len);
			if (!result[j - 1])
			{
				frll(result, j);
				return (NULL);
			}
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!result)
		return (NULL);
	return (norm(result, s, c, j));
}
