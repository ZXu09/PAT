
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
