#include<iostream>
#include<set>
using namespace std;

int root[10010];//实现并查集
bool node[10010];//判断鸟的数量
int find(int x)
{
	while (x != root[x]) {
		x = root[x];
	}
	return x;
}

void Union(int a, int b)
{
	int ra = find(a);
	int rb = find(b);
	if (ra < rb) {
		root[rb] = ra;
	}
	else if (ra > rb)
		root[ra] = rb;
}
int main()
{
	
	for (int i = 0;i < 10010;i++)
		root[i] = i;
	int N, Q, K;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &K);
		int tmpB, lastB;
		for (int j = 0;j < K;j++) {
			if (j == 0) {
				scanf("%d", &lastB);
				node[lastB] = true;
			}
			else {
				scanf("%d", &tmpB);
				node[tmpB] = true;
				Union(tmpB, lastB);
				lastB = tmpB;
			}
		}
	}
	set<int>s;
	int cntb = 0;//鸟的数量
	for (int i = 0;i < 10010;i++) {
		if (node[i]) {//出现的鸟
			cntb++;
			int tree = find(i);
			s.insert(tree);
		}
	}
	printf("%d %d\n", s.size(), cntb);

	scanf("%d", &Q);
	int Q1, Q2;
	for (int i = 0;i < Q;i++) {
		scanf("%d %d", &Q1, &Q2);
		if (find(Q1) == find(Q2))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}