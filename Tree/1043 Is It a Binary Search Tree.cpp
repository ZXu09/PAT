#include<iostream>
#include<vector>
using namespace std;
bool isMirror, flag = true;
int N;
vector<int> pre, post;

void PostOrder(int s, int e)//s为根节点、e为最大的结点(这棵树的起始和结束结点)
{
	if (!flag || s > e) 
		return;
	int i = s + 1, j = e;//i为左子树的根,j为右子树的最大的结点
	if (isMirror == false) {//不是镜像（左子树小，右子树大）
		while (i <= e && pre[s] > pre[i]) i++;//满足比根节点小就递增
		while (j > s && pre[s] <= pre[j]) j--;//满足比根节点大就递减
	}
	else if (isMirror == true) {//反过来
		while (i <= e && pre[s] <= pre[i]) i++;           
		while (j > s && pre[s] > pre[j])  j--;
	}
	if (i - j != 1) {//此时i对应的结点比根小，j对应的结点比根大，相差为1
		flag = false;
		return;
	}
	//后序-左右中
	PostOrder(s + 1, i - 1);//左子树
	PostOrder(i, e);//右子树
	post.push_back(pre[s]);//根节点入队

}
int main()
{
	cin >> N;
	pre.resize(N);
	for (int i = 0;i < N;i++) {
		cin >> pre[i];
	}
	if (N > 1 && pre[1] - pre[0] > 0) //假定是镜像的
		isMirror = true;
	PostOrder(0, N - 1);
	if (!flag)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0;i < post.size();i++) {
			if (i)
				cout << " ";
			cout << post[i];
		}
	}
	return 0;
}