#include<iostream>
using namespace std;

int main()
{
	int N, M;
	int Collected[101] = { 0 };//是否是叶子结点1-不是；0-是
	int Level[101] = { 0 };//表示层数
	Level[1] = 1;//编号为1的根节点层号为1
	int result[101] = { 0 };//输出结果
	int Father[101] = { 0 };//存储父亲结点

	cin >> N >> M;//N：所有结点数,M：非叶子结点数
	int ID, K, L, IDS, MAXL = 1;

	for (int i = 0;i < M;i++) {
		cin >> ID >> K;
		if (K > 0)
			Collected[ID] = 1;//非叶子结点
		for (int j = 0;j < K;j++) {
			cin >> IDS;
			Father[IDS] = ID;
		}
	}

	//更新Level（之所以不在输入的时候更新，是因为可能父结点当时还没有与族谱链接）
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= N;j++) {
			if (Father[j] == i) {
				Level[j] = Level[i] + 1;
			}
		}
	}

	//输出
	for (int i = 1;i <= N;i++) {//遍历数组
		if (Collected[i] == 0)
			result[Level[i]]++;//该层的叶子结点数增加
		if (Level[i] > MAXL)
			MAXL = Level[i];
	}
	
	for (int i = 1;i < MAXL;i++) {
		cout << result[i] << " ";
	}
	cout << result[MAXL];
	return 0;
}