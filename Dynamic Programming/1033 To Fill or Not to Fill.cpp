#include<iostream>
#define INF 0x3f3f3f
using namespace std;
int main()
{
	int Capacity, Distance, Davg, N;
	cin >> Capacity >> Distance >> Davg >> N;
	float Price[30001];
	fill(Price, Price + 30001, INF);
	float P;
	int D;
	for (int i = 0;i < N;i++) {
		cin >> P >> D;
		Price[D] = P;
	}
	int MaxD = Capacity * Davg;
	int Begin = 0;//起始点
	float cost = 0;//总花费
	int  MinStation;
	float MinPrice, len, NowGas = 0;
	while (Begin < Distance) {
		MinPrice = INF;
		if (Price[0] == INF) {//无法出发
			printf("The maximum travel distance = 0.00\n");
			return 0;
		}
		for (int i = Begin + 1;i <= Begin + MaxD;i++) {//在可以到达的最远距离内寻找
			if (i <= Distance && Price[i] < Price[Begin]) {//直接到达价格更低的地方,防止数据逸出
				len = i - Begin;
				//此时不补满油
				if (!NowGas)
					cost += (len / Davg) * Price[Begin];
				else cost += ((len / Davg) - NowGas) * Price[Begin];//减去已经有的油
				Begin = i;//更新起始点
				continue;
			}
			if (i <= Distance && Price[i] < MinPrice) {
				MinPrice = Price[i];
				MinStation = i;
			}
		}
		if (Distance - Begin <= MaxD) {
			len = Distance - Begin;
			cost += (len / Davg) * Price[Begin];//仅需加最后一段路的油
			break;
		}
		if (MinPrice == INF) {//说明没有站点了
			float result = Begin + MaxD;
			printf("The maximum travel distance = %.2f\n", result);
			return 0;
		}
		len = MinStation - Begin;
		//加满油
		if (!NowGas)
			cost += Capacity * Price[Begin];//空的情况
		else
			cost += (Capacity - NowGas) * Price[Begin];
		//NowGas指到达下一个站点后剩余的油
		NowGas = Capacity - (len / Davg);//容量减去这段路程所需的油
		Begin = MinStation;
	}
	printf("%.2f", cost);
	return 0;
}