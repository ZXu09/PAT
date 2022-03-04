#include<iostream>
using namespace std;
#define maxn 100001
struct node
{
	char data;
	int next;
	bool flag;
}Array[maxn];

int main()
{
	int A1, A2, N;
	cin >> A1 >> A2 >> N;
	int Address, Suffix = 0;
	for (int i = 0;i < N;i++) {
		cin >> Address;
		cin >> Array[Address].data >> Array[Address].next;
	}
	for (int i = A1;i != -1;i = Array[i].next)
		Array[i].flag = true;//已经访问过
	for (int i = A2;i != -1;i = Array[i].next) {
		if (Array[i].flag) {
			printf("%05d", i);
			return 0;
		}
	}
	cout << -1;
	return 0;
}