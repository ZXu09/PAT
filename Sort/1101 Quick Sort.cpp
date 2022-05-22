#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int Num[100010];
	int tmp[100010];
	vector<int>v;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &Num[i]);
		tmp[i] = Num[i];
	}
	sort(Num, Num + N);
	int cnt = 0, max = 0;//max存储i前面最大的元素
	for (int i = 0;i < N;i++) {
		if (Num[i] == tmp[i] && tmp[i] > max) {
			v.push_back(tmp[i]);
			cnt++;
		}
		if (tmp[i] > max)
			max = tmp[i];
	}
	printf("%d\n", cnt);
	for (int i = 0;i < v.size();i++) {
		if (!i)
			printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
	printf("\n");//0个主元的情况
	return 0;
}