#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int N, M;
	cin >> N;
	vector<int>arr1;
	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		arr1.push_back(num);
	}

	cin >> M;
	vector<int>arr2;
	for (int i = 0;i < M;i++) {
		cin >> num;
		arr2.push_back(num);
	}

	int Median = (N + M - 1) / 2;
	int i = 0, j = 0, count = 0;
	int output = 0;
	if (N > M)//使arr2中的元素个数最多
		swap(arr1, arr2);
	while (count <= Median && i < arr1.size())
	{
		if (arr1[i] < arr2[j])
		{
			output = arr1[i];
			i++;
		}
		else
		{
			output = arr2[j];
			j++;
		}
		count++;
	}
	while (count <= Median)
	{
		output = arr2[j];
		j++;
		count++;
	}
	cout << output;
	return 0;
}