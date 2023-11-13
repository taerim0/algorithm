#include <stdio.h>
#include <stdlib.h>

double arr1[500001], arr2[500001];
int low, high, mid;

int compare(const void* a, const void* b)  
{
	double num1 = *(double*)a;  
	double num2 = *(double*)b;  

	if (num1 < num2)   
		return -1;   

	if (num1 > num2)    
		return 1;       

	return 0;  
}

int binarysearch(double n)
{
	if (low > high) return 0;

	mid = (low + high) / 2;

	if (arr1[mid] == n) return 1;

	if (arr1[mid] < n)
	{
		low = mid + 1;
		return binarysearch(n);
	}

	high = mid - 1;
	return binarysearch(n);
}

int main()
{
	int N, M;

	scanf("%d", &N);

	for (int z = 0; z < N; z++)
	{
		scanf("%lf", &arr1[z]);
	}

	qsort(arr1, N, sizeof(double), compare);

	scanf("%d", &M);

	for (int z = 0; z < M; z++)
	{
		scanf("%lf", &arr2[z]);
	}

	for (int z = 0; z < M; z++)
	{
		low = 0;
		high = N - 1;
		printf("%d ", binarysearch(arr2[z]));
	}
}
