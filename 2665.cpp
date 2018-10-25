#include<stdio.h>
#include <queue>

int N;

char map[50][50];

using namespace std;

typedef struct _node {
	int x;
	int y;
	int sw;
}Node;

int v[50][50];

int main(void)
{
	int i, j;
	scanf("%d", &N);
	
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			char val;
			scanf(" %c ", &val);
			map[i][j] = val - '0';
			v[i][j] =2500;
		}
	}

	queue<Node> q;

	Node s;
	s.x = 0;
	s.y = 0;
	s.sw = 0;
	
	q.push(s);

	int answ = 2500;
	
	while (!q.empty()) {
		Node n;

		n = q.front();
		q.pop();

		if (n.x == N - 1 && n.y == N - 1) {
			if( answ > n.sw)
				answ = n.sw;	
			//break;
		}		
		if (v[n.x][n.y] < n.sw)
			continue;

		if (n.x < N - 1 && v[n.x + 1][n.y] > n.sw) {
			if (map[n.x + 1][n.y] == 1) {
				Node next;
				next.x = n.x + 1;
				next.y = n.y;
				next.sw = n.sw;
				v[n.x + 1][n.y] = next.sw;
				q.push(next);
				
			}
		}

		if (n.y < N - 1 && v[n.x][n.y + 1] > n.sw) {
			if (map[n.x][n.y + 1] == 1) {
				Node next;
				next.x = n.x;
				next.y = n.y + 1;				
				next.sw = n.sw;
				v[n.x][n.y+1] = next.sw;
				q.push(next);
			}
		}

		if (n.x > 0 && v[n.x-1][n.y] > n.sw) {
			if (map[n.x - 1][n.y] == 1) {
				Node next;
				next.x = n.x - 1;
				next.y = n.y;				
				next.sw = n.sw;
				v[n.x-1][n.y] = next.sw;
				q.push(next);
			}
		}
		
		if (n.y > 0 && v[n.x][n.y-1] > n.sw) {
			if (map[n.x][n.y-1] == 1) {
				Node next;
				next.x = n.x;
				next.y = n.y-1;
				next.sw = n.sw;				
				v[n.x][n.y-1] = next.sw;
				q.push(next);
			}
		}

//////////////////////////////////////////////////////////////////////////////////////

		if (n.x < N - 1 && v[n.x + 1][n.y] > n.sw) {
			if (map[n.x+1][n.y] == 0) {
				Node next;
				next.x = n.x + 1;
				next.y = n.y;
				next.sw = n.sw + 1;
				v[n.x + 1][n.y] = next.sw;
				q.push(next);
			}
		}

		if (n.y < N - 1 && v[n.x][n.y + 1] > n.sw) {
			if (map[n.x][n.y+1] == 0) {
				Node next;
				next.x = n.x;
				next.y = n.y + 1;
				next.sw = n.sw + 1;
				v[n.x][n.y + 1] = next.sw;
				q.push(next);
			}
		}

		if (n.x > 0 && v[n.x - 1][n.y] > n.sw) {
			if (map[n.x-1][n.y] == 0) {
				Node next;
				next.x = n.x - 1;
				next.y = n.y;
				next.sw = n.sw + 1;
				v[n.x - 1][n.y] = next.sw;
				q.push(next);
			}
		}

		if (n.y > 0 && v[n.x][n.y - 1] > n.sw) {
			if (map[n.x][n.y-1] == 0) {
				Node next;
				next.x = n.x;
				next.y = n.y - 1;
				next.sw = n.sw + 1;
				v[n.x][n.y - 1] = next.sw;
				q.push(next);
			}
		}
		
	}
	printf("%d\n", answ);	
}