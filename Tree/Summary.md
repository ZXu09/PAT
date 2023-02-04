### 1004 Counting Leaves 30
利用  `Father[ID_i] = ID;`记忆结点之间的父子关系，再统计level

***
**Traversal**
### 1020 Tree Traversals 25
postorder and inorder -> level order后序中序输出层序
1.`solve(int PreL, int InL, int PostL, int L, int index);`
递归得到前序并记录index
2.利用完全二叉树存储index，利用index的大小进行排序输出

### 1086 Tree Traversals Again 25
**栈和遍历之间的关系**：

PUSH：preorder
POP: inorder

利用前序和中序遍历solve后序

### 1119 Pre- and Post-order Traversals
给定先序和后序，判断中序及是否唯一  秒极！！
```C++
void Traversal(int prel, int prer, int postl, int postr)
{
	if (prel == prer) {//只有一个结点的子树
		in.push_back(pre[prel]);
		return;
	}
	int i = prel + 1;//pre中找到右子树（存在）的根
	while (i <= prer && pre[i] != post[postr - 1])
		i++;//此时i为右子树的根
	int leftlength = i - prel - 1;//i-prel-1为左子树的长度
	if (i - prel > 1) {//存在左子树()
		Traversal(prel + 1, i - 1, postl, postl + leftlength - 1);
	}
	else//此时只有一边子树，即右子树
		unique = false;
	in.push_back(pre[prel]);//访问根节点
	Traversal(i, prer, postl + leftlength, postr - 1);//若只有一个子树，默认为右子树
}
```

### 1043  Is It a Binary Search Tree 25
输入先序遍历的序列
递归思想：对每个根节点，判断其是否满足BST的定义
```C++
void PostOrder(int l, int r)//先序遍历最左为根，最右为最大值
{
	if (!flag || l > r)
		return;
	int i = l + 1, j = r;//i为左子树的根，j为右子树最大
	if (!isMirror) {//BST 左小右大
		//注意i<=r是因为存在只有左/右子树的情况，此时j为左子树最大，i要越过j
		while (i <= r && Pre[i] < Pre[l])i++;//比根Pre[l]小，递增
		while (j > l && Pre[j] >= Pre[l])j--;//比根Pre[l]大，递减
	}
	if (isMirror) {
		while (i <= r && Pre[i] >= Pre[l])i++;//比根Pre[l]大，递增
		while (j > l && Pre[j] < Pre[l])j--;//比根Pre[l]小，递减
	}
	if (i - j != 1) {//此时i对应的结点比根小，j对应的结点比根大，相差为1
		flag = false;
		return;
	}
	//后序-左右中
	PostOrder(l + 1, i - 1);//左子树
	PostOrder(i, r);//右子树
	Post.push_back(Pre[l]);//根节点入队
}
 ```
 ```
 
如:8
 6  10
5 7 8 11
pre[]=8 6 5 7 10 8 11 -> 8 6 5 7 10 8 11
 	i          j           j  i
```
***
**树状数组**

 1. 单点修改：更改数组中一个元素的值
 2. 区间查询：查询一个区间内所有元素的和
 
例如11，转化为二进制数就是1011，如果我们要求前11项和，可以分别查询 [(0000),(1000)]、[(1000),(1010)]以及[(1010),(1011)]的和再相加。
这三个区间怎么来的呢？其实就是不断地去掉二进制数最右边的一个1的过程
1011->1010->1000 对应c[1011]+c[1010]+c[1000]

### 1057 Stack 30 -求栈中元素的中位数
树状数组，方便求sum和进行修改；时间复杂度均为O(logN)
本题的核心在于求第k = (s.size() + 1) / 2大的数。查询小于等于x的数的个数是否等于k

 1. `int c[maxn]`树状数组，c[i]代表其子树结点出现的次数
 2. `#define lowbit(i) ((i)&(-i))`取最低位的1，最右边的1连带后面的0，比如10100->100
 3. 
```C++
void update(int x, int v)//单点修改(v代表出现了x的次数)
{
	//1011->1100->10000(1011、1100都是10000的子树!)
	for (int i = x;i < maxn;i += lowbit(i){
		c[i] += v;//顺着树向上爬
	}
}
int getsum(int x)//区域查询,小于等于x的数的个数
{
	int sum = 0;
	//比如111->110->100
	//这个过程类似于同层进行爬，不会重复统计到共同树根1000
	for (int i = x;i >= 1;i -= lowbit(i)) 
		sum += c[i];
	}
	return sum;
}
void PeekMedian() //二分法
{
	int left = 1, right = maxn, mid;//Key保证>0
	int k = (s.size() + 1) / 2;//代表要求的第k大小的数
	while (left < right) {
		mid = (left + right) / 2;
		if (getsum(mid) >= k)//小于等于mid的数的个数大于k个
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
}
```

