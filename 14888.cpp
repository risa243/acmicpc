#include<stdio.h>

int num[12];
int N;

int A;
int S;
int M;
int D;

long long min = 10000000002;
long long max = -10000000002;


void DFS(int a, int s, int m, int d, int i, int val)
{
	int n_val;

	if (i == N-1 )
	{
		if (val > max)
		{
			max = val;
		}

		if (val < min)
		{
			min = val;
		}
		return;
	}

	

	if (a > 0) {
		n_val = val + num[i + 1];
		DFS(a - 1, s, m, d, i + 1, n_val);
	}

	if (s > 0) {
		n_val = val - num[i + 1];
		DFS(a , s - 1, m, d, i + 1, n_val);
	}

	if (m > 0) {		
		n_val = val * num[i + 1];
		DFS(a , s, m -1 , d, i + 1, n_val);
	}

	if (d > 0) {
		n_val = val / num[i + 1];
		DFS(a , s, m , d-1, i + 1, n_val);
	}
}

int main(void)
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		int v;
		scanf("%d", &v);
		num[i] = v;
	}
	scanf("%d %d %d %d", &A, &S, &M, &D);

	DFS(A, S, M, D, 0, num[0]);

	printf("%lld\n%lld\n", max, min);


	return 0;
}