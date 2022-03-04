#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define begin 28800//开始的时间
#define end 75600//结束的时间
using namespace std;

int N;

struct Person
{
	int arrive;//到达时间
	float wait;//等待时间
	int serve;//服务时间
	int play;//训练时间
	int tag;//是否是VIP
	bool served = false;//是否被服务过
}p[10001];

struct table
{
	int poptime = begin;//空闲时间
	int count = 0;//接待人数
	bool vip;
};
vector<table> tables;
bool cmp1(Person a, Person b)
{
	return a.arrive < b.arrive;
}
bool cmp2(Person a, Person b)
{
	return a.serve < b.serve;
}
int FindNextVIP(int vip_id) //查询队伍中第一个没有被服务的VIP
{
	vip_id++;
	while (vip_id < N && !p[vip_id].tag)
		vip_id++;
	return vip_id >= N ? 0 : vip_id;
}
void alloc(int id, int table_id)//为第id个人分配桌子
{
	if (tables[table_id].poptime <= p[id].arrive)//不需要等待
		p[id].serve = p[id].arrive;//服务时间与到达时间一致
	else
		p[id].serve = tables[table_id].poptime;//服务时间与桌子的空闲时间一致
	tables[table_id].poptime = p[id].serve + p[id].play;
	tables[table_id].count++;//接待过的人+1
	p[id].wait = round((p[id].serve - p[id].arrive) / 60.0);
	p[id].served = true;

}

int main()
{
	int i;
	int hh, mm, ss, tt, tag;
	cin >> N;
	int sum = 0;
	for (i = 0;i < N;i++) {
		scanf_s("%d:%d:%d %d %d", &hh, &mm, &ss, &tt, &tag);
		sum = 3600 * hh + 60 * mm + ss;
		p[i].arrive = sum;
		p[i].play = p[i].play <= 120 ? tt * 60 : 120 * 60;//训练时间要小于120
		p[i].tag = tag;
	}
	int K, M;
	cin >> K >> M;
	tables.resize(K + 1);//初始化容量
	int table;
	for (i = 0;i < M;i++) {
		cin >> table;
		tables[table].vip = true;
	}
	sort(p, p + N, cmp1);//按照到来的时间进行排序
	int vip_id = FindNextVIP(-1);//找到VIP所在的位置
	i = 0;
	while (i < N) {
		if (p[i].serve) {//找到未被服务的人
			i++;
			continue;//以这种方式跳过VIP用户
		}
		int min_table_id = -1;//空闲且编号最小的桌子
		int min = 0x3f3f3f;//最短的空闲时间
		for (int j = 1;j <= K;j++) {//遍历所有桌子找到空闲的桌子
			if (tables[j].poptime < min) {
				min = tables[j].poptime;
				min_table_id = j;
			}
			if (tables[j].poptime <= p[i].arrive) {//存在空闲的桌子
				min_table_id = j;
				break;
			}
		}
		if (tables[min_table_id].poptime >= end || p[i].arrive >= end)
			break;//排队结束
		if (p[i].tag == 1) {//是VIP的情况
			int vip_table_id = -1;//vip桌子中空闲且序号最小
			for (int j = 1;j <= K;j++) {//查找是否有空闲的VIP桌子
				if (tables[j].vip && tables[j].poptime <= p[i].arrive) {
					vip_table_id = j;
					break;
				}
			}
			if (i == vip_id)
				vip_id = FindNextVIP(vip_id);//更新下一个VIP的位置
			if (vip_table_id == -1) {//没有VIP，只能分配普通桌子
				alloc(i++, min_table_id);
			}
			else {
				alloc(i++, vip_table_id);
			}
		}//不是VIP的情况
		else {
			if (tables[min_table_id].vip) {//是VIP桌子
				if (!p[vip_id].serve && p[vip_id].arrive <= tables[min_table_id].poptime) {
					//有VIP用户还没被服务且该VIP入队的时候桌子还未空闲
					alloc(vip_id, min_table_id);
					vip_id = FindNextVIP(vip_id);
					continue;
				}
			}
			alloc(i++, min_table_id);//分配给该用户
		}
	}
	sort(p, p + N, cmp2);//根据serve的时间进行排序
	for (int j = 0;j < N;j++) {
		if (p[j].served) {
			printf("%02d:%02d:%02d ", p[j].arrive / 3600, (p[j].arrive % 3600) / 60,
				(p[j].arrive % 3600) % 60);
			printf("%02d:%02d:%02d %.0f\n", p[j].serve / 3600, (p[j].serve % 3600) / 60,
				(p[j].serve % 3600) % 60,p[j].wait);
		}
	}
	for (int j = 1;j <= K;j++) {
		if (j != 1) printf(" ");
		printf("%d", tables[j].count);
	}
	return 0;
}