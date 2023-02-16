### 1002 A+B for Polynomials
存储对应指数下的底数即可，在输入时即相加
```
double p[1001] = { 0.0 };//存储对应指数下的底数值
int a;
double b;
cin >> a >> b;//指数和底数b^a
if (p[a] == 0)//未存储过
	p[a] = b;
else
	p[a] += b;
```


1022 
用title、author、publisher、key、publishyear查找ID
1.unordered_map<string, set<string>> mp;//key, value 对value值也就是id进行排序
2.for (auto it : mp[key]) {//采取auto类型+ 增强for 循环(auto迭代)
		cout << it << endl;
}
3.set<string>有序，升序排列
4.这题用map也不影响

1039
用int 类型存储学生的名字(map有一个点过不去)
int getid(char* name) //hash散列
{
	int id = 0;
	for (int i = 0; i < 3; i++)
		id = 26 * id + (name[i] - 'A');
	id = id * 10 + (name[3] - '0');
	return id;
}
1047 与 1039是同一类型的题
方法1：
getid(char* name) getname(int id)分别转换char和int类型
在vector中存储最后按照课程号进行输出
方法2：
char name[40010][5];
输入的N个同学就存储在name[i]中这个方法要方便很多，但占用的内存也会更大一些
