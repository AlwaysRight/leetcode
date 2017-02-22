/*
 * tree.cpp
 *
 *  Created on: 2017��2��21��
 *      Author: bb
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Tree {
public:
	//============================== 1====================================
	//��������ͺ������д��������, ��Ҫ�������� vector�� ֱ�������ã���Ȼmemory������
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		TreeNode * root = NULL;
		if (inorder.size() > 0) {
			buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
					postorder.size() - 1, root, 0);
		}
		return root;
	}

	void buildTree(vector<int>& inorder, int ib, int ie, vector<int>& postorder,
			int pb, int pe, TreeNode * &root, int side) {
		int rootval = postorder[pe];
		if (root == NULL) {
			root = new TreeNode(rootval);
		} else if (side == 0) { //left sub tree
			root->left = new TreeNode(rootval);
		} else {
			root->right = new TreeNode(rootval);
		}
		int left = 0;
		for (int i = ib; i <= ie; i++) {
			if (inorder[i] == rootval) {
				left = i;
				break;
			}
		}
		if (left > ib) {
			buildTree(inorder, ib, left - 1, postorder, pb, left - ib - 1 + pb,
					root->left, 0);
		}
		if (ie > left) {
			buildTree(inorder, left + 1, ie, postorder, pb + left - ib, pe - 1,
					root->right, 1);
		}
	}

	//===============================2================================
	/**
	 * For a undirected graph with tree characteristics,
	 * we can choose any node as the root. The result graph
	 * is then a rooted tree. Among all possible rooted trees,
	 * those with minimum height are called minimum height trees (MHTs).
	 * Given such a graph, write a function to find all the MHTs and
	 * return a list of their root labels.
	 * Example 2:

	 Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

	 0  1  2
	 \ | /
	 3
	 |
	 4
	 |
	 5
	 return [3, 4]
	 *
	 */
	//--------------------------�ָ���------------------------------------
	/**
	 * �����뵽���� ����ÿ���ڵ�����ȼ��㣬���Ǵ˷�������50+������ʱ�� ��������
	 */
	vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
		int minDepth = -1;
		vector<int> result;
		for (int i = 0; i < n; i++) {
			int depth = findMinHeightTrees(i, -1, edges, minDepth, 0);
			if (minDepth == -1 || depth <= minDepth) {
				if (depth < minDepth) {
					result.clear();
				}
				result.push_back(i);
				minDepth = depth;
			}
		}
		return result;
	}

	int findMinHeightTrees(int n, int fromN, vector<pair<int, int> >& edges,
			int minDepth, int depth) {
		if (minDepth != -1 && depth > minDepth) { // �Ѿ�������С������ˣ� �����ٵݹ������
			return depth;
		}
		int max = depth;
		int temp = 0;
		for (int i = 0; i < edges.size(); i++) {
			pair<int, int> p = edges[i];
			if (p.first != n && p.second != n) {
				continue;
			}
			if (p.first == n && p.second != fromN) {
				temp = findMinHeightTrees(p.second, p.first, edges, minDepth,
						depth + 1);
			} else if (p.second == n && p.first != fromN) {
				temp = findMinHeightTrees(p.first, p.second, edges, minDepth,
						depth + 1);
			}
			if (temp > max) {
				max = temp;
			}
		}
		return max;
	}
	//--------------------------�ָ���------------------------------------

	/**
	 * ��ʵ���Խ����ͼ��������һ�£� ÿһ��ڵ����һ���ڵ㣬 �����м��һ����2���ڵ���Ϊrootʱ �߶���С��
	 * ���ϵġ�����С��㷨
	 * ����ͼ�����鱣��ÿ���ڵ������Ķ���ڵ�
	 * �ҳ�Ҷ�ӽڵ㣨ֻ��һ���ߵĵ㣩�� ����У� Ȼ��������ȥ��Щ�㣬 ����ȥ���ߣ��ظ���ʣ��1or2�ڵ�
	 */

	vector<int> findMinHeightTrees2(int n, vector<pair<int, int> >& edges) {
		vector<int> result;
		if (n < 1) {
			return result;
		} else if (n == 1) { // ע�� ֻ��һ���ڵ���������
			result.push_back(0);
			return result;
		}

		vector<vector<int> > adj(n);
		queue<int> q;

		for (int i = 0; i < edges.size(); i++) {
			pair<int, int> egde = edges[i];
			adj[egde.first].push_back(egde.second);
			adj[egde.second].push_back(egde.first);
		}

		for (int i = 0; i < n; i++) {
			if (adj[i].size() == 1) {
				q.push(i);
			}
		}

		while (n > 2) {
			n = n - q.size();
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int t = q.front();
				q.pop();
				int cont = adj[t][0];
				vector<int>::iterator iter;
				for (iter = adj[cont].begin(); iter != adj[cont].end();
						iter++) {
					if ((*iter) == t) {
						adj[cont].erase(iter);
						break;
					}
				}
				if (adj[cont].size() == 1) {
					q.push(cont);
				}
			}
		}
		while (!q.empty()) {
			result.push_back(q.front());
			q.pop();
		}
		return result;
	}

	//============================================3=======================================
	//�ж�һ�����ǲ���BST
	//�����뵽�����������ÿһ��������Ԫ�ض�Ҫ��ǰһ����
	bool isValidBST(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		long last = (numeric_limits<long>::min)();
		return isValidBST(root, last);
	}

	bool isValidBST(TreeNode* t, long &last) {	//ע��Ҫ��last �����á���
		bool l = true, r = true;
		if (t->left) {
			l = isValidBST(t->left, last);
		}
		if (t->val <= last) {
			return false;
		}
		last = t->val;
		if (t->right) {
			r = isValidBST(t->right, last);
		}
		return l && r;
	}

	// ���⿼�ǣ�ÿ��һ��root ��Ҫ����������ģ� С���ұ���С�ġ�
	bool isValidBST2(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		long min = (numeric_limits<long>::min)();
		long max = (numeric_limits<long>::max)();
		return isValidBST(root, min, max);
	}

	bool isValidBST(TreeNode* t, long min, long max) {
		if (t == NULL) {
			return true;
		}
		if (!(t->val > min && t->val < max)) {
			return false;
		}
		if (!isValidBST(t->left, min, t->val)) {
			return false;
		}
		if (!isValidBST(t->right, t->val, max)) {
			return false;
		}
		return true;
	}

	//===================================4=================================
	//ǰ���������ĿҪ���õݹ顣����stack,�ȴ�ӡ���ٰѽڵ��stack. ��������������������ͷ�ٳ�ջһ��������������ֱ��ջ��
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) {
			return result;
		}
		stack<TreeNode *> s;
		s.push(root);
		result.push_back(root->val);
		TreeNode * node = root->left;
		while (!s.empty()) {
			while (node) {
				result.push_back(node->val);
				s.push(node);
				node = node->left;
			}
			node = s.top()->right;
			s.pop();
			if (node != NULL) {
				s.push(node);
				result.push_back(node->val);
				node = node->left;
			}
		}
		return result;
	}
};

//==================================5===================================
/**
 * 	 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

 	 Calling next() will return the next smallest number in the BST.

 	 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
 	       where h is the height of the tree.
 */
class BSTIterator {
private:
	TreeNode *r;
	stack<TreeNode *> s;
public:

	BSTIterator(TreeNode *root) {
		r = root;
		TreeNode * temp = root;
		while (temp) {
			s.push(temp);
			temp = temp->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode * temp = s.top();
		s.pop();
		int result = temp->val;
		temp = temp->right;
		while (temp) {
			s.push(temp);
			temp = temp->left;
		}
		return result;
	}
};

//int main() {
//	vector<int> v;
//	Tree t;
//	TreeNode * tree = new TreeNode(3);
//	tree->left = new TreeNode(1);
//	tree->left->right = new TreeNode(2);
//	BSTIterator i = BSTIterator(tree);
//	while (i.hasNext())
//		cout << i.next();
//}
