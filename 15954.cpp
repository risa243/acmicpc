#include<stdio.h>

//1 2 3 4 5 6
//1 3 6 10 15 21


//1 2 4 8 16
//1 3 7 15 31
int get_a(int a)
{
	if (a == 0)
	{
		return 0;
	}

	if (a == 1) {
		return 500;
	}
	else if (a <= 3) {
		return 300;
	}
	else if (a <= 6) {
		return 200;
	}
	else if (a <= 10) {
		return 50;
	}
	else if (a <= 15) {
		return 30;
	}
	else if (a <= 21 ){
		return 10;
	}else 
		return 0;
}

int get_b(int b)
{
	if (b == 0) {#include<stdio.h>
#include<math.h>

int a[501];
long double v[501];

int main(void)
{
	int N, K;
	int i;
	long double m = 0;
	long double min = 10000000000.0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
	{
		int val;
		scanf("%d", &val);
		a[i] = val;
	}
	for (i = 0; i < N; i++)
	{
		v[i] = min;
	}

	for (i = 0; i <= N - K; i++)
	{
		

		int e;
		for(e = i + K-1 ; e < N ; e++)
		{
			long double var = 0.0;
			int t = 0;
			int num = e - i+1;
			
			for (int j = i; j <= e; j++)
			{
				t = t + a[j];
			}			

			m = (long double)t / (long double)num;

			for (int j = i; j <= e; j++)
			{
				var += ((long double)a[j] - m) * ((long double)a[j] - m);
			}
			var = var / (long double)num;

			var = sqrt(var);
			if (v[i] > var)
			{
				v[i] = var;
			}			
		}
	}

	for (i = 0; i <= N-K; i++)
	{		
		if (min > v[i])
		{
			min = v[i];
		}
	}
	printf("%.11Lf\n", (min));
}
		return 0;
	}

	if (b == 1) {
		return 512;
	}
	else if (b <= 3) {
		return 256;
	}
	else if (b <= 7) {
		return 128;
	}
	else if (b <= 15) {
		return 64;
	}
	else if (b <= 31) {
		return 32;
	}
	else
		return 0;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int a, b;
		int ans = 0;
		scanf("%d %d", &a, &b);

		ans = (get_a(a) + get_b(b)) * 10000;

		printf("%d\n", ans);
	}
	return 0;
}