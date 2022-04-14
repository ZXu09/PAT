#include<iostream>
using namespace std;
struct Node
{
	int Next;
	int Data;
}Array[100010];
int main()
{
	int Ad, N, K;
	scanf("%d %d %d", &Ad, &N, &K);
	for (int i = 0;i < N;i++) {
		int Address;
		scanf("%d", &Address);
		scanf("%d %d", &Array[Address].Data, &Array[Address].Next);
	}
	int Count = 0,Address=Ad;
	while (Address != -1) {//遍历计数
		Address = Array[Address].Next;
		Count++;
	}
	bool flag = true;//判断是否是第一个结点
	int NextHead = Ad, LastEnd = -1;//头结点与尾结点
	int Head;
	while (Count >= K) {//满足逆转的条件
		int Ptr1 = NextHead;
		int Ptr2 = Array[Ptr1].Next;
		for (int i = 0;i < K - 1 ;i++) {
			int Ptr3 = Array[Ptr2].Next;//先存储Ptr2的Next，否则会丢掉
			Array[Ptr2].Next = Ptr1;
			Ptr1 = Ptr2;
			Ptr2 = Ptr3;
		}
		Array[NextHead].Next = Ptr2;//假定之后不需要修改，直接接到下一轮的起始
		if (flag) {
			Head = Ptr1;
			flag = false;
		}
		else {
			Array[LastEnd].Next = Ptr1;//更新一下
		}
		LastEnd = NextHead;
		NextHead = Ptr2;
		Count -= K;
	}
	//输出：
	int i = Head;
	while (Array[i].Next != -1) {
		printf("%05d %d %05d\n", i, Array[i].Data, Array[i].Next);
		i = Array[i].Next;
	}
	printf("%05d %d %d\n", i, Array[i].Data, Array[i].Next);//最后一项
	return 0;
}