#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	int add;//地址
	int data;//数据
	int next;//下一数据的地址
}Array[100010];
vector<Node>l;
bool cmp(Node a, Node b) {
	return a.data < b.data;
}
int main()
{
	int N, Address, add;
	cin >> N >> Address;
	int address = Address;
	for (int i = 0;i < N;i++) {
		cin >> add;
		Array[add].add = add;
		cin >> Array[add].data >> Array[add].next;
	}
	while (Address != -1) {//存在链表内的数
		l.push_back(Array[Address]);
		Address = Array[Address].next;
	}
	if (l.size() == 0) {//无结点的情况单独讨论
		printf("0 -1\n");
		return 0;
	}
	sort(l.begin(), l.end(), cmp);
	printf("%d %05d\n", l.size(), l[0].add);
	for (int i = 0;i < l.size()-1;i++) {
		l[i].next = l[i + 1].add;
		printf("%05d %d %05d\n", l[i].add, l[i].data, l[i].next);
	}
	l[l.size() - 1].next = -1;
	printf("%05d %d %d\n", l[l.size() - 1].add, l[l.size() - 1].data, l[l.size() - 1].next);
	return 0;
}