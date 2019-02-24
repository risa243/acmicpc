#include<stdio.h>

int map[2200][2200];
int K;

int zero;
int minus;
int plus;

void adder(int num)
{
	if (num == 0)
	{
		zero++;
	}
	else if (num == 1)
	{
		plus++;
	}
	else {
		minus++;
	}
}

void dfs(int sx, int sy, int n)
{
	int i, j;

	int num = map[sx][sy];
	int flags = 0;

	//printf("%d %d %d\n", sx, sy, n);

	if (n == 1)
	{
		adder(num);
		return;
	}

	for (i = sx; i < sx+n; i++)
	{
		for (j = sy; j < sy+n; j++)
		{
			//printf("%d %d\n", num, map[i][j]);
			if (num != map[i][j])
			{
				int k, l;
				flags = 1;
				for (k = sx; k < sx + n; k = k + (n / 3))
				{
					for (l = sy; l < sy + n; l = l + (n / 3))
					{
						dfs(k, l, (n / 3));
					}
				}
				goto out;					
			}
		}
	}

out:
	if (flags == 0)
	{
		adder(num);
	}
}

int getK(int n)
{
	int k = 0;
	while (n != 1) {
		n = n / 3;
		k++;
	}

	return k;
}

int main(void)
{
	int N;

	scanf("%d", &N);
	K = getK(N);

	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			int val;
			scanf("%d", &val);
			map[i][j] = val;
		}
	}

	dfs(0, 0, N);
	
	printf("%d\n%d\n%d\n", minus, zero, plus);

	return 0;

}

