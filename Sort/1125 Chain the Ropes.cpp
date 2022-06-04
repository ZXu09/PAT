#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector<int>v(N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(),v.end());
	int result = v[0];
	for (int i = 1; i < N; i++)
		result = (result + v[i]) / 2;
	printf("%d", result);
	return 0;

}