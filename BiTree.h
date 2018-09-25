#pragma once
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <xfunctional>
#include <istream>
#include <string>
#include <set>
#include <iterator>
#include<sstream>
#include <map>
#include <queue>
#include<set>
#include<list>
#include<stack>
#include<vector>

namespace BiTree
{
	template<typename T>
	struct TNode
	{
		T val;
		TNode *left;
		TNode *right;
		TNode(T i = 0) 
		{ 
			val = i; 
			left = nullptr;
			right = nullptr;
		}
	};

	template<typename T>
	struct PTNode
	{
		TNode<T>* tnode;
		int count;
		PTNode(TNode<T>* pnode = nullptr, int val = 0) { tnode = pnode; count = val; }
	};

	template<typename T>
	bool init(TNode<T>* root,const T *front,const T *middle, int num)
	{
		int i = 0;
		root->val = front[0];
		if (num == 0)
			return false;

		for (i = 0; i < num; i++)
		{
			if (middle[i] == front[0]) break;
		}
		if (i != 0)
		{
			root->left = new TNode<T>(0);
			init(root->left, front + 1, middle, i);
		}
		if (i != num - 1)
		{
			root->right = new TNode<T>(0);
			init(root->right, front + i + 1, middle + i + 1, num - i - 1);
		}
		return true;
	}

	template<typename T> //递归后续遍历
	void PostOrder(TNode<T>* root)
	{
		if (root == nullptr) return;

		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val << " ";
	}

	template<typename T> //递归先续遍历
	void PreOrder(TNode<T>* root)
	{
		if (root == nullptr) return;

		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}

	template<typename T> //非递归先根遍历
	void PreOrderUnrec(TNode<T>* root)
	{
		stack<TNode<T>*> stacks;
		TNode<T>* p = root;	
	
		while (p != nullptr || !stacks.empty())
		{
			while (p != nullptr)
			{
				cout << p->val << " ";
				stacks.push(p);
				p = p->left;
			}
			if (!stacks.empty())
			{
				p = stacks.top();
				stacks.pop();
				p = p->right; //p != nullptr
			}
		}
	}

	template<typename T> //非递归中根遍历
	void MidOrderUnrec(TNode<T>* root)
	{
		stack<TNode<T>*> stacks;
		TNode<T>* p = root;
		
		while (p != nullptr || !stacks.empty())
		{
			while (p != nullptr)
			{
				stacks.push(p);
				p = p->left;
			}
			if (!stacks.empty())
			{
				p = stacks.top();
				stacks.pop();
				cout << p->val << " ";
				p = p->right;
			}
		}
	}

	template<typename T> //非递归后根遍历
	void PostOrderUnrec(TNode<T>* root)
	{
		stack<PTNode<T>> stacks;
		PTNode<T> temp(root);
		TNode<T>* p = root;
		while (p != nullptr || !stacks.empty())
		{
			while (p != nullptr)//沿左子树一直往下搜索，直至出现没有左子树的结点 
			{
				PTNode<T> node(p);
				stacks.push(node);
				p = p->left;
			}
			if (!stacks.empty()) 
			{
				temp = stacks.top();
				stacks.pop();
				if (temp.count == 0) //表示是第一次出现在栈顶 
				{
					temp.count = 1;
					stacks.push(temp);
					p = temp.tnode->right;
				}
				else if (temp.count == 1) //第二次出现在栈顶
				{
					cout << temp.tnode->val << " ";
					p = nullptr;
				}
			}
		}
	}

	template<typename T> //递归比较两颗树是否相等
	bool CompareTree(TNode<T>* root1, TNode<T>* root2)
	{
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 == nullptr || root2 == nullptr)
			return false;
		if (root1->val != root2->val)
			return false;

