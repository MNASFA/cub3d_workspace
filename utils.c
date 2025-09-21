/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:42:56 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/21 10:45:49 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(const char *message)
{
	write(2, "Error : ", 8);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

int	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len ++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buffer_dest;
	unsigned char	*buffer_src;

	if (dest == src)
		return (dest);
	buffer_dest = (unsigned char *) dest;
	buffer_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		buffer_dest[i] = buffer_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		len;

	len = ft_strlen (str);
	ptr = (char *) malloc((len + 1) * sizeof (char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, (char *) str, len + 1);
	return (ptr);
}
