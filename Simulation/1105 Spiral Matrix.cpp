#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int Matrix[10010][10010];
int main()
{
	int N, m, n;
	scanf("%d", &N);
	int Num[10010];
	for (int i = 0;i < N;i++)
		scanf("%d", &Num[i]);
	sort(Num, Num + N, cmp);
	//确定m和n
	for (int i = sqrt(N);i <= N;i++) {
		int b = N / i;
		if (N % i == 0 && i >= b) {
			m = i, n = b;//满足m*n=N,m>=n的最小差值
			break;
		}
	}
	int i = 0, j = 0, cnt = 0;
	int rbi = n, lbi = 0, lbj = 1, rbj = m;//分别是列和行的左右标记
	bool iflag = false, jflag = false;//判断顺序
	while (lbi <= rbi - 1 || lbj <= rbj - 1) {//满足左边的标记小于右边
		if (cnt == N)
			break;
		if (lbi <= rbi - 1) {//判断方向
			if (!iflag) {//左->右插入矩阵
				for (i = lbi;i < rbi;i++)//
					Matrix[j][i] = Num[cnt++];
				iflag = true;
				rbi--;//下一轮的右侧减1
				i--;//保证i为当前元素列,要回退一个
			}
			else {//右->左插入矩阵
				for (i = rbi - 1;i >= lbi;i--)//起始的原因要rbi-1
					Matrix[j][i] = Num[cnt++];
				iflag = false;;
				lbi++;//下一轮的左侧加1
				i++;
			}
		}
		if (lbj <= rbj - 1) {
			if (!jflag) {//判断方向
				for (j = lbj;j < rbj;j++)
					Matrix[j][i] = Num[cnt++];
				jflag = true;
				rbj--;
				j--;
			}
			else {
				for (j = rbj - 1;j >= lbj;j--)
					Matrix[j][i] = Num[cnt++];
				jflag = false;
				lbj++;
				j++;
			}
		}
	}
	//输出
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (!j)
				printf("%d", Matrix[i][j]);
			else printf(" %d", Matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}