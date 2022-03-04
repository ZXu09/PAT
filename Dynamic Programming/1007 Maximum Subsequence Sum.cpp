#include<iostream>
using namespace std;

void MaxSubsequm1(int A[], int N)//暴力破解-O(N^3)-过不去最后一个
{
	int i, j, k;
	int MaxSum = -1,ThisSum;
	int First = A[0], Last = A[0];//输出索引最小的那个
	for (i = 0;i < N;i++) {
		for (j = i;j < N;j++) {
			ThisSum = 0;
			for (k = i;k <= j;k++) {
				ThisSum += A[k];
				if (ThisSum > MaxSum) {
					MaxSum = ThisSum;
					First = A[i];
					Last = A[k];
				}
			}			
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}

void MaxSubsequm2(int A[], int N)//稍作改进-O(N^2)-可以全过
{
	int i, j;
	int MaxSum = -1, ThisSum;
	int First, Last;
	for (i = 0;i < N;i++) {
		ThisSum = 0;
		for (j = i;j < N;j++) {
			ThisSum += A[j];
			if (ThisSum > MaxSum) {
				MaxSum = ThisSum;
				First = A[i];
				Last = A[j];
			}
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}

void MaxSubsequm3(int A[], int N)//动态规划-可以全过
{
	int i, MaxSum = -1, ThisSum = 0;
	int First, Last, Start = A[0];
	for (i = 0;i < N;i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			Last = A[i];
			First = Start;//存进First
		}
		if (ThisSum < 0) {//重新开始
			ThisSum = 0;
			Start = A[i + 1];//记录开始的地方
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}

int Max(int A, int B, int C)
{
	return A > B ? (A > C ? A : C) : (B > C ? B : C);
}

int DivideAndConquer(int A[], int left, int right)//O(NlogN)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, LeftBorderSum;
	int MaxRightBorderSum, RightBorderSum;
	int First, Last;
	if (left == right) {//中止递归的条件
		if (A[left] > 0)
			return A[left];
		else return 0;
	}
	//求左右子列的最大
	int center = (left + right) / 2;
	MaxLeftSum = DivideAndConquer(A, left, center);
	MaxRightSum = DivideAndConquer(A, center + 1, right);
	//求跨越左边界的最大
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (int i = center;i >= left;i--) {
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	//求跨越右边界的最大
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (int i = center + 1; i <= right; i++) {
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequm4(int A[], int N)//分而治之
{
	return DivideAndConquer(A, 0, N - 1);
}
int main()
{
	int N;
	int A[10001];
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> A[i];
	//MaxSubsequm1(A, N);
	//MaxSubsequm2(A, N);
	MaxSubsequm3(A, N);
	//cout << MaxSubsequm4(A,N) << endl;
	return 0;
}