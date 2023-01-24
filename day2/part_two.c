//ELF:  A-ROCK, B-PAPER, C-SCISSORS
// ME: X-LOSE-0, Y-DRAW-3, Z-WIN-6
// ME: 1-ROCK, 2-PAPER, 3-SCISSORS + OUTCOME: 0-LOST, 3-DRAW, 6-WIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	sum_row(char1, char2)
{
	int	sum = 0;
	if(char1 == 'A')
	{
		if (char2 == 'X') // lose
		{
			sum += 3; // me: scisors+3 
		}
		else if (char2 == 'Y') // draw-3
		{
			sum += (1 + 3); // me: rock+1
		}
		else if (char2 == 'Z') // win-6
		{
			sum += (6 + 2); // paper+2 + 6(win)
		}
		else
		{
			printf("suprise:::: no X,Y or Z");
			return(-1);
		}
	}
	else if (char1 == 'B') // paper
	{
		if (char2 == 'X') // lose
		{
			sum += 1; // rock-1
		}
		else if (char2 == 'Y') // draw+3
		{
			sum += (3 + 2); // paper+2
		}
		else if (char2 == 'Z') //win
		{
			sum += (6 + 3); // scissors+3
		}
		else
		{
			printf("suprise:::: no X,Y or Z");
			return(-1);
		}
	}
	else if (char1 == 'C') // scissors
	{
		if (char2 == 'X') //lose
		{
			sum += 2; //paper+2
		}
		else if (char2 == 'Y') //draw+3
		{
			sum += (3 + 3); //scis+3
		}
		else if (char2 == 'Z') // win
		{
			sum += (6 + 1); //rock+1
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