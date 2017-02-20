/*
 * solution.cpp
 *
 *  Created on: 2017年2月20日
 *      Author: bb
 */
#include <iostream>
#include <vector>
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

class Solution {
public:
	//根据中序和后序遍历写出二叉树
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
		cout << "root:" << rootval << endl;
		if (root == NULL) {
			root = new TreeNode(rootval);
		} else if (side == 0) { //left sub tree
			root->left = new TreeNode(rootval);
		} else {
			root->right = new TreeNode(rootval);
			cout << rootval << endl;
		}
		int left = 0;
		for (int i = ib; i <= ie; i++) {
			if (inorder[i] == rootval) {
				left = i;
				break;
			}
		}
		cout << "left" << left << endl;
		if (left > ib) {
			buildTree(inorder, ib, left - 1, postorder, pb, left - ib - 1 + pb,
					root->left, 0);
		}
		if (ie > left) {
			buildTree(inorder, left + 1, ie, postorder, pb + left - ib, pe - 1,
					root->right, 1);
		}
	}

	//生成螺旋形矩阵
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > v(n, vector<int>(n, 0));
		int num = 1;
		int row = 0, column = 0;
		while (num <= n * n) {
			for (int j = 0; j < n; j++) {
				if (v[row][j] == 0) {
					v[row][j] = num++;
					column = j;
				}
			}
			if (num > n * n) {
				break;
			}
			for (int i = 0; i < n; i++) {
				if (v[i][column] == 0) {
					v[i][column] = num++;
					row = i;
				}
			}
			if (num > n * n) {
				break;
			}
			for (int j = n - 1; j >= 0; j--) {
				if (v[row][j] == 0) {
					v[row][j] = num++;
					column = j;
				}
			}
			if (num > n * n) {
				break;
			}
			for (int i = n - 1; i >= 0; i--) {
				if (v[i][column] == 0) {
					v[i][column] = num++;
					row = i;
				}
			}
		}
		return v;
	}

	/* Input: k = 3, n = 9,  (k个数相加为n的情况)
	 * Output:[[1,2,6], [1,3,5], [2,3,4]]
	 * 用递归。 注意判断每个数的取值范围， 例如第一个数之后的几个数都要不同，依次递增， 要保证最小的数的和小于等于n. 另外题目要求每个数字都小于9
	 */
	vector<vector<int> > combinationSum3(int k, int n) {
		vector<vector<int> > v;
		vector<int> temp;
		combinationSum3(k, n, v, temp);
		return v;
	}
	void combinationSum3(int k, int n, vector<vector<int> > & v,
			vector<int>& temp) {
		if (k == 1) {
			int last = temp[temp.size() - 1];
			if (n > last && n <= 9) {
				temp.push_back(n);
				v.push_back(temp);
				temp.pop_back();
			}
		} else {
			int i = 1;
			if (temp.size() > 0) {
				i = temp[temp.size() - 1] + 1;
			}
			for (; (2 * i + k - 1) * k <= 2 * n && i <= 9; i++) {
				temp.push_back(i);
				combinationSum3(k - 1, n - i, v, temp);
				temp.pop_back();
			}
		}
	}

};
int main() {
	Solution s;
	vector<vector<int> > v = s.combinationSum3(2, 18);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

