#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct student
{
	int ID;
	string name;
	int grade;
}s[100001];
bool cmp1(student a, student b)//°´ÕÕIDÉıĞò
{
	return a.ID < b.ID;
}
bool cmp2(student a, student b)
{
	if (a.name.compare(b.name) < 0)
		return true;
	else if (a.name.compare(b.name) > 0)
		return false;
	else if(a.name.compare(b.name)==0)
		return a.ID < b.ID;
}
bool cmp3(student a, student b)
{
	if (a.grade < b.grade)
		return true;
	else if (a.grade > b.grade)
		return false;
	else if(a.grade == b.grade)
		return a.ID < b.ID;
}
int main()
{
	int N, C;
	cin >> N >> C;
	for (int i = 0;i < N;i++) {
		cin >> s[i].ID >> s[i].name >> s[i].grade;
	}
	if (C == 1)
		sort(s, s + N, cmp1);
	else if (C == 2)
		sort(s, s + N, cmp2);
	else if (C == 3)
		sort(s, s + N, cmp3);
	for (int i = 0;i < N;i++) {
		printf("%06d", s[i].ID);
		cout << " " << s[i].name << " " << s[i].grade << endl;
	}
	return 0;
}