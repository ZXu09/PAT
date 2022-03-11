#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
	int weight;
	int order;//按照排名后的顺序的老鼠的下标
	int rank;
	int porder;//排名前的顺序
}Array[100010];
bool cmp(Node a, Node b)
{
	return a.order < b.order;
}
int main()
{
	int Np, Nc;
	cin >> Np >> Nc;
	vector<int>v(Np);
	vector<Node>w(Np);
	int num;
	for (int i = 0;i < Np;i++) {
		cin >> v[i];
	}
	for (int i = 0;i < Np;i++) {
		cin >> num;
		w[i].order = num;//存6 0 8 7...
		w[i].porder = i;//存0 1 2 3...
		w[i].weight = v[num];
	}
	queue<Node>q;
	for (int i = 0; i < Np; i++)
		q.push(w[i]);//按照给定的顺序入队
	while (!q.empty()) {//队列不空的情况
		int size = q.size();
		if (size == 1) {//就一个元素
			Node temp = q.front();
			w[temp.porder].rank = 1;
			break;
		}
		int group = size / Nc;//代表鼠鼠被分成了几组
		if (size % Nc != 0)
			group += 1;
		Node maxnode;
		int maxn = -1, cnt = 0;
		for (int i = 0; i < size; i++) {
			Node temp = q.front();
			w[temp.porder].rank = group + 1;//一轮一轮地修改rank
			q.pop();
			cnt++;
			if (temp.weight > maxn) {//更新Nc中最大的结点
				maxn = temp.weight;
				maxnode = temp;
			}
			if (cnt == Nc || i == size - 1) {
				cnt = 0;
				maxn = -1;
				q.push(maxnode);//将最大的结点重新入队
			}
		}
	}
	sort(w.begin(), w.end(), cmp);//按照原本的顺序进行排序
	for (int i = 0; i < Np; i++) {
		if (i != 0) printf(" ");
		printf("%d", w[i].rank);
	}
	return 0;
}