#include<stdio.h>

int N, M;
int map[100][100];
int cmap[100][100];

void DFS(int x, int y)
{
	if (cmap[x][y] != 0) {
		return;
	}

	cmap[x][y] = 2;
	if (x > 0) {
		DFS(x - 1, y);
	}
	if (y > 0) {
		DFS(x , y-1);
	}
	if (x < N - 1) {
		DFS(x+1, y);
	}

	if (y < M - 1)
	{
		DFS(x , y+1);
	}
}


int count_near(int x, int y)
{
	int val = 0;

	if (cmap[x - 1][y] == 2) {
		val++;
	}

	if (cmap[x + 1][y] == 2) {
		val++;
	}

	if (cmap[x ][y-1] == 2) {
		val++;
	}

	if (cmap[x ][y+1] == 2) {
		val++;
	}

	return val;
}

int main(void)
{
	int i, j;
	int cnt = 0;

	scanf("%d %d", &N, &M);
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			int v;
			scanf("%d", &v);
			map[i][j] = v;
			cmap[i][j] = v;
			if (v == 1)
				cnt++;
		}
	}

	
	
#if 0
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d", cmap[i][j]);
		}
		printf("\n");
	}
#endif
	DFS(0, 0);

	int phase = 0;

	while (cnt != 0)
	{	
		int tmap[100][100];
				
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (cmap[i][j] == 0 && (cmap[i - 1][j] == 2 || cmap[i + 1][j] == 2 || cmap[i][j - 1] == 2 || cmap[i][j + 1] == 2))
				{
					DFS(i, j);
				}
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				tmap[i][j] = cmap[i][j];
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (cmap[i][j] == 1)
				{
					int ret = count_near(i, j);
					if (ret > 1) {
						tmap[i][j] = 2;
						cnt--;
					}
				}
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				cmap[i][j] = tmap[i][j];
			}
		}
		
#if 0
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				printf("%d", cmap[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
#endif
		phase++;

		
	}
	
	printf("%d\n", phase);

	return 0;
}