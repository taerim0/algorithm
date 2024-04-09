#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, t, change, co;
char string[1000], result[1000];

int main()
{

	scanf("%d", &N);
	getchar();

	for (int z = 0; z < N; z++)
	{
		scanf("%s", string);
		getchar();

		t = 0;
		change = 0;
		co = 0;

		for (int x = 0; x < strlen(string); x++)
		{
			switch (string[x])
			{
			case '@':
				result[t] = 'a';
				t++;
				change++;
				break;
			case '[':
				result[t] = 'c';
				t++;
				change++;
				break;
			case '!':
				result[t] = 'i';
				t++;
				change++;
				break;
			case ';':
				result[t] = 'j';
				t++;
				change++;
				break;
			case '^':
				result[t] = 'n';
				t++;
				change++;
				break;
			case '0':
				result[t] = 'o';
				t++;
				change++;
				break;
			case '7':
				result[t] = 't';
				t++;
				change++;
				break;
			case '\\':
				co++;
				break;
			case '\'':
				if (co == 1) result[t] = 'v';
				else if (co == 2) result[t] = 'w';
				co = 0;
				t++;
				change++;
				break;
			default:
				result[t] = string[x];
				t++;
				break;
			}
		}

		result[t] = NULL;

		if (change >= (t+1) / 2) printf("I don't understand\n");
		else printf("%s\n", result);


	}
}