		return CompareTree(root1->left, root2->left) && CompareTree(root1->right, root2->right);
	}

	template<typename T> //递归得到一颗树的深度
	int GetTreeDeep(TNode<T>* root)
	{
		if (root == nullptr)
			return 0;
		return max(GetTreeDeep(root->left) + 1, GetTreeDeep(root->right) + 1);
	}

	template<typename T> //递归得到一颗树的深度
	int GetTreeDeep(TNode<T>* root, bool& blance)
	{
		if (root == nullptr)
			return 0;
		int left = GetTreeDeep(root->left) + 1;
		int right = GetTreeDeep(root->right) + 1;

		if (left - right > 1 || right - left > 1) blance = false;
		return max(left, right);
	}

	template<typename T> //平衡二叉树它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树
	bool isBlanced(TNode<T>*root)
	{
		bool blance = true;
		GetTreeDeep(root, blance);
		return blance;
	}

	template<typename T> //根据排序数组建立搜索二叉树
	void BuildSerchBiTree(TNode<T>* &root,const T* scr, int start, int end)
	{
		if (start > end)
			return;
		int mid = (start + end) / 2;
		root = new TNode<T>(scr[mid]);
		BuildSerchBiTree(root->left, scr, start, mid - 1);
		BuildSerchBiTree(root->right, scr, mid + 1, end);
	}

	template<typename T> //判断B是否是A的子树(根节点已对齐)
	bool TreeAHasTreeB(TNode<T>* A, TNode<T>* B)
	{
		if (B == nullptr)
			return true;
		if (A == nullptr)
			return false;
		if (A->val != B->val)
			return false;
		return TreeAHasTreeB(A->right, B->right) && TreeAHasTreeB(A->left, B->left);
	}

	template<typename T> //判断B是否是A的子树
	bool hasSubTree(TNode<T>* A, TNode<T>* B)
	{
		bool result = false;
		if (A != nullptr && B != nullptr)
		{
			if (A->val == B->val)
				result = TreeAHasTreeB(A, B);
			if (!result)
				result = hasSubTree(A->left, B);
			if (!result)
				result = hasSubTree(A->right, B);
		}
		return result;
	}
    
	template<typename T> //镜像树
	TNode<T>* mirrorTree(TNode<T>* root)
	{
		if (root == nullptr)
			return nullptr;
		TNode<T>* root1 = new TNode<T>;
		root1 = root;
		root1->left = mirrorTree(root->right);
		root1->right = mirrorTree(root->left);
		return root1;
	}

	template<typename T> //层序建立二叉树
	void buildTreeOnLevel(std::vector<T>& data, TNode<T>*& root)
	{
		queue<TNode<T>*> que;
		int len = data.size();
		root->val = data[0];
		que.push(root);
		int i = 1;
		while (i < len && !que.empty())
		{
			TNode<T>* p = que.front();
			que.pop();
			if (i == len)
				break;
			p->left = new TNode<T>(data[i++]);
			que.push(p->left);
			if (i == len)
				break;
			p->right = new TNode<T>(data[i++]);
			que.push(p->right);
		}
		MidOrderUnrec(root); cout << endl;
	}

	template<typename T> //二叉树变为链表的核心函数
	void CovertNode(TNode<T>* node, TNode<T>* &lastNodeInList)
	{
		if (node == nullptr)
			return;

		TNode<T>* current = node;
		if (current->left != nullptr)
			CovertNode(current->left, lastNodeInList);

		current->left = lastNodeInList;
		if (lastNodeInList != nullptr)
			lastNodeInList->right = current;

		lastNodeInList = current;
		if(current->right != nullptr)
			CovertNode(current->right, lastNodeInList);
	}

	template<typename T> //二叉树变为链表 
	TNode<T>* Covert(TNode<T>* root)
	{
		TNode<T>* lastNodeInList = nullptr;
		CovertNode(root, lastNodeInList);

		TNode<T>* HeadOfList = lastNodeInList;
		while (HeadOfList != nullptr && HeadOfList->left != nullptr)
		{
			HeadOfList = HeadOfList->left;
		}
		return HeadOfList;
	}

	template<typename T> //二叉树根节点到节点的路径
	bool FindRootToNodePath(list<T>& path, TNode<T>* root, T node)
	{
		if (root == nullptr)
			return false;
		if (root->val == node)
		{
			path.push_back(root->val);
			return true;
		}
		path.push_back(root->val);
		bool result = false;
		if (!result)
			result = FindRootToNodePath(path, root->left, node);
		if(!result)
			result = FindRootToNodePath(path, root->right, node);
		if (!result)
			path.pop_back();
		return result;
	}

	template<typename T>
	T GetLastComParent(TNode<T>* root, T node1, T node2)
	{
		list<T> path1, path2;
		FindRootToNodePath(path1, root, node1);
		FindRootToNodePath(path2, root, node2);
		T ans;
		auto itr1 = path1.begin();
		auto itr2 = path2.begin();
		while (itr1 != path1.end() && itr2 != path2.end())
		{
			if (*itr1 == *itr2)
			{
				ans = *itr1;
				break;
			}
			itr1++;
			itr2++;
		}
		cout << "LastComParent: "<< ans << endl;
		return ans;
	}

	void test()
	{
		string front = "ABDHIEJCFG";
		string middle = "HDIBJEAFCG";

		string front1 = "12473568";
		string middle1 = "47215386";

		TNode<char>* root = new TNode<char>(0);
		TNode<char>* root1 = new TNode<char>(0);
		TNode<int>* root2 = new TNode<int>(0);
		init(root, front.c_str(), middle.c_str(), front.length());
		init(root1, front1.c_str(), middle1.c_str(), front1.length());

		PostOrder(root); cout << endl;
		PostOrderUnrec(root); cout << endl;
		PreOrderUnrec(root); cout << endl;
		MidOrderUnrec(root); cout << endl;

		cout << "compare:" << CompareTree(root, root1) << endl;
		cout << "treedeep:" << GetTreeDeep(root) << endl;
		cout << "isBlance:" << isBlanced(root) << endl;

		/*BuildSerchBiTree(root2, "123456789", 0, 8);
		MidOrderUnrec(root2); cout << endl;*/
		cout << "subtree:" << hasSubTree(root, root) << endl;
		vector<int> data = {1,2,3,4,5,6,7,8,9};
		buildTreeOnLevel(data, root2);
		int dest = 9;
		list<int> path;
		bool a = FindRootToNodePath(path, root2, dest);
		cout << GetLastComParent(root2, 4, 8);
	}
};

