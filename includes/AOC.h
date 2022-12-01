#ifndef AOC_H
# define AOC_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int			last;
	char		*save;
}				t_list;

typedef struct s_Elves
{
	int			kcal_higest;
	int			kcal_higest_sec;
	int			kcal_higest_third;	
	int			kcal_current;
}				t_Elves;

char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
#endif