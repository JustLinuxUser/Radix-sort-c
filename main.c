#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_arr(int *arr, int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++)
	{
		printf(" %i,", arr[i]);
	}
	printf(" ]\n");
}

int get_dig(int n, int index)
{
	return (n % (int)pow(10, index + 1) -
			n % (int)pow(10, index)) /
		   (int)pow(10, index);
}

int *sort(int *arr, int n)
{
	int *ptr1 = arr;
	int *ptr2 = (int *)malloc(n * sizeof(int));
	int count[11] = {0};
	int length = 0;

	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			count[get_dig(ptr1[i], length) + 1]++;
		}
		if (count[1] == n)
			break;

		for (int i = 2; i < 11; i++)
		{
			count[i] = count[i] + count[i - 1];
		}
		int zero = 0;

		for (int i = 0; i < n; i++)
		{

			ptr2[count[get_dig(ptr1[i], length)]] = ptr1[i];

			count[get_dig(ptr1[i], length)]++;
		}

		length++;

		for (int c = 0; c < 11; c++)
		{
			count[c] = 0;
		}

		int *temp = ptr1;
		ptr1 = ptr2;
		ptr2 = temp;
	}
	print_arr(ptr1, n);
}

int main()
{
	int n = 50;
	int *arr = (int *)malloc(n * sizeof(int));
	int nums = 5;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (int)pow(10, nums);
	}

	sort(arr, n);

	return 0;
}
