/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/14 10:01:43 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/20 11:00:01 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To help prioritize item rearrangement, every item type can be converted to a priority:
// Lowercase item types a through z have priorities 1 through 26.
// Uppercase item types A through Z have priorities 27 through 52.


int	main(void)
{
	FILE *fp = fopen("list_of_items.txt", "r");
	char	line[50] = {0};
	int		check = 0, sum = 0, flag = 0;

	while (fgets(line, sizeof(line), fp) != NULL)
	{
		printf("line: %i: ", ++check);
		for (int i = 0; i < (strlen(line) / 2); i++)
		{
			for (int j = (strlen(line) / 2); j < strlen(line); j++)
			{
				if (line[i] == line[j])
				{
					printf("yes: %c\n", line[i]);
					if (line[i] >= 'A' && line[i] <= 'Z')
					{
						sum += line[i] - 'A' + 27;
					}
					else if (line[i] >= 'a' && line[i] <= 'z')
					{
						sum += line[i] - 'a' + 1;
					}
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				flag = 0;
				break;
			}		
		}
		// printf("sum: %i\n", sum);
	}
	printf("sum: %i\n", sum);
	fclose(fp);
	//printf("final sum: %d", sum);
	return (sum);
}
