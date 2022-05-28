#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int>v, ans, tmpans;
int N, K, P;
void init()//初始化v数组为所有比N小的所有i^P
{
	int tmp = 0, i = 1;
	while (tmp <= N) {
		v.push_back(tmp);
		tmp = pow(i, P);
		i++;
	}
}

int maxfacsum = -1;//分解因式之和
void DFS(int i, int sum, int facsum)//从v[i]的最后开始进行DFS
{
	if (tmpans.size() == K) {//计数为K个时
		if (sum == N && facsum > maxfacsum) {
			maxfacsum = facsum;
			ans = tmpans;//存储答案
		}
		return;
	}
	while (i>=1) {//i存储在数组v的下标,也就是该数组
		if (sum + v[i] <= N) {
			tmpans.push_back(i);
			DFS(i, sum + v[i], facsum + i);
			tmpans.pop_back();
		}
		if (i == 1)//现在是1就返回，不用去找0了
			return;
		i--;//只有相加直到sum+v[i]>N时才会让i--
	}
}
int main()
{
	scanf("%d %d %d", &N, &K, &P);
	init();
	DFS(v.size() - 1, 0, 0);
	if (maxfacsum == -1) {//说明没有答案
		printf("Impossible");
		return 0;
	}
	printf("%d = ", N);
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" + ");
		printf("%d^%d", ans[i], P);
	}
	return 0;

}