#include<iostream>
#include<cmath>
using namespace std;
struct Node
{
	int rank = -1;
	bool flag = false;
}arr[10000];
bool isPrime(int N)
{
	for (int i = 2;i <= sqrt(N);i++) {
		if (N % i == 0)
			return false;
	}
	return true;
}
void Print(int ID,int rank)
{
	if (rank == 1)
		printf("%04d: Mystery Award\n", ID);
	else if (isPrime(rank))
		printf("%04d: Minion\n", ID);
	else printf("%04d: Chocolate\n", ID);
}
int main()
{
	int N, K, ID;
	int rank = 1;//记录排名的顺序
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &ID);
		arr[ID].rank = rank++;
	}
	scanf("%d", &K);
	for (int i = 0;i < K;i++) {
		scanf("%d", &ID);
		if (arr[ID].rank >= 1) {
			if (!arr[ID].flag) {//第一次出现,
				Print(ID, arr[ID].rank);
				arr[ID].flag = true;
			}
			else
				printf("%04d: Checked\n", ID);
		}
		else
			printf("%04d: Are you kidding?\n", ID);
	}
	return 0;
}