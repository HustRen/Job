#include "stdafx.h"
#include "selectionandsort.h"
#include <algorithm>

void quickSort(double a[], int p, int r)
{
	if (p < r)
	{
		int mid = partition(a, p, r);
		quickSort(a, p, mid - 1);
		quickSort(a, mid + 1, r);
	}
}

int partition(double a[], int p, int r)
{
	int j = p - 1;
	for (int i = p; i < r; i++)
	{
		if (a[i] < a[r])
		{
			j++;
			std::swap(a[i], a[j]);
		}
	}
	j++;
	std::swap(a[j], a[r]);
	return j;
}

void insertionSort(double a[], int length)
{
	for (int i = 1; i < length; i++)
	{
		int j = i - 1;
		int k = a[i];
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
}

void bubbleSort(double a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}

void selectionSort(double a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (a[j] < a[i])
			{
				std::swap(a[i], a[j]);
			}
		}
   }
}
