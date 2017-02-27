/*
 * backtracking.cpp
 *
 *  Created on: 2017��2��21��
 *      Author: bb
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Back {
public:
	//================================1==============================
	/* Input: k = 3, n = 9,  (k�������Ϊn�����)
	 * Output:[[1,2,6], [1,3,5], [2,3,4]]
	 * �õݹ顣 ע���ж�ÿ������ȡֵ��Χ�� �����һ����֮��ļ�������Ҫ��ͬ�����ε����� Ҫ��֤��С�����ĺ�С�ڵ���n. ������ĿҪ��ÿ�����ֶ�С��9
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

	//======================================2===============================
	/**
	 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 �� x < 10n.

	 Example:
	 Given n = 2, return 91. (The answer should be the total numbers in the range of 0 �� x < 100, excluding [11,22,33,44,55,66,77,88,99])

	 Hint:

	 A direct way is to use the backtracking approach.Show More Hint  ֱ���ҹ��ɹ�ʽҲ������������
	 *
	 */
	int countNumbersWithUniqueDigits(int n) {
		if (n < 1) {
			return 1;
		}
		int count = 10;
		for (int i = 0; i < n - 1; i++) {
			int c = 9;
			for (int j = 0; j < i + 1; j++) {
				c = c * (10 - j - 1);
			}
			count += c;
		}
		return count;
	}

	//241. Different Ways to Add Parentheses  ���η�
	/**
	 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


	 Example 1
	 Input: "2-1-1".

	 ((2-1)-1) = 0
	 (2-(1-1)) = 2
	 */
	vector<int> diffWaysToCompute(string input) {
		return diffWaysToCompute(input, 0, input.length());
	}
	vector<int> diffWaysToCompute(string input, int start, int end) {
		vector<int> result;
		bool flag = true;
		for (int i = start; i < end; i++) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
				flag = false;
				vector<int> left = diffWaysToCompute(input, start, i);
				vector<int> right = diffWaysToCompute(input, i + 1, end);
				for (unsigned int j = 0; j < left.size(); j++) {
					for (unsigned int k = 0; k < right.size(); k++) {
						if (input[i] == '+') {
							result.push_back(left[j] + right[k]);
						} else if (input[i] == '-') {
							result.push_back(left[j] - right[k]);
						} else {
							result.push_back(left[j] * right[k]);
						}
					}
				}
			}
		}
		if (flag) {
			int x = 0;
			for (int i = start; i < end; i++) {
				x = 10 * x + (input[i] - '0');
			}
			result.push_back(x);
		}
		return result;
	}
};

//int main() {
//	Back b;
//	vector<int> c = b.diffWaysToCompute("10+5");
//	for (int i = 0; i < c.size(); i++) {
//		cout << c[i] << endl;
//	}
//}
