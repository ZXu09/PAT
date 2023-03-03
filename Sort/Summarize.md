### 1016 Phone Bills 25
给定一天24个小时对应的通话收费价格，然后N个人对应格式：

`ID`、`MM:dd:HH:mm`、`on-line` or `off-line`

每个`on-line`都应当按时间顺序匹配下一个同样的人的`off-line`，若匹配失败则忽略

输出：按照ID的字母顺序，输出ID、Month以及每段通话`dd:HH:mm`、持续时间、价格，通话按照时间顺序输出。最后输出总价格
```C++
struct customer
{
	string name;
	int month;
	int day;
	int hour;
	int minute;
	string on_off;
};
bool cmp(customer a, customer b)
{
	if (a.name != b.name)//对name升序排序
		return a.name < b.name;
	else if (a.day != b.day) 
		return a.day < b.day;
	else if (a.hour != b.hour) 
		return a.hour < b.hour;
	else return 
		a.minute < b.minute;
}
```
```C++
sort(list, list + N, cmp);//按照名字升序排序，名字一样则按时间，也就是说之后的匹配的通话一定挨着
string name, tname;
customer start, endt;
int flag=0,length;
double total = 0;

for (i = 0; i < N - 1; i++) {
    if (list[i + 1].on_off == "off-line" && list[i].on_off == "on-line" && list[i].name == list[i + 1].name) {
        //配对成功
        start = list[i];
        endt = list[++i];
        tname = start.name;//更新tname为当前人的名字
        if (name != tname) {//新的人了，结算上一个人的Total amount
            if (flag)//若是第一个人，不用输出上一个人的信息
                printf("Total amount: $%.2lf\n", total / 100);
            total = 0;//总共的金额
            name = tname;//更新name的值
            cout<<start.name<<" ";
            printf("%02d\n", start.month);
        }
        flag = 1;
        double once = 0;//计算单次的金额
        length = 0;//通话相隔的分钟数
        /*计算小时的金额和时长*/
        if (endt.day > start.day) {//跨天
            for (int dd = start.day + 1; dd < endt.day; dd++, length += 1440)//一天1440min
                once += 60 * sum;//一天的总金额
            for (int hh = start.hour + 1; hh < 24; hh++, length += 60)//起始天
                once += (60 * rate[hh]);//（分钟暂未记录，因此要+1）
            for (int hh = 0; hh < endt.hour; hh++, length += 60)//结束天               
                once += (60 * rate[hh]);
        }
        else//同一天                                  
            for (int hh = start.hour + 1; hh < endt.hour; hh++, length += 60)
                once += (60 * rate[hh]);
        /*计算分钟的金额和时长*/
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
```

1037
两组数据两两组合相乘，其和最大
1.排序，保证最大与最大，最小与最小的组合且符号相同
2.auto cb = coup.begin();或vector<int>::iterator cb是一样的
3.cb是指针 *cb取出coup的值

1038
将数字组合起来使其最小
1.绝妙的排序方法：
bool cmp(string a, string b)
{
	return a + b < b + a;
}
说明a在b前面组合的数要更小
1053
vector<vector<int>> ans;//存放所有路径
ans.push_back(v);v是条路径
对每种情况按字典序从大到小排序
sort(ans.begin(), ans.end(), greater<vector<int>>());

1067 Sort with Swap(0, i)
表排序的特点，判断0是否在这个环里
1.按照i=Num[i]遍历环，并修改Num[i] = i(方便判断环的结束)
2.环中有0 交换N-1次；环中无0 交换N+1次

1080 Graduate Admission
首先对每位同学的成绩进行排序，再按照规则插入学校
二维数组：	vector<vector<int>>v(M);//元素为vector的vector
排序：	for (auto it = v.begin();it != v.end();it++) {
		sort(it->begin(),it->end());
	}
另一种二维数组排序：
二维数组：  vector<int>v[M];
排序：  for(int i = 0; i < M; i++)//元素为vector的数组
          sort(sch[i].begin(), sch[i].end(), cmp2);
