#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int ID;
	int virtue;
	int talent;
}Array[100010];
bool cmp(Node a, Node b)
{
	int a_total = a.talent + a.virtue;
	int b_total = b.talent + b.virtue;
	if (a_total == b_total) {
		if (a.virtue == b.virtue) {
			return a.ID < b.ID;
		}
		else return a.virtue > b.virtue;
	}
	else return a_total > b_total;
}
int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	int cnt = 0;
	vector<Node>sage;
	vector<Node>noble;
	vector<Node>fool;
	vector<Node>small;
	for (int i = 0;i < N;i++) {
		cnt++;
		cin >> Array[i].ID >> Array[i].virtue >> Array[i].talent;
		if (Array[i].virtue >= H && Array[i].talent >= H)
			sage.push_back(Array[i]);
		else if (Array[i].virtue >= H && Array[i].talent >= L)
			noble.push_back(Array[i]);
		else if (Array[i].virtue >= L && Array[i].talent >= H)
			small.push_back(Array[i]);
		else if (Array[i].virtue >= L && Array[i].talent >= L && 
			Array[i].virtue >= Array[i].talent)
			fool.push_back(Array[i]);//保证virtue>=talent才能当fool
		else if (Array[i].virtue >= L && Array[i].talent >= L &&
			Array[i].virtue < Array[i].talent)
			small.push_back(Array[i]);//平庸之辈也有小人呐
		else cnt--;
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(noble.begin(), noble.end(), cmp);
	sort(small.begin(), small.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	//输出
	cout << cnt << endl;
	for (int i = 0;i < sage.size();i++)
		cout << sage[i].ID << " " << sage[i].virtue << " " << sage[i].talent << endl;
	for (int i = 0;i < noble.size();i++)
		cout << noble[i].ID << " " << noble[i].virtue << " " << noble[i].talent << endl;
	for (int i = 0;i < fool.size();i++)
		cout << fool[i].ID << " " << fool[i].virtue << " " << fool[i].talent << endl;
	for (int i = 0;i < small.size();i++)
		cout << small[i].ID << " " << small[i].virtue << " " << small[i].talent << endl;
	return 0;
}