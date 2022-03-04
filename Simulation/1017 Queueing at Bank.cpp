#include<iostream>
#include<queue>
#include<algorithm>
#define maxn 10001//最大排队人数
#define begin 28800//08：00以s记
#define end 61200//17：00以s记
using namespace std;

struct person
{
	int come;//来的时间
	int time;//等待的时间
}p[maxn];

int cmp(person p1, person p2)//按照来的时间升序排序
{
	return p1.come < p2.come;
}
int main()
{
	int N, K;
	cin >> N >> K;
	int hh, mm, ss, tt;
	int sum = 0;
	int cnt = 0;//真实参与的人数
	for (int i = 0;i < N;i++) {
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		cin >> tt;
		sum = 3600 * hh + 60 * mm + ss;
		if (sum > end)
			continue;
		p[cnt].come = sum;
		p[cnt].time = tt * 60;
		cnt++;
	}
	sort(p, p + cnt, cmp);//按照到达银行的时间进行排序
	priority_queue<int, vector<int>, greater<int>>q;//按照升序排序的优先队列
	for (int i = 0;i < K;i++) {
		q.push(begin);//将每个窗口的起始值入队
	}
	int total = 0;//总等待秒数
	for (int i = 0;i < cnt;i++) {
		if (p[i].come < q.top()) {//来的比队首结束服务的时间要早-等待
			total += (q.top() - p[i].come);//等待的时间
			q.push(q.top() + p[i].time);//将该人完成服务的时间入队
			q.pop();//队首出队
		}
		else {//来的比队首结束服务的时间要晚-不用等待
			q.push(p[i].come + p[i].time);//直接办理业务，入队
			q.pop();//队首出队
		}
	}
	if (cnt == 0)
		printf("0.0\n");
	else
		printf("%.1f\n", (total / 60.0) / cnt * 1.0);//计算结果
	return 0;
}
