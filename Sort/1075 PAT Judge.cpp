#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	int rank;
	int P[6];
	bool submitted = false;
	int perfect = 0;
	int total = 0;
	int ID;
}Array[10010];
bool cmp(Node a, Node b)
{
	if (a.total == b.total) {
		if (a.perfect == b.perfect) {
			return a.ID < b.ID;
		}
		else return a.perfect > b.perfect;
	}
	else return a.total > b.total;
}
int main()
{
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	int P[6];
	for (int i = 1;i <= K;i++)
		scanf("%d", &P[i]);
	for (int i = 1;i <= N;i++) {
		Array[i].ID = i;//初始化ID
		for (int j = 1;j <= K;j++)
			Array[i].P[j] = -2;//初始化
	}
	for (int i = 0;i < M;i++) {
		int ID, List, Score;
		scanf("%d %d %d", &ID, &List, &Score);
		if (Score != -1)
			Array[ID].submitted = true;//提交过
		if (Score > Array[ID].P[List])
			Array[ID].P[List] = Score;
	}
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= K;j++) {
			if (Array[i].P[j] >= 0) {
				Array[i].total += Array[i].P[j];
			}
			if (Array[i].P[j] == P[j]) {
				Array[i].perfect++;
			}
		}
	}
	sort(Array + 1, Array + N + 1, cmp);
	int rank = 1;
	int count = 1;

	//输出
	Array[1].rank = 1;
	printf("%d %05d %d", Array[1].rank, Array[1].ID, Array[1].total);
	for (int j = 1;j <= K;j++) {
		if (Array[1].P[j] == -2)
			printf(" -");
		else if (Array[1].P[j] <= 0)
			printf(" 0");
		else printf(" %d", Array[1].P[j]);
	}
	printf("\n");
	for (int i = 2;i <= N;i++) {
		if (!Array[i].submitted)//没有提交过
			continue;
		if (Array[i].total == Array[i - 1].total)
			Array[i].rank = Array[i - 1].rank;
		else
			Array[i].rank = i;
		printf("%d %05d %d", Array[i].rank,Array[i].ID,Array[i].total);
		for (int j = 1;j <= K;j++) {
			if (Array[i].P[j] == -2)
				printf(" -");
			else if (Array[i].P[j] <= 0)
				printf(" 0");
			else printf(" %d", Array[i].P[j]);
		}
		printf("\n");
	}
	return 0;
}