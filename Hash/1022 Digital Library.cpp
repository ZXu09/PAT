#include<iostream>
#include<set>//所有元素都会根据元素的键值自动排序
#include<unordered_map>//哈希表
#include<string>
using namespace std;


int main()
{
	int n, m;
	cin >> n;
	string id, title, author, publisher, publishyear, key;
	getchar();//输入换行符
	unordered_map<string, set<string>> mp;//key, value 对value值也就是id进行排序
	for (int i = 0;i < n;i++) {
		getline(cin, id);
		getline(cin, title);
		mp[title].insert(id);//title是用于查询id的key值
		getline(cin, author);
		mp[author].insert(id);
		while (cin >> key) {//对于每一个key值进行保存
			char c = getchar();//输入空格
			mp[key].insert(id);
			if (c == '\n')break;//key值输入结束
		}
		getline(cin, publisher);
		mp[publisher].insert(id);
		getline(cin, publishyear);
		mp[publishyear].insert(id);
	}
	cin >> m;
	int num;
	getchar();
	while (m--) {
		getline(cin, key);
		num = key[0] - '0';//首位的数字
		key = key.substr(3);//从第三位到末尾复制
		cout << num << ": " << key << endl;
		if (mp[key].size() == 0) {//没找到
			cout << "Not Found" << endl;
		}
		else {
			for (auto it : mp[key]) {//采取auto类型+ 增强for 循环(auto迭代)
				cout << it << endl;
			}
		}
	}
	return 0;
}