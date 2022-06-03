#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int ID, Father, Mother, M, area;
	vector<int>child;
}fam[1010];

struct ANode
{
	int ID, Person;
	double Sum, area;
	bool flag = false;//
}ans[10000];
int father[10000];//实现并查集
bool visited[10000] = {false};
int find(int x)//找到没有父结点的那个结点
{
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}
void Union(int a, int b)//使得ID最小的结点成为根节点
{
	int fa = find(a);
	int fb = find(b);
	if (fa > fb)
		father[fa] = fb;
	else if (fa < fb)
		father[fb] = fa;
}
bool cmp(ANode a, ANode b)
{
	if (a.area != b.area)
		return a.area > b.area;
	else
		return a.ID < b.ID;
}
int main()
{
	for (int i = 0; i < 10000; i++)
		father[i] = i;//方便find返回
	int N, ID, K, c;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d %d %d %d", &fam[i].ID, &fam[i].Father, &fam[i].Mother, &K);
		visited[fam[i].ID] = true;
		if (fam[i].Father != -1) {
			visited[fam[i].Father] = true;//出现了的结点，方便之后进行统计人数
			Union(fam[i].Father, fam[i].ID);
		}
		if (fam[i].Mother != -1) {
			visited[fam[i].Mother] = true;
			Union(fam[i].Mother, fam[i].ID);
		}
		for (int j = 0;j < K;j++) {
			scanf("%d", &c);
			fam[i].child.push_back(c);
			visited[c] = true;
			Union(c, fam[i].ID);
		}
		scanf("%d %d", &fam[i].M, &fam[i].area);
	}
	for (int i = 0;i < N;i++) {
		ID = find(fam[i].ID);
		ans[ID].flag = true;//表明这个ID是一个家庭的根节点
		ans[ID].ID = ID;
		ans[ID].area += fam[i].area;
		ans[ID].Sum += fam[i].M;
		//此时不计数person是因为有部分人没有房子不在fam[i].ID中
	}
	int cnt = 0;//计数
	for (int i = 0;i < 10000;i++) {
		if(visited[i])//这样就不会漏了没有房子的人
			ans[find(i)].Person++;
		if (ans[i].flag)//每个家庭的根节点
			cnt++;
	}
	for (int i = 0;i < 10000;i++) {//统计完该组的Person才能计算AVG
		if (ans[i].flag) {
			ans[i].Sum = ans[i].Sum / ans[i].Person;
			ans[i].area = ans[i].area / ans[i].Person;
		}
	}
	sort(ans, ans + 10000, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%04d %d %.3f %.3f\n", ans[i].ID, ans[i].Person, ans[i].Sum, ans[i].area);
	return 0;
}