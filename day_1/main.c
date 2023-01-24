/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 17:13:14 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/13 11:57:10 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	FILE	*fp = fopen("calories.txt", "r");
	char	line[10] = {0};
	int		i = 0, max1 = 0, max2 = 0, max3 = 0, sum = 0, num;
	while (fgets(line, 10, fp))
	{
		num = atoi(line);
		sum += num;
		if (line[0] == '\n')
		{
			if (sum > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = sum;
			}
			else if (sum > max2)
			{
				max3 = max2;
				max2 = sum;
			}
			else if (sum > max3)
			{
				max3 = sum;
			}
			//printf("max sum elf: %i: %i\n", ++i, max1);
			sum = 0;
		}

	}
	fclose(fp);
	printf("max cal: %i", max1 + max2 + max3);
	return (0);
}