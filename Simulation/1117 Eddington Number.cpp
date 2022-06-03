#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N;
	int arr[100010];
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N, cmp);
	int i = 0;
	for (i = 0;i < N;i++) {//Âú×ãarr[i]>i + 1
		if (arr[i] <= i + 1)
			break;
	}
	printf("%d", i);
	return 0;
}