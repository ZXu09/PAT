#include<iostream>
using namespace std;
int bagV = 8;//背包最大体积
int w[5] = { 0,2,3,4,5 };//体积
int v[5] = { 0,3,4,5,6 };//价值
int dp[5][9];//动态规划表
int item[5];//最优解路径

void FindMax()//找到最大值
{
	for (int i = 1;i < 5;i++) {
		for (int j = 1;j < 9;j++) {
			if (j < w[i]) {//容量不够
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
}
void FindPave(int i, int j)
{
	if (i >= 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			item[i] = 0;//该物品没有用到
			FindPave(i - 1, j);
		}
		else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
			item[i] = 1;//该物品用到了
			FindPave(i - 1, j - w[i]);
		}
	}
}
void print() {
	for (int i = 0; i < 5; i++) {			//动态规划表输出
		for (int j = 0; j < 9; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)			//最优解输出
		cout << item[i] << " ";
	cout << endl;
}
int main()
{
	FindMax();
	FindPave(4, 8);
	print();
	return 0;
}