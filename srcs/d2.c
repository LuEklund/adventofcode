#include "../includes/AOC.h"
//A-X = Rock(1)
//B-Y = Papper(2)
//C-Z = Scissors(3)
//Lost=0; Draw=3; Win=6;
// win +1 more
// lost +2 more
// else draw

//PART 2
//X = LOSE
//Y = DRAW
//Z = WIN


//----------========[PART 1]========----------
// void	MaterialConverter(char *mat, int *tot_score_return)
// {
// 	int	opponent;
// 	int	you;

// 	opponent = (int)mat[0]-64;
// 	you = (int)mat[2]-87;
// 	if (opponent == you)
// 		*tot_score_return += you + 3;
// 	else
// 	{
// 		if (opponent == 3)
// 			opponent = 1;
// 		else
// 			opponent++;
// 		if (opponent == you)
// 			*tot_score_return += you + 6;
// 		else
// 			*tot_score_return += you + 0;
// 	}
// 	printf("opponent[%d] --- you[%d] -----> TOT[%d]\n", opponent,you,*tot_score_return);
// }

//----------========[PART 2]========----------
void	MaterialConverter(char *mat, int *tot_score_return)
{
	int	opponent;

	opponent = (int)mat[0]-64;
	if (mat[2] == 'X')
	{
		if (opponent == 3)
			opponent = 2;
		else if (opponent == 2)
			opponent = 1;
		else
			opponent = 3;
		*tot_score_return += opponent;
	}
	else if (mat[2] == 'Y')
		*tot_score_return += opponent + 3;
	else
	{
		if (opponent == 3)
			opponent = 1;
		else
			opponent += 1;
		*tot_score_return += opponent + 6;
	}
	printf("TOT[%d]\n",*tot_score_return);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		tot_score_return;

	fd = 0;
	fd = open("fileInput/input_d2.txt", O_RDONLY);

	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{

		write(1, line, ft_strlen(line));
		MaterialConverter(line, &tot_score_return);
		free(line);
	}
	close(fd);
	return (0);
}