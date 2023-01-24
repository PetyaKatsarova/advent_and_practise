/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   part_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/14 10:01:43 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/22 16:39:44 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

// To help prioritize item rearrangement, every item type can be converted to a priority:
// Lowercase item types a through z have priorities 1 through 26.
// Uppercase item types A through Z have priorities 27 through 52.

// int	main(void)
// {
// 	FILE *fp = fopen("proba2.txt", "r");
// 	char	line[50] = {0};
// 	int		sum = 0, i = 0, j = 0, k = 0, check = 0;

// 	while (fgets(line, sizeof(line), fp) != NULL)
// 	{	
// 		char	sorted_line[50];
// 		char	ch;
// 		char	arr_2d[3][50];
// 		// sort line
// 				/* sorting process */
// 		for (i = 1; i < strlen(line); i++)
// 			for (j = 0; j < strlen(line) - i; j++)
// 			if(line[j] > line[j + 1])
// 			{
// 			ch = line[j];
// 			line[j] = line[j + 1];
// 			line[j + 1] = ch;
// 		}
// 		arr_2d[k][50] = line;
// 		printf("%s", arr_2d[k]);
		
// 		// for (int bla = 0; bla < 3; bla++)
// 		// {
// 		// 	printf("\narr %i: %s\n", k, arr_2d[k]);
// 		// }
// 		// printf("%s", line);
		
// 		if (k <= 1)
// 			k++;
// 		else
// 		{
// 			printf("     ------------- yes!! --------------\n");
// 			k = 0;
// 		}
			
// 		//sort original line
// 		//printf("%i: %c\n", ++check, line[i]);
// 	}
// 	//printf("sum: %i\n", sum);
// 	fclose(fp);
// 	return (sum);
// }
//2499
int main()
{
    FILE* fd = fopen("list_of_items.txt", "r");
    char line0[50] = {0}, line1[50] = {0}, line2[50] = {0};
    int i = 0, amount = 0, k = 0;
    while (fgets(line0, 50, fd))
    {
		// get one line at a time
        printf("line0[%04d]: %s", ++i, line0);
        fgets(line1, 50, fd);
        printf("line1[%04d]: %s", ++i, line1);
        fgets(line2, 50, fd);
        printf("line2[%04d]: %s", ++i, line2);
        char letters[52] = {0};
        for (int j = 0; j < strlen(line0) - 1; j++)
        {
            int y = 0;
            if (line0[j] >= 'A' && line0[j] <= 'Z')
                y = line0[j] - 'A' + 26;
            else
                y = line0[j] - 'a';
            letters[y] = 2;
        } // filled letters with key letter val 2
        for (int j = 0; j < strlen(line1) - 1; j++)
        {
            if (line1[j] >= 'A' && line1[j] <= 'Z' && letters[line1[j] - 'A' + 26] != 0)
                letters[line1[j] - 'A' + 26] = 6;
            else if (letters[line1[j] - 'a'] != 0 && line1[j] >= 'a' && line1[j] <= 'z')
                letters[line1[j] - 'a'] = 6;
        }
        // while (k < strlen(line2))
        // {
        //     if ((line2[k] <= 'Z' && line2[k] >= 'A' && letters[line2[k] - 'A' + 26] == 6) 
        //         || (line2[k] <= 'z' && line2[k] >= 'a' && letters[line2[k] - 'a'] == 6))
        //         break;
        //     k++;
        // }
        // if (line2[k] >= 'A' && line2[k] <= 'Z')
        //     amount += 1 + line2[k] - 'A' + 26;
        // else
        //     amount += 1 + line2[k] - 'a';
        // printf("amount == %d, line2[k] = %c\n", amount, line2[k]);
        k = 0;
    }
    fclose(fd);
    return 0;
}