### 1064 Complete Binary Search Tree 30 -计算左子树长度
BST -> level order traversal
排序后的BST相当于中序遍历
利用BST的性质，判断左子树的长度，得到根节点的值
层序遍历：利用index，即root
```C++
void Sort_CBT(int L, int index, int treeL, int lnode)//lnode用于累加
{
	if (L == 0)
		return;
	int level = 1;//计算N个结点的完全二叉树的高度
	int lastlevel;//最后一层的结点数
	int maxlevel;//最后一层最多的结点数
	while ((pow(2, level / 1.0) - 1) < L) {
		level++;
	}
	lastlevel = L - (pow(2, (level - 1) / 1.0) - 1);
	maxlevel = pow(2, (level - 1) / 1.0);

	int leftnode = LeftNode(maxlevel, lastlevel, level);
	int rightnode = L - leftnode - 1;

	Tree[treeL].index = index;
	Tree[treeL].value = Array[leftnode + lnode];
	Sort_CBT(leftnode, 2 * index + 1, treeL + 1, lnode);
	//加上左子树和根节点的
	Sort_CBT(rightnode, 2 * index + 2, treeL + 1 + leftnode, lnode + leftnode + 1);
}
```
***
**AVL树（平衡二叉树）**
An AVL tree is a self-balancing binary search tree.
利用定义实现
### 1066 Root of AVL Tree 25
```C++
BinTree LL(BinTree T)
{
	BinTree B = T->left;
	T->left = B->right;
	B->right = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->left), T->height) + 1;
	return B;
}
BinTree LR(BinTree T)
{
	T->right = RR(T->right);
	return LL(T);
}
BinTree Insert(BinTree T, int V)
{
	if (!T)
		T = MakeTree(V);//在此处创建新的结点
	else if (V < T->data) {
		T->left = Insert(T->left, V);//一路递归到插入新结点
		//自更新结点的路径向上调整AVL树
		if (GetHeight(T->left) - GetHeight(T->right) == 2) {
			if (V < T->left->data)
				T = LL(T);
			else
				T = LR(T);
		}
	}
	else if (V > T->data) {
		T->right = Insert(T->right, V);
		//自更新结点的路径向上调整AVL树
		if (GetHeight(T->right) - GetHeight(T->left) == 2) {
			if (V > T->right->data)
				T = RR(T);
			else
				T = RL(T);
		}
	}
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	return T;
}
```

### 1099 Build A Binary Search Tree 30
inorder中序遍历填值，因为是BST树满足左边小右边大，因此将key排序后就可以填值
```C++
void inOrder(int root)//中序遍历填值
{
	if (root == -1) return;
	inOrder(T[root].left); //-1也要插入
	T[root].data = key[num++];
	inOrder(T[root].right);
}
void Levelorder(int root)
{
	queue<int> q;
	q.push(root);
	bool flag = false;//控制输出格式
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (!flag) {
			cout << Array[tmp].data;
			flag = true;
		}
		else cout << " " << Array[tmp].data;
		if (Array[tmp].left != -1)
			q.push(Array[tmp].left);
		if (Array[tmp].right != -1)
			q.push(Array[tmp].right);
	}
}
```
### 1102 Invert a Binary Tree 25
类似1099的解决方法

### 1110 Complete Binary Tree 25
我的方法：Levelorder遍历，若一个结点存在左/右子树且之前已经有结点没有左/右子树，说明不是完全二叉树
柳神方法：Inorder遍历找到最大index下标，对比结点数

### 1115 Counting Nodes in a Binary Search Tree
求一个二叉搜索树最后两层的结点
```C++
struct Node
{
	int data;
	PNode left, right;
};

PNode Build(PNode root, int data)
{
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Build(root->left, data);
	else
		root->right = Build(root->right, data);
	return root;
}
int Num[1010];//存储对应层数的结点个数
int maxdepth = -1;//由于会递归到空结点，故为最深的层数+1

void Inorder(PNode root, int depth) {
	if (root == NULL) {
		maxdepth = max(depth, maxdepth);
		return;
	}
	Num[depth]++;
	Inorder(root->left, depth + 1);
	Inorder(root->right, depth + 1);
}
```

