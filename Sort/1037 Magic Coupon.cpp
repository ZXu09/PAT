#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int Nc, Np, result = 0;
	vector<int> coup, prod;
	int temp;
	cin >> Nc;
	for (int i = 0; i < Nc; i++) {
		cin >> temp;
		coup.push_back(temp);
	}
	cin >> Np;
	for (int i = 0; i < Np; i++) {
		cin >> temp;
		prod.push_back(temp);
	}
	sort(coup.begin(), coup.end());
	sort(prod.begin(), prod.end());
	vector<int>::iterator cb = coup.begin(), ce = coup.end() - 1,
		pb = prod.begin(), pe = prod.end() - 1;
	//保证相乘数据是同号
	while (cb < coup.end() && pb < prod.end() && *cb < 0 && *pb < 0) {
		result += *cb * *pb;
		cb++;
		pb++;
	}
	while (ce >= coup.begin() && pe >= prod.begin() && *ce > 0 && *pe > 0) {
		result += *ce * *pe;
		ce--;
		pe--;
	}
	cout << result;
	return 0;
}