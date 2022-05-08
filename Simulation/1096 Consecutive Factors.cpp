#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int N, count = 0;
	vector<int>v, r;
	scanf("%d", &N);
	for (int i = 2;i <= sqrt(N) + 1;i++) {
		int tmp = N;
		v.clear();
		int j = i;
		while (tmp % j == 0) {
			v.push_back(j);
			tmp /= j;
			j++;
		}
		if (v.size() > r.size())
			r = v;
	}
	if (r.size() == 0)//ÖÊÊý
		r.push_back(N);
	printf("%d\n", r.size());
	for (int i = 0;i < r.size();i++) {
		if (!i)
			printf("%d", r[i]);
		else printf("*%d", r[i]);
	}
}