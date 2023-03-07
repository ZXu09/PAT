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

### 1025 PAT Ranking 25
N：测试场地，对于每个测试场地都有K个人以ID, scores的形式

输出：所有参赛者的数量，然后输出最终的排名，若排名一致，按照ID顺序输出：

`registration_number final_rank location_number local_rank`,
```C++
struct Person
{
	string ID;
	int score;
	int rank;
	int location;
	int lrank;
}person[30001];

bool cmp(Person a,Person b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else if (a.ID != b.ID)
		return (a.ID < b.ID);
}
```
```C++
for (int i = 1;i <= N;i++) {
    cin >> K;
    /*对每K个，即一个考点的人进行排序*/
    for (int j = begin;j < begin + K;j++) {
        cin >> person[j].ID >> person[j].score;
        person[j].location = i;
    }
    for (int j = begin;j < begin + K;j++) {//遍历确定lrank
        int lrank = 1;
        for (int t = begin;t < begin + K;t++) {
            if (person[t].score > person[j].score)
                lrank++;
        }
        person[j].lrank = lrank;
    }
    begin += K;
}
sort(person, person + begin, cmp);
person[0].rank = 1;
for (int i = 1;i < begin;i++) {
    if (person[i].score == person[i - 1].score) {
        person[i].rank = person[i - 1].rank;
    }
    else {
        person[i].rank = i + 1;//第几个同学就是第几位
    }
}
```

### 1153 Decode Registration Card of PAT 25
**unordered_map的应用**
题目大意：给出一组学生的准考证号和成绩，准考证号包含了等级(乙甲顶)，考场号，日期，和个人编号信息，
`B123180908127 99`
- 等级：B
- 考场：123
- 日期：180908
- 个人编号：127
- 成绩：99
并有三种查询方式
1. 给出考试等级，找出该等级的考生，按照成绩降序，准考证升序排序
2. 给出考场号，统计该考场的考生数量和总得分
3. 给出考试日期，查询改日期下所有考场的考试人数，按照人数降序，考场号升序排序（本质上用准考证进行升序排序也许）
```C++
vector<node> v(n);
struct node {
    string t;//准考证号
    int value;//成绩
};
bool cmp(const node &a, const node &b) {
    if(a.value==b.value)
        return a.t<b.t;
    else return a.value>b.value;
}
for(int i=1;i<=K;i++){
	vector<node> ans;
	...
}
```
分析：先把所有考生的准考证和分数记录下来～
1. 按照等级查询，枚举选取匹配的学生，然后排序即可。
若满足`v[j].t[0] == s[0]`，即等级相同的，入队ans。
2.按照考场查询，枚举选取匹配的学生，然后计数、求和。
若满足`v[j].t.substr(1, 3) == s`，即考场号相同的，统计人数及总分。
3.按日期查询每个考场人数，用**unordered_map**存储，最后排序汇总。
```C++
unordered_map<string, int> m;
for (int j = 0; j < n; j++)
    if (v[j].t.substr(4, 6) == s) //满足考场日期一样
	    m[v[j].t.substr(1, 3)]++;//该考生对应的site的num++
for (auto it : m) 
	ans.push_back({it.first, it.second});
```
注意:1.第三个用map存储会超时，用**unordered_map**就不会超时啦～
2.排序传参建议用引用传参，这样更快，虽然有时候不用引用传参也能通过，但还是尽量用，养成好习惯
最后`sort(ans.begin(), ans.end(),cmp);`



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
