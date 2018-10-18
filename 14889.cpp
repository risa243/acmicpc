#include<stdio.h>

int map[20][20];
int diff = 100 * 20 * 20;
int N;

int count_diff(unsigned long flags)
{
	int i;
	int j;
	int start = 0;
	int link = 0;

	int start_cnt = 0;
	int link_cnt = 0;
	for (i = 0; i < N; i++)
	{		
		if ((1 << i)&flags) {
			
			for (j = 0; j < N; j++)
			{				
				if ((1 << j) & flags)
				{
					
					start = start + map[i][j];
				}
			}		
		}
		else {
			link_cnt++;
			for (j = 0; j < N; j++)
			{
				if (!((1 << j) & flags))
				{					
					link = link + map[i][j];
				}
			}

		}
	}


	if (start > link) {
		return start - link;
	}
	else {
		return link - start;
	}
}

void DFS(int idx, int cnt, unsigned long flags)
{


	if (idx >= N) {
		return;
	}

	if (cnt == N/2) {
		int ret = count_diff(flags);
		if (diff > ret) {
			diff = ret;
		}
		return;		
	}
	else {
		DFS(idx + 1, cnt + 1, (flags | (1 << idx+1)));
		DFS(idx + 1, cnt, flags);
	}
}

int main(void)
{
	int i, j;
	unsigned long flag = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			int v;
			scanf("%d", &v);
			map[i][j] = v;
		}
	}

	DFS(0, 1, 1);
	DFS(0, 0, 0);
		
	printf("%d\n", diff);

}