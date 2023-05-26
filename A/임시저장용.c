#include "header.h"


int main()
{

	int arr[] = { 3, 29, 38, 12, 57, 74, 40, 85, 61 };


	int n = 0, first = 0;

	int size = sizeof(arr) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; i < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				first = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = first;
			}
		}
	}

	for (int c = 0; c < size; c++)
	{
		printf("%d ", arr[c]);
	}


	return 0;
}