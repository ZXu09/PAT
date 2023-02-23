
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
