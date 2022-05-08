#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int add;
	int data;
	int next;
}Array[100010];
int main()
{
	int N, Address, add;
	scanf("%d %d", &Address, &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &add);
		Array[add].add = add;
		scanf("%d %d", &Array[add].data, &Array[add].next);
	}
	vector<Node>res, rem;
	vector<int>tmp;//存储出现过的字符
	while (Address != -1) {
		if (find(tmp.begin(), tmp.end(), abs(Array[Address].data)) != tmp.end()) {
			//已经存过了
			rem.push_back(Array[Address]);
		}
		else {
			tmp.push_back(abs(Array[Address].data));//未存储就存储
			res.push_back(Array[Address]);
		}
		Address = Array[Address].next;
	}
	for (int i = 0;i < res.size() - 1;i++) {
		printf("%05d %d %05d\n", res[i].add, res[i].data, res[i + 1].add);
	}
	printf("%05d %d -1\n", res[res.size() - 1].add, res[res.size() - 1].data);
	if (rem.size()) {//防止出现为0的情况-（vector.size返回值是unsigned int）
		for (int i = 0;i < rem.size() - 1;i++) {
			printf("%05d %d %05d\n", rem[i].add, rem[i].data, rem[i + 1].add);
		}
		printf("%05d %d -1\n", rem[rem.size() - 1].add, rem[rem.size() - 1].data);
	}
	return 0;
}