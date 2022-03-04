#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#define maxn 2001
int weight[maxn];
int G[maxn][maxn];//邻接矩阵
bool visited[maxn];

using namespace std;

int cnt = 0;//计数
int N, K;
int Count, maxi, total, maxId;
map<string, int> m;//用hash将string->int类型
vector<string> ss, ans;//ss用来存输入，ans存答案

void DFS(int S);
void GetAns();
bool cmp(string a, string b);

int main()
{
	cin >> N >> K;
	string S1, S2;
	int s1, s2;//存储转化后的整形
	int T;
	for (int i = 0;i < N;i++) {
		cin >> S1 >> S2 >> T;
		//将输入的S1、S2转化成int类型
		if (m.find(S1) != m.end()) {//找到了
			s1 = m[S1];
		}
		else {
			m[S1] = cnt;//计数编号
			s1 = m[S1];
			ss.push_back(S1);
			cnt++;
		}
		if (m.find(S2) != m.end()) {
			s2 = m[S2];
		}
		else {
			m[S2] = cnt;
			s2 = m[S2];
			ss.push_back(S2);
			cnt++;
		}
		G[s1][s2] = T;//单向的，这样计算total不会＋两遍
		
		weight[s1] += T;//更新对应结点的权重
		weight[s2] += T;
	}
	GetAns();
	sort(ans.begin(), ans.end(), cmp);//按照字母升序排列
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}

void DFS(int S)
{
	Count++;//判断这个群中有几人
	visited[S] = 1;
	if (weight[S] > maxi) {
		maxi = weight[S];
		maxId = S;//最大权值的人的
	}
	for (int i = 0;i < cnt;i++) {
		if (G[S][i] > 0) {
			total += G[S][i];//总共的
			if (!visited[i])
				DFS(i);
		}
	}
}
void GetAns()
{
	for (int i = 0; i < cnt; i++) {
		Count = 0; maxi = 0; total = 0;//重置
		if (visited[i] == 0)
			DFS(i);
		if (Count > 2 && total > K) {//total代表这个群中权值最大的人
			string s = ss[maxId] + " " + to_string(Count);//转换为string
			ans.push_back(s);
		}
	}
}

bool cmp(string a, string b)
{
	return a < b;//升序排列
}