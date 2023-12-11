#include <stdio.h>

int sdoku[10][10], blank[100] = { 0 }, calcul[100] = { 0 }, i = 0;

int find(int n, int col, int row)
{
	for (int z = 0; z < 9; z++)
	{
		if (n == sdoku[col][z]) return 1;
	}
	for (int z = 0; z < 9; z++)
	{
		if (n == sdoku[z][row]) return 1;
	}

	int boxcol = col / 3;
	int boxrow = row / 3;

	for (int z = boxcol * 3; z < boxcol * 3 + 3; z++)
	{
		for (int x = boxrow * 3; x < boxrow * 3 + 3; x++)
		{
			if (n == sdoku[z][x]) return 1;
		}
	}

	return 0;
}

void printsdoku()
{
	for (int z = 0; z < 9; z++)
	{
		for (int x = 0; x < 9; x++)
		{
			printf("%d ", sdoku[z][x]);
		}
		printf("\n");
	}
}

int calculate(int n)
{
	if (n == i)
	{
		printsdoku();
		return 1;
	}

	for (int z = 1; z <= 9; z++)
	{
		sdoku[blank[n] / 10][blank[n] % 10] = 0;
		if (find(z, blank[n] / 10, blank[n] % 10)) continue;

		sdoku[blank[n] / 10][blank[n] % 10] = z;
		calcul[n] = z;
		if (calculate(n + 1)) return 1;
	}

	sdoku[blank[n] / 10][blank[n] % 10] = 0;

	return 0;
}

int main()
{
	for (int z = 0; z < 9; z++)
	{
		for (int x = 0; x < 9; x++)
		{
			scanf("%d", &sdoku[z][x]);
		}
	}

	for (int z = 0; z < 9; z++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (sdoku[z][x] == 0)
			{
				blank[i] = z * 10 + x;
				i++;
			}
		}
	}

	calculate(0);
}