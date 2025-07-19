#include "cub3d.h"

void	print_error(const char *message)
{
	write(2, "Error\n", 6);
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

int		ft_strcmp(char *s1, char *s2)
{
	int i;

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

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == d)
		return ((char *) &s[i]);
	return (NULL);
}

int	is_empty_line(char *line)
{
	int	i = 0;

	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_texture_line(char *line)
{
	if (!line)
		return (0);

	while (*line == ' ' || *line == '\t')
		line++;

	return (
		ft_strncmp(line, "NO ", 3) == 0 ||
		ft_strncmp(line, "SO ", 3) == 0 ||
		ft_strncmp(line, "WE ", 3) == 0 ||
		ft_strncmp(line, "EA ", 3) == 0
	);
}

int	is_color_line(char *line)
{
	if (!line)
		return (0);

	while (*line == ' ' || *line == '\t')
		line++;

	return (
		ft_strncmp(line, "F ", 2) == 0 ||
		ft_strncmp(line, "C ", 2) == 0
	);
}

