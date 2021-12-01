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
	int count[10] = {0};
	int length = 0;
	for (int z = 0; z < 4; z++)
	{
		for (int i = 0; i < n; i++)
		{
			count[get_dig(ptr1[i], length)]++;
		}

		for (int i = 1; i < 10; i++)
		{
			count[i] = count[i] + count[i - 1];
		}
		int zero = 0;
		for (int i = 0; i < n; i++)
		{
			if (get_dig(ptr1[i], length) == 0)
			{
				ptr2[zero] = ptr1[i];
				zero++;
			}
			else
			{
				ptr2[count[get_dig(ptr1[i], length)] - 1] = ptr1[i];
				count[get_dig(ptr1[i], length)]--;
			}
		}

		length++;

		print_arr(count, 10);
		for (int c = 0; c < 10; c++)
		{
			count[c] = 0;
		}

		int *temp = ptr1;
		ptr1 = ptr2;
		ptr2 = temp;
		print_arr(ptr1, 10);
	}
}

int main()
{
	int arr[] = {1222, 32, 5, 765, 75, 75, 3, 2, 9, 870};
	sort(arr, 10);

	return 0;
}
