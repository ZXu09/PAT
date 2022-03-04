#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct customer
{
	char name[21];
	int month;
	int day;
	int hour;
	int minute;
	char on_off[9];
};
bool cmp(customer a, customer b)
{
	if (strcmp(a.name, b.name))//对name升序排序
		return strcmp(a.name, b.name) < 0;
	else if (a.day != b.day) 
		return a.day < b.day;
	else if (a.hour != b.hour) 
		return a.hour < b.hour;
	else return 
		a.minute < b.minute;
}
int main()
{
	customer list[1001];//对每条信息的结构体数组

	int rate[24], sum = 0;
	int i,N;
	for (i = 0;i < 24;i++) {
		cin >> rate[i];
		sum += rate[i];
	}
	cin >> N;
	for (i = 0;i < N;i++) {
		scanf_s("%s %d:%d:%d:%d %s", list[i].name,21, &list[i].month, &list[i].day, &list[i].hour, &list[i].minute, list[i].on_off,9);
	}
	sort(list, list + N, cmp);
	string name, tname;
	customer start, endt;
	int flag=0,length;
	double total = 0;

	for (i = 0; i < N - 1; i++) {//最多有N-1个配对
		if (strcmp(list[i + 1].on_off, "off-line") == 0 && strcmp(list[i].on_off, "on-line") == 0 && strcmp(list[i].name, list[i + 1].name) == 0) {
			//配对成功
			start = list[i];endt = list[++i];
			tname = string(start.name);//更新tname为当前人的名字
			if (name != tname) {
				if (flag)//已经计算好了上个人的total
					printf("Total amount: $%.2lf\n", total / 100);
				total = 0;//总共的金额
				name = tname;//更新name的值
				printf("%s %02d\n", start.name, start.month);
			}
			flag = 1;
			double once = 0;//计算单次的金额
			length = 0;//通话相隔的分钟数
			if (endt.day > start.day) {//跨天
				for (int dd = start.day + 1; dd < endt.day; dd++, length += 1440)//一天1440min
					once += 60 * sum;
				for (int hh = start.hour + 1; hh < 24; hh++, length += 60)//起始天
					once += (60 * rate[hh]);//（分钟暂未记录，因此要+1）
				for (int hh = 0; hh < endt.hour; hh++, length += 60)//结束天               
					once += (60 * rate[hh]);
			}
			else//同一天                                  
				for (int hh = start.hour + 1; hh < endt.hour; hh++, length += 60)
					once += (60 * rate[hh]);
			if (start.hour == endt.hour && start.day == endt.day) {//同一天同一小时
				length += (endt.minute - start.minute);
				once += rate[start.hour] * (endt.minute - start.minute);
			}
			else {
				length += (60 - start.minute) + endt.minute;//补上差的min
				once += rate[start.hour] * (60 - start.minute) + rate[endt.hour] * endt.minute;
			}
			total += once;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", start.day, start.hour, start.minute,
				endt.day, endt.hour, endt.minute, length, once / 100);
			
		}
	}
	if (flag)
		printf("Total amount: $%.2lf\n", total / 100);
	return 0;
}