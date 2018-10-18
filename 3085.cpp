#include<stdio.h>

char candy[50][50];
int N;

int max = 0;

void cswitch (int x1, int y1, int x2, int y2)
{
	char tmp;

	tmp = candy[x1][y1];
	candy[x1][y1] = candy[x2][y2];
	candy[x2][y2] = tmp;	
}

void count(int a, int b)
{
	char ch;
	int cnt = 1;
	int x, y;

	x = a;
	y = b;


	ch = candy[x][y];

	while (candy[--x][y] == ch && x >= 0) {
		cnt++;
	}

	x = a;
	y = b;

	while (candy[++x][y] == ch && x <= N-1) {
		cnt++;
	}

	if (cnt > max)
	{
		max = cnt;
	}

	cnt = 1;
	x = a;
	y = b;

	while (candy[x][--y] == ch && y >= 0) {
		cnt++;
	}

	x = a;
	y = b;
	while (candy[x][++y] == ch && y <= N - 1) {
		cnt++;
	}

	if (cnt > max)
	{
		max = cnt;
	}
	
}


int main(void)
{
	int i;
	int j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			char ch;
			scanf(" %c ", &ch);
			candy[i][j] = ch;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i != 0) {
				cswitch(i, j, i - 1, j);
				count(i, j);
				count(i - 1, j);
				
				cswitch(i, j, i - 1, j);
			}

			if (i != N - 1)
			{
				cswitch(i, j, i + 1, j);
				count(i, j);
				count(i+1, j);

				cswitch(i, j, i + 1, j);
			}

			if (j != 0) {
				cswitch(i, j, i , j-1);

				count(i, j);
				count(i , j-1);
				cswitch(i, j, i, j - 1);
			}

			if (j != N - 1) {
				cswitch(i, j, i, j + 1);
				count(i, j);
				count(i, j + 1);
				cswitch(i, j, i, j + 1);
			}

		}
	}
	printf("%d\n", max);
}