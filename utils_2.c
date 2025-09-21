/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:46:05 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/21 10:52:49 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if ((!s1 && !s2 && n == 0) || (!s1 && n == 0))
		return (0);
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	*ft_memset(void *str, int ch, size_t n)
{
	unsigned char	*buffer;
	unsigned char	letter;
	size_t			i;

	buffer = (unsigned char *) str;
	letter = (unsigned char) ch;
	i = 0;
	while (i < n)
	{
		buffer[i] = letter;
		i++;
	}
	return (str);
}

static int	check_sign(char str, int sign)
{
	if (str == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		res;
	long		temp;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign (str[i++], sign);
	while (str[i] >= 48 && str[i] <= 57)
	{
		temp = res;
		res = res * 10 + (sign * (str[i] - 48));
		if ((res / 10) != temp && sign == 1)
			return (-1);
		else if ((res / 10) != temp && sign == -1)
			return (0);
		i++;
	}
	return (res);
}
