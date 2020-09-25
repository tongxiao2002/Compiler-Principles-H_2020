#include <stdio.h>
#include <stdlib.h>

void Swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Select_Sort(int Array[], int Array_length)
{
    for(int i = 0; i < Array_length; i++)
    {
        int k = i;
        int min = Array[i];
        for(int j = i + 1; j < Array_length; j++)
        {
            if(Array[j] < min)
            {
                k = j;
                min = Array[j];
            }
        }
        Swap(&Array[i], &Array[k]);
    }
}

int main()
{
	int n;
	int print_n = 0;
	scanf("%d", &n);
	int *Array = (int *)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &Array[i]);
		//Array[i] = 21000 - 100 * i;
	}
/*	for(int i = 0; i < n; i++)
 *	{
 *		printf("%d ", Array[i]);
 *		if(Array[i] != 0)
 *		{
 *			print_n++;
 *		}
 *	}
 */
/*	for(print_n = 0; print_n < 1001 && Array[print_n] != 0; print_n++)
	{
		int value = Array[print_n];
		if(value >= -1411 && value <= 330)
		{
			printf("%d ", value);
		}
	}
*/
//	printf("\n");
//	int same_num = 0;
	Select_Sort(Array, n);
/*	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			if(Array_1[i] == Array[j])
			{
				same_num++;
				break;
			}
			else if(j == 999)
			{
				printf("%d ", Array_1[i]);
			}
		}
	}
*/
//	printf("\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", Array[i]);
	}
	free(Array);
//	printf("\n%d", same_num);
	
	return 0;
}

