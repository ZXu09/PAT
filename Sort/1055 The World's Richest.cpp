#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Node
{
	string Name;
	int Age;
	int Net_Worth;
}Array[100010];
bool cmp(Node a, Node b)
{
	if (a.Net_Worth == b.Net_Worth) {
		if (a.Age == b.Age)
			return a.Name.compare(b.Name) < 0;
		else return a.Age < b.Age;
	}
	else return a.Net_Worth > b.Net_Worth;
}
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		cin >> Array[i].Name >> Array[i].Age >> Array[i].Net_Worth;
	}
	sort(Array, Array + N, cmp);
	int M, cnt, Amin, Amax;
	for (int i = 0;i < K;i++) {
		cin >> M >> Amin >> Amax;
		printf("Case #%d:\n", i + 1);
		cnt = 0;
		int j;
		for (j = 0;j < N;j++) {
			if (Array[j].Age >= Amin && Array[j].Age <= Amax) {
				cout << Array[j].Name << " " << Array[j].Age << " " << Array[j].Net_Worth << endl;
				cnt++;
				if (cnt == M)
					break;
			}
		}
		if (cnt == 0)
			cout << "None" << endl;
	}
	return 0;
}