//ELF:  A-ROCK, B-PAPER, C-SCISSORS
// ME: X-ROCK, Y-PAPER, Z-SCISSORS
// 1-ROCK, 2-PAPER, 3-SCISSORS + OUTCOME: 0-LOST, 3-DRAW, 6-WIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	sum_row(char1, char2)
{
	int	sum = 0;
	if(char1 == 'A')
	{
		if (char2 == 'X')
		{
			sum += (1 + 3);
		}
		else if (char2 == 'Y')
		{
			sum += (2 + 6);
		}
		else if (char2 == 'Z')
		{
			sum += 3;
		}
		else
		{
			printf("suprise:::: no X,Y or Z");
			return(-1);
		}
	}
	else if (char1 == 'B')
	{
		if (char2 == 'X')
		{
			sum += 1;
		}
		else if (char2 == 'Y')
		{
			sum += (2 + 3);
		}
		else if (char2 == 'Z')
		{
			sum += (3 + 6);
		}
		else
		{
			printf("suprise:::: no X,Y or Z");
			return(-1);
		}
	}
	else if (char1 == 'C')
	{
		if (char2 == 'X')
		{
			sum += (1 + 6);
		}
		else if (char2 == 'Y')
		{
			sum += 2;
		}
		else if (char2 == 'Z')
		{
			sum += (3 + 3);
		}
		else
		{
			printf("suprise:::: no X,Y or Z");
			return(-1);
		}
	}
	else
	{
		printf("SUPRISE: NO A, B or C");
		return (-1);
	}
	return(sum);
}

int	main(void)
{
	FILE 	*fp = fopen("strategy_guide.txt", "r");
	char	line[10] = {0};
	int		sum = 0;

	while(fgets(line, 10, fp))
	{
		sum += sum_row(line[0], line[2]);
		//printf("%c -- %c && sum: %i\n", line[0], line[2], sum_row(line[0], line[2]));
	}
	fclose(fp);
	printf("final sum: %i\n", sum);
	return (0);
}