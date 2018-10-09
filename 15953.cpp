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
	if (b == 0) {
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