### 1021 Deepest Root 25 -DPS(int S, int deep)
-对每个结点进行DFS遍历，找到最大深度，比较简单
```C++
void DFS(int S, int deep)//dfs找到最大深度
{
	visited[S] = true;
	//访问S的每个邻接点
	for (int i = 0;i < G[S].size();i++) {
		if (!visited[G[S][i]]) {
			visited[G[S][i]] = true;
			if (deep > maxd) {
				maxd = deep;
			}
			DFS(G[S][i], deep + 1);
		}
	}
}
```

### 1003 Emergency 25 -Dijkstra(int S)
- 图存储路径长度，点上有救援队人数Weight[]，寻找最短路径的个数Num[]，最短路径相等则比较路径的权重最大值Gather[]
```C++
int G[501][501];
fill(G[0], G[0] + 501 * 501, INF);

int Weight[501];//路径权重
bool Visited[501] = { false };//是否访问过
int Dist[501];//最短路径长度
int Num[501] = { 0 };//最短路径的条数
int Gather[501] = { 0 };//最大支援队集结数

void Dijkstra(int S)
{
	fill(Dist, Dist + 501, INF);
	Dist[S] = 0;//起始点
	Gather[S] = Weight[C1];//在起始点的救援队个数
	Num[S] = 1;//最短路径的条数1条

	while (1)
	{
		int u = -1, mindist = INF;
		for (int i = 0;i < N;i++) {
			if (!Visited[i] && Dist[i] < mindist) {
				mindist = Dist[i];
				u = i;//未收录顶点中Dist最小者
			}
		}
		if (u == -1)//这样的顶点不存在
			break;
		Visited[i] = true;//u即将被访问
		for (int i = 0;i < N;i++) {
			if (!Collected[i] && G[u][i] != INF) {//未访问过的邻结点i
				if (Dist[i] > Dist[u] + G[u][i]) {
					Dist[i] = Dist[u] + G[u][i];//更新最短路径长度
					Num[i] = Num[u];//更新最短路径的条数(与上一个顶点u一样)
					Gather[i] = Gather[u] + Weight[i];//这条路径上的救援队数
				}
				else if (Dist[i] == Dist[u] + G[u][i]) {
					Num[i] += Num[u];//两种路都可以
					if (Gather[i] < Gather[u] + Weight[i])//此时就要找救援队数量大的
						Gather[i] = Gather[u] + Weight[i];
				}
			}
		}
	}
}
```
### 1018 Public Bike Management 30 -DFS()+Dijkstra()
- 图存储路径长度，点上有单车数Weight[]，寻找最短路径，最短路径相等则比较路径send和back的单车数，并输出路径
- 寻找最短路径-Dijkstra()，利用prenode记录最短路径的上一个结点，方便对最短路径进行遍历
```C++
void Dijkstra(int S)//单源最短路径
{
	fill(Dist, Dist + 501, INF);
	Dist[S] = 0;
	while (1) {
		int u = -1;//未收录顶点中权值最小
		int mint = INF;
		for (int i = 0;i < N;i++) {
			if (!Visited[i] && Dist[i] < mint) {
				mint = Dist[i];
				u = i;
			}
		}
		if (u == -1)//没有找到
			return;
		Visited[u] = true;//已经被访问过
		for (int i = 0; i <= N; i++) {
			if (!Visited[i] && G[u][i] != INF) {
				if (Dist[u] + G[u][i] < Dist[i]) {
					Dist[i] = Dist[u] + G[u][i];
					prenode[i].clear();
					prenode[i].push_back(u);
				}
				else if (Dist[u] + G[u][i] == Dist[i]) {
					prenode[i].push_back(u);
				}
			}
		}
	}
}
```
- 对每一条最短路径进行比较，取发送单车数量最少的，若相等则取接受单车数量最少的
```C++
void DFS(int vi)//传入有问题的地点
{
	if (vi == 0) {//此时已经是到了原点了
		tmppath.push_back(0);
		int minsendtmp = 0, minbacktmp = 0;
		for (int i = tmppath.size() - 2; i >= 0; i--) {//不考虑0点（出发点）
			int t = tmppath[i];//起始点为0点（出发点）前一个
			//判断是否要返回车
			if (minbacktmp + C[t] < CMax / 2)//车不够用，要带过去车
				minsendtmp += CMax / 2 - (minbacktmp + C[t]), minbacktmp = 0;
			else {//要返回车
				if (C[t] > CMax / 2)//返回的车多了
					minbacktmp += C[t] - CMax / 2;//多的就要回去的时候带上
				else//返回的车少了
					minbacktmp -= CMax / 2 - C[t];//直接减去
			}
		}
		if (minsendtmp < minsend)//更新路径
			path = tmppath, minsend = minsendtmp, minback = minbacktmp;
		else if (minsendtmp == minsend && minbacktmp < minback)
			path = tmppath, minback = minbacktmp;
		tmppath.pop_back();//原点(0)弹出
		return;//此时这一条路径已经走完了
	}
	tmppath.push_back(vi);
	for (int i = 0; i < prenode[vi].size(); i++)//遍历该结点之前的结点
		DFS(prenode[vi][i]);
	tmppath.pop_back();//将vi这个结点弹出
}
```
1018 Public Bike Management 30
1030 Travel Plan 30
1087 All Roads Lead to Rome 30
都是用Dijkstra和DFS来求解，是同类型的题，区别在与DFS的过程中找最优解的条件（一个是cost最小，一个是send单车最少，一个是happiness最多）

1034 Head of a Gang 30
图+DFS，关键点在于将姓名string类型->int类型保存在图中，用map<string, int> m;//用hash将string->int类型(key,value)
1.ss用于用value找回key，也就是m存储时value就是cnt，而ss正好在ss[cnt]=S1；
2.
if (m.find(S1) != m.end()) {//找到了
	s1 = m[S1];
}
else {
	m[S1] = cnt;//计数编号
	s1 = m[S1];
	ss.push_back(S1);
	cnt++;
}

1072 Gas Station 30
从m个加油站里面选取1个站点，让他离居民区的最近的人最远，并且没有超出服务范围ds之内
简而言之：找最大的Min，相同则最小的Ave，相同则最小的号码的加油站

1076 Forwards on Weibo 30
BFS的应用
因为是给定人要找订阅他的人，题目的输入的格式是这个人订阅的人，因此存储时要用 谁订阅了他 来存储（反过来）

1091 Acute Stroke
三维BFS！！一共有6个方向进行移动，遍历i = 1 ~ 6，分别加上对应X、Y、Z数组的值
int X[6] = { 1, 0, 0, -1, 0, 0 };
int Y[6] = { 0, 1, 0, 0, -1, 0 };
int Z[6] = { 0, 0, 1, 0, 0, -1 };
judge判断是否邻接点且未访问
