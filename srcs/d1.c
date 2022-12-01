#include "../includes/AOC.h"

int	save_value(char *str, t_Elves *Elves)
{
	int	add;

	add = atoi(str);
	if (add)
	{
		Elves->kcal_current = Elves->kcal_current + add;
		return (add);
	}
	return (0);
}

void	higest(t_Elves *Elves)
{
	if (Elves->kcal_current > Elves->kcal_higest)
		{
		Elves->kcal_higest_third = Elves->kcal_higest_sec;
		Elves->kcal_higest_sec = Elves->kcal_higest;
		Elves->kcal_higest = Elves->kcal_current;
		}
	else if (Elves->kcal_current > Elves->kcal_higest_sec)
	{
		Elves->kcal_higest_third = Elves->kcal_higest_sec;
		Elves->kcal_higest_sec = Elves->kcal_current;
	}
	else if (Elves->kcal_current > Elves->kcal_higest_third)
		Elves->kcal_higest_third = Elves->kcal_current;
	Elves->kcal_current = 0;
}

int	main(void)
{
	char	*line;
	int		fd;
	t_Elves Elves = {0, 0, 0};

	fd = 0;
	fd = open("fileInput/input_d1.txt", O_RDONLY);

	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!save_value(line, &Elves))
			higest(&Elves);

		write(1, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	if (Elves.kcal_current)
		higest(&Elves);
	
	printf("HIGEST_TOTVALUE=[%d]\n", Elves.kcal_higest + Elves.kcal_higest_sec + Elves.kcal_higest_third);
	return (0);
}
