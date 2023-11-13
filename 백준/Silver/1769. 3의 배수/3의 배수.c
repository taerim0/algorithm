#include<stdio.h>
#include<string.h>

int main()
{
	char X[1000001] = { 0 };
	int value1 = 0, value2 = 0;

	scanf("%s", &X);

	if (strlen(X) == 1)
	{
		printf("0\n");
		if ((X[0] - 48) % 3 == 0)
		{
			printf("YES");
		}
		else
		{
			printf("NO");
		}

		return 0;
	}

	for (int z = 0; z < strlen(X); z++)
	{
		value1 += X[z] - 48;
	}

	int t = 1;

	while (value1 > 9)
	{
		while (value1 != 0)
		{
			value2 += value1 % 10;
			value1 /= 10;
		}

		t++;
		value1 = value2;
		value2 = 0;
	}

	printf("%d\n", t);

	if (value1 % 3 == 0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}
