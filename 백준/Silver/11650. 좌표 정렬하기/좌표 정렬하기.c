#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}point;

point dot[100004];

int compare(const void* a, const void* b)
{
	if (((point*)a)->x == ((point*)b)->x)
	{
		return (((point*)a)->y - ((point*)b)->y);
	}
	return (((point*)a)->x - ((point*)b)->x);
}

int main()
{
	int N;

	scanf("%d", &N);

	for (int z = 0; z < N; z++)
	{
		scanf("%d %d", &dot[z].x, &dot[z].y);
	}

	qsort((point*)dot, N, sizeof(point), compare);

	for (int z = 0; z < N; z++)
	{
		printf("%d %d\n", dot[z].x, dot[z].y);
	}
}