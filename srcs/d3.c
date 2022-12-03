#include "../includes/AOC.h"


//----------========[PART 1]========----------
// char	finder(char *str)
// {
// 	int	len;
// 	int	i;
// 	int	y;

// 	i = 0;
// 	y = 0;
// 	len = (ft_strlen(str)) / 2;
// 	while (i < len)
// 	{
// 		y = 0;
// 		while (y < len)
// 		{
// 			if (str[i] == str[len + y])
// 				return (str[i]);
// 			y++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

//----------========[PART 2]========----------
char	finder(char *str1, int fd)
{
	char	*str2;
	char	*str3;
	int		a;
	int		b;
	int		c;

	str2 = get_next_line(fd);
	str3 = get_next_line(fd);
	a = 0;
	b = 0;
	c = 0;

	while (str1[a])
	{
		b = 0;
		while (str2[b])
		{
			if (str1[a] == str2[b])
			{
				c = 0;
				while (str3[c])
				{
					if (str1[a] == str3[c])
						return (str1[a]);
					c++;
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		tot;
	char	c;

	fd = 0;
	fd = open("fileInput/Input_d3.txt", O_RDONLY);

	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		write (1, line, ft_strlen(line));
		c = finder(line, fd);
		if (c > 96 && c < 123)
			tot += c - 96;
		else
			tot += c - 38;
		free(line);
	}
	printf("[%d]", tot);
	close(fd);
	return (0);
}