#include<iostream>
#include<algorithm>
#include <queue>
#define INF 0x3f3f3f
using namespace std;
int time(int h, int m)//转换成为分钟
{
	return 60 * h + m;
}
struct Window//每个窗口的时间
{
	//队伍的最后的人服务完成花费的总时间,用于计算服务耗费时间
	int endtime = time(8, 0);
	//队首的人服务的结束时间,队首服务时间最短的即为入队选择的窗口
	int poptime = endtime;
	queue<int>q;
}window[20];
int main()
{
	int N, M, K, Q;
	//以mintues为单位存储
	int spenttime[1001] = {0};//服务耗费时间
	int finishtime[1001] = {0};//服务结束时间
	cin >> N >> M >> K >> Q;
	int i;
	for (i = 0;i < K;i++) {
		cin >> spenttime[i];
	}
	//队伍满之前入队
	int idx = 0;//序号，第几个人
	for (i = 0;i < min(N * M, K);i++) {
		window[idx % N].q.push(idx);//第idx % N个窗口入队idx这个人
		window[idx % N].endtime += spenttime[idx];
		if (idx < N)//此时窗口还没满
			window[idx].poptime = spenttime[idx];
		finishtime[idx] = window[idx % N].endtime;
		idx++;
	}
	while (idx < K) {
		//寻找poptime最小的队伍
		int inx = -1, minpoptime = INF;
		for (i = 0;i < N;i++) {
			if (window[i].poptime < minpoptime) {
				inx = i;
				minpoptime = window[i].poptime;
			}
		}
		window[inx].q.pop();//队首元素出队
		window[inx].q.push(idx);//入队

		window[inx].endtime += spenttime[idx];
		window[inx].poptime += spenttime[window[inx].q.front()];
		//队首的人服务花费的时间,作为之后的人的比较因此还要把之前的也加上
		finishtime[idx] = window[inx].endtime;
		idx++;
	}
	//输出
	int queries;
	for (i = 0;i < Q;i++) {
		cin >> queries;
		if (finishtime[queries - 1] - spenttime[queries - 1] >= time(17, 0))
			cout << "Sorry" << endl;//服务时间要早于17:00
		else
			printf("%02d:%02d\n", finishtime[queries - 1] / 60, finishtime[queries - 1] % 60);
	}

	return 0;
}