
### 1032 Sharing 25
**找共同后缀**

Node的结构为：`Address Data Next`
```C++
struct node
{
	char data;
	int next;
	bool flag;//判断是否访问过
}Array[maxn];
```
思路：先把一个支路的遍历一遍，设置为访问过，在访问第二个支路时遇到的第一个相同结点即为共同后缀
```C++
for (int i = A1;i != -1;i = Array[i].next)
		Array[i].flag = true;//已经访问过
for (int i = A2;i != -1;i = Array[i].next) {
	if (Array[i].flag) {
		printf("%05d", i);
		return 0;
	}
}
```

### 1032 Sharing 25
**链表结点排序**

Node的结构为：`Address Data Next`
```C++
struct Node {
	int add;//地址（上一题没有add是因为序号当作地址，本题因为要用vector重新存储结点，故要存储add结点当前地址）
	int data;//数据
	int next;//下一数据的地址
}Array[maxn];
```
思路：只用修改next值即可
```C++
//输入过程
for (int i = 0;i < N;i++) {
	cin >> add;
	Array[add].add = add;
	cin >> Array[add].data >> Array[add].next;
}
//利用vector存储链表内的结点（存在游离在链表外的结点）
while (Address != -1) {//存在链表内的数
	l.push_back(Array[Address]);
	Address = Array[Address].next;
}
//输出
sort(l.begin(), l.end(), cmp);
for (int i = 0;i < l.size()-1;i++) {
	l[i].next = l[i + 1].add;//更新next值
	printf("%05d %d %05d\n", l[i].add, l[i].data, l[i].next);
}
```

### 1074 Reversing Linked List 25
**逆转链表**，给定K，要求每K个结点逆转，如：

given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4;
```C++
struct Node
{
	int Next;
	int Data;
}Array[maxn];

bool flag = true;//判断是否是第一个结点
int NextHead = Ad, LastEnd = -1;//头结点与尾结点
int Head;
//根据不断更新Ptr1、Ptr2进行链表逆转
while (Count >= K) {//满足逆转的条件
	int Ptr1 = NextHead;
	int Ptr2 = Array[Ptr1].Next;
	for (int i = 0;i < K - 1 ;i++) {
		int Ptr3 = Array[Ptr2].Next;//先存储Ptr2的Next，否则会丢掉
		Array[Ptr2].Next = Ptr1;
		Ptr1 = Ptr2;
		Ptr2 = Ptr3;
	}
	//4→3→2→1→5→6，1接到5上的情况（不用逆转的起始位置）
	Array[NextHead].Next = Ptr2;//假定之后不需要修改，直接接到下一轮的起始
	if (flag) {
		Head = Ptr1;
		flag = false;
	}
	else {
		//3→2→1→6→5→4，1接到6上的情况（逆转之后的起始位置）
		Array[LastEnd].Next = Ptr1;//更新一下
	}
	//NextHead一开始是头结点，逆转之后变为尾结点
	LastEnd = NextHead;//更新尾结点
	NextHead = Ptr2;//更新头结点
	Count -= K;
}
```

### 1079 Total Sales of Supply Chain 25
题目大意：给一棵树，在树根出货物的价格为p，然后从根结点开始每往下走一层，该层的货物价格将会在父亲结点的价格上增加r%，给出每个叶结点的货物量，求他们的价格之和

第i层：Ki​ ID[1] ID[2] ... ID[Ki​]
- 若Ki不为0，则后面的为儿子节点，若Ki为0，则后面的数字表示当前叶子结点的数目
```C++
struct Node
{
	int data;//存储叶子结点的个数
	vector<int>child;//存储儿子结点
};
```
```C++
//pow()计算n层对应的价格(1+r)^n * P
double cnt = 0.0;//cnt要是double类型
void DFS(int index, int depth)
{
	if (v[index].child.size() == 0) {//叶子结点
		cnt += v[index].data * P * pow(1 + r, depth);
		return;
	}
	for (int i = 0;i < v[index].child.size();i++)
		DFS(v[index].child[i], depth + 1);
}
```

### 1090 Highest Price in Supply Chain 25
与1079类似，1079给儿子结点，这题给该结点的父亲结点
若为-1，则为根节点（没有父结点），统计最高价格（最长路径）以及其条数。
```C++
void DFS(int S, int deep)
{
	if (v[S].size() == 0) {
		if (deep > length) {
			num = 1;
			length = deep;//记录深度
		}
		else if (deep == length) {
			num++;//统计数目
		}
	}
	for (int i = 0;i < v[S].size();i++) {
		DFS(v[S][i], deep + 1);
	}
}
```

### 1097 Deduplication on a Linked List 25
given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

node：`Address Key Next`
```C++
struct Node
{
	int add;
	int data;
	int next;
}Array[maxn];
```
```C++
vector<Node>res, rem;//分别是移除后的链表和被移除的链表
vector<int>tmp;//存储出现过的字符
//Address一开始是头结点
while (Address != -1) {
	if (find(tmp.begin(), tmp.end(), abs(Array[Address].data)) != tmp.end()) {
		//已经存过了
		rem.push_back(Array[Address]);
	}
	else {
		tmp.push_back(abs(Array[Address].data));//未存储就存储
		res.push_back(Array[Address]);
	}
	Address = Array[Address].next;
}
```
1074 Reversing Linked List
用Ptr1、Ptr2、Ptr3进行逆转，并用NextHead、LastEnd存储
很优雅的解法

1114 Family Property
并查集
int find(int x)//找到没有父结点的那个结点
{
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}
void Union(int a, int b)//使得ID最小的结点成为根节点
{
	int fa = find(a);
	int fb = find(b);
	if (fa > fb)
		father[fa] = fb;
	else if (fa < fb)
		father[fb] = fa;
}

1118 Birds in Forest
同理并查集
