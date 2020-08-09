#include <stdio.h>
#include <time.h>

#define TRUE	1
#define FALSE	0

typedef int BOOL;

int main()
{
	int border;
	int i, j;
	int temp;
	int count = 0;
	BOOL is_prime = FALSE;
	clock_t begin;
	clock_t end;

	printf("Input a number: ");
	scanf_s("%d", &border);

	begin = clock();
	for (i = 2; i <= border; i++)
	{
		temp = i / 2 + 1;
		is_prime = TRUE;
		for (j = 2; j < temp; j++)
		{
			if (0 == i % j)
			{
				is_prime = FALSE;
				break;
			}
		}

		if (is_prime)
		{
			count++;
			printf("%d\t", i);
			if (0 == count % 20)
			{
				printf("\n");
			}
		}
	}
	end = clock();

	printf("\nThere are %d prime numbers is %d\n", count, border);
	printf("Time cost: %.2f s\n", (double)(end - begin) / CLOCKS_PER_SEC);

	return 0;
}