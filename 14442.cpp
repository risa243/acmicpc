#include<stdio.h>
#include <queue>

int N, M, K;

char map[1000][1000];

using namespace std;

typedef struct _node {
	short x;
	short y;
	short k;
	int move;
}Node;


char v[1000][1000];

int main(void)
{
	int i, j;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			char val;
			scanf(" %c ", &val);
			map[i][j] = val - '0';
			v[i][j] = -1;
		}
	}

	queue<Node> q;

	Node s;
	s.x = 0;
	s.y = 0;
	s.k = K;
	s.move = 1;

	q.push(s);

	v[0][0] = s.k;
	int answ = -1;

	while (!q.empty()) {
		Node n;

		n = q.front();
		q.pop();

		if (n.x == N - 1 && n.y == M - 1) {
			answ = n.move;
			break;
		}

		if (n.x < N - 1 && v[n.x + 1][n.y] < n.k) {
			if (map[n.x + 1][n.y] == 0) {
				Node next;
				next.x = n.x + 1;
				next.y = n.y;
				next.k = n.k;
				next.move = n.move + 1;
				v[n.x + 1][n.y] = next.k;
				q.push(next);

			}
			else {
				if (n.k > 0) {
					Node next;
					next.x = n.x + 1;
					next.y = n.y;
					next.k = n.k - 1;
					next.move = n.move + 1;
					v[n.x + 1][n.y] = next.k;
					q.push(next);
				}
			}
		}

		if (n.y < M - 1 && v[n.x][n.y + 1] < n.k) {
			if (map[n.x][n.y + 1] == 0) {
				Node next;
				next.x = n.x;
				next.y = n.y + 1;
				next.k = n.k;
				next.move = n.move + 1;
				v[n.x][n.y + 1] = next.k;
				q.push(next);
			}
			else {
				if (n.k > 0) {
					Node next;
					next.x = n.x;
					next.y = n.y + 1;
					next.k = n.k - 1;
					next.move = n.move + 1;
					v[n.x][n.y + 1] = next.k;
					q.push(next);
				}
			}
		}

		if (n.x > 0 && v[n.x - 1][n.y] < n.k) {
			if (map[n.x - 1][n.y] == 0) {
				Node next;
				next.x = n.x - 1;
				next.y = n.y;
				next.k = n.k;
				next.move = n.move + 1;
				v[n.x - 1][n.y] = next.k;
				q.push(next);
			}
			else {
				if (n.k > 0) {
					Node next;
					next.x = n.x - 1;
					next.y = n.y;
					next.k = n.k - 1;
					next.move = n.move + 1;
					v[n.x - 1][n.y] = next.k;
					q.push(next);
				}
			}
		}

		if (n.y > 0 && v[n.x][n.y - 1] < n.k) {
			if (map[n.x][n.y - 1] == 0) {
				Node next;
				next.x = n.x;
				next.y = n.y - 1;
				next.k = n.k;
				next.move = n.move + 1;
				v[n.x][n.y - 1] = next.k;
				q.push(next);
			}
			else {
				if (n.k > 0) {
					Node next;
					next.x = n.x;
					next.y = n.y - 1;
					next.k = n.k - 1;
					next.move = n.move + 1;
					v[n.x][n.y - 1] = next.k;
					q.push(next);
				}
			}
		}



	}
	printf("%d\n", answ);


}