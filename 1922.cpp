#include<stdio.h>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int N;
int M;

class edge {
	public :
		edge(pair<int, int> p, int dist) {
			stod = p;
			distance = dist;
		}

		bool operator < (edge &e) {
			return this->distance < e.distance;
		}

	pair<int, int> stod;
	int distance;

};

int get_parent(int vset[], int a)
{
	if (vset[a] == a)
		return a;
	
	return vset[a] = get_parent(vset, vset[a]);
}

void merge(int vset[], pair<int, int> p) {
	int a = get_parent(vset, p.first);
	int b = get_parent(vset, p.second);

	if (a < b) {
		vset[b] = a;
	}
	else
		vset[a] = b;
}

bool find(int vset[], pair<int, int> p)
{
	int a = get_parent(vset, p.first);
	int b = get_parent(vset, p.second);


	if (a == b)
		return true;
	else
		return false;
}

int vset[1001];

int main(void)
{
	//freopen("in.txt", "r", stdin);

	scanf("%d", &N);
	scanf("%d", &M);

	

	vector<edge> v;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		v.push_back(edge(make_pair(a, b), c));
	}


	
	for (int i = 0; i < N; i++)
	{
		vset[i] = i;
	}

	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(vset, v[i].stod)) {
			sum += v[i].distance;
			merge(vset, v[i].stod);
		}
	}
	printf("%d\n", sum);
}