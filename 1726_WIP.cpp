#include<stdio.h>
#include<queue>

using namespace std;

#define RIGHT		1
#define LEFT		2
#define DOWN		3
#define UP			4

int map[101][101];
int v[101][101][5];
int N, M;

int sx, sy, sd;
int ex, ey, ed;

typedef struct _node {
	int x;
	int y;
	int d;
	int  op;
}Node;

int main(void)
{
	int N, M;
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			int val;
			scanf("%d", &val);
			map[i][j] = val;
		}
	}

	scanf("%d %d %d", &sx, &sy, &sd);
	scanf("%d %d %d", &ex, &ey, &ed);

	Node s;
	s.x = sx - 1;
	s.y = sy - 1;
	s.d = sd;
	s.op = 0;

	queue<Node> q;

	q.push(s);

	int answ = 0;

	while (!q.empty())
	{
		Node c;
		Node n;
		c = q.front();
		q.pop();
		
		if (c.x == ex - 1 && c.y == ey - 1 && c.d == ed)
		{
			answ = c.op;
			break;
		}

		if (v[c.x][c.y][c.d] == 1) {
			continue;
		}
		else {
			v[c.x][c.y][c.d] = 1;
		}

		n.x = c.x;
		n.y = c.y;
		n.d = c.d;

		switch (c.d) {
		case UP:
		case DOWN:
		{
			n.d = RIGHT;
			n.op = c.op + 1;
			q.push(n);

			n.d = LEFT;
			n.op = c.op + 1;
			q.push(n);
		}
		break;
		case LEFT:
		case RIGHT:
		{
			n.d = UP;
			n.op = c.op + 1;
			q.push(n);

			n.d = DOWN;
			n.op = c.op + 1;
			q.push(n);
		}
		break;
		}

		int k;

		n.x = c.x;
		n.y = c.y;
		n.d = c.d;

		switch (c.d) {
		case UP:
		{
			for (k = c.x - 1; k >= c.x - 3; k--)
			{
				if (k < 0)
					break;
								
				if (map[k][c.y] == 0 && v[k][c.y][UP] == 0) {
										
					n.d = c.d;
					n.x = k;
					n.y = c.y;
					n.op = c.op + 1;
					q.push(n);
				}
				else {
					break;
				}
			}
		}
		break;
		case LEFT:
		{
			for (k = c.y - 1; k >= c.y-3; k--)
			{
				if (k < 0)
					break;

				if (map[c.x][k] == 0 && v[c.x][k][LEFT] == 0) {
					n.y = k;
					n.x = c.x;
					n.op = c.op + 1;
					q.push(n);
				}
				else {
					break;
				}
			}
		}
		break;
		case RIGHT:
		{
			for (k = c.y + 1; k <= c.y + 3; k++)
			{
				if (k >= M)
					break;

				if (map[c.x][k] == 0 && v[c.x][k][RIGHT] == 0) {
					n.x = c.x;
					n.y = k;
					n.op = c.op + 1;
					q.push(n);
				}
				else {
					break;
				}
			}
		}
		break;
		case DOWN:
		{
			for (k = c.x + 1; k <= c.x+3; k++)
			{
				if (k >= N)
					break;

				if (map[k][c.y] == 0 && v[k][c.y][DOWN] == 0) {
					n.y = c.y;
					n.x = k;
					n.op = c.op + 1;
					q.push(n);
				}
				else {
					break;
				}
			}
		}
		break;
		}
	}

	printf("%d\n", answ);

	return 0;
}