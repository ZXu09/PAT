#include<iostream>
#include<string>
using namespace std;
int min(int a, int b, int c, int d)
{
	if (a <= b)
		return a <= c ? (a <= d ? a : d) : (c <= d ? c : d);
	else if (a > b)
		return b <= c ? (b <= d ? b : d) : (c <= d ? c : d);
}
struct student
{
	string ID;
	int rank_C;
	int rank_M;
	int rank_E;
	int rank_A;
};
int main()
{
	int a, b, i, j;
	cin >> a >> b;
	int C[2001];
	int M[2001];
	int E[2001];
	int A[2001];
	student name[2001];
	for (i = 0;i < a;i++) {
		cin >> name[i].ID >> C[i] >> M[i] >> E[i];
		A[i] = (int)((C[i] + M[i] + E[i]) / 3.0 + 0.5);//四舍五入
	}
	for (i = 0;i < a;i++) {
		name[i].rank_A = name[i].rank_C = name[i].rank_E = name[i].rank_M = 1;
		for (j = 0;j < a;j++) {
			if (A[j] > A[i])
				name[i].rank_A++;
			if (C[j] > C[i])
				name[i].rank_C++;
			if (E[j] > E[i])
				name[i].rank_E++;
			if (M[j] > M[i])
				name[i].rank_M++;
		}
	}
	//输出
	string ID;
	int flag = 0;//判断是否是N/A
	for (i = 0;i < b;i++) {
		cin >> ID;
		flag = 0;
		for (j = 0;j < a;j++) {
			if (ID.compare(name[j].ID) == 0) {
				flag = 1;
				int rank = min(name[j].rank_A, name[j].rank_C, name[j].rank_M, name[j].rank_E);
				if (rank == name[j].rank_A)
					cout << rank << " " << "A" << endl;
				else if(rank== name[j].rank_C)
					cout << rank << " " << "C" << endl;
				else if(rank == name[j].rank_M)
					cout << rank << " " << "M" << endl;
				else if (rank == name[j].rank_E)
					cout << rank << " " << "E" << endl;
			}
		}
		if (flag == 0)
			cout << "N/A" << endl;
	}
	return 0;
}