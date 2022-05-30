#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
struct Node
{
	string s;
	int data;
}arr[10010];
bool cmp(Node a, Node b)
{
	if (a.data != b.data) {
		return a.data > b.data;
	}
	else return a.s.compare(b.s) < 0;//按照名字升序排列
}
string G[11][10100];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int row = K;
	int col = N / row;
	for (int i = 0;i < N;i++) {
		cin >> arr[i].s >> arr[i].data;
	}
	sort(arr, arr + N, cmp);
	int cnt = 0;//对arr数组计数
	//对第一行单独输入
	int left = 0, right = N - (col * (row - 1)) - 1;
	int mid = (right + 1) / 2, r = mid + 1, l = mid - 1;
	bool flag = false;//控制左右
	G[0][mid] = arr[cnt++].s;
	while (l >= left || r <= right) {
		if (!flag) {
			if (l >= left)
				G[0][l--] = arr[cnt++].s;
			flag = true;
		}
		else {
			if (r <= right)
				G[0][r++] = arr[cnt++].s;
			flag = false;
		}
	}

	for (int i = 1;i < row;i++) {//行数
		int left = 0, right = col - 1;
		bool flag = false;//控制左右
		int mid = (right + 1) / 2, r = mid + 1, l = mid - 1;
		G[i][mid] = arr[cnt++].s;
		while (l >= left || r <= right) {
			if (!flag) {
				if (l >= left)
					G[i][l--] = arr[cnt++].s;
				flag = true;
			}
			else {
				if (r <= right)
					G[i][r++] = arr[cnt++].s;
				flag = false;
			}
		}
	}
	//输出
	for (int i = 0;i <= right;i++) {
		if (!i)
			cout << G[0][i];
		else cout << " " << G[0][i];
	}
	printf("\n");
	for (int i = 1;i < row;i++) {
		for (int j = 0;j < col;j++) {
			if (!j)
				cout << G[i][j];
			else cout << " " << G[i][j];
		}
		printf("\n");
	}
	return 0;
}