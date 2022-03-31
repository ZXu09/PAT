#include<iostream>
#include<algorithm>
using namespace std;
struct Moon
{
	int amount;
	float price;
	float profit;
}arr[1010];
bool cmp(Moon a, Moon b)
{
	return a.profit > b.profit;//∞¥’’¿˚»ÛΩµ–Ú≈≈–Ú
}
int main()
{
	int N, D;
	scanf("%d %d", &N, &D);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i].amount);
	}
	for (int i = 0;i < N;i++) {
		scanf("%f", &arr[i].price);
		arr[i].profit = arr[i].price / arr[i].amount;
	}
	sort(arr, arr + N, cmp);
	float sum = 0;
	for (int i = 0;i < N;i++) {
		if (arr[i].amount >= D) {
			sum += (float)D / arr[i].amount * arr[i].price;
			break;
		}
		else {
			sum += arr[i].price;
			D -= arr[i].amount;
		}
	}
	printf("%.2f\n", sum);
	return 0;
}