/*
 * solution.cpp
 *
 *  Created on: 2017年2月20日
 *      Author: bb
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//==========================1=================================
	//生成螺旋形矩阵, 四个方向循环， 判断转向时的条件
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

	//==================================2======================================
	/**
	 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

	 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

	 Find the minimum element.

	 You may assume no duplicate exists in the array.

	 题目的意思应该是只从一个点旋转一次。
	 */
	int findMin(vector<int>& nums) {
		if (nums[0] <= nums[nums.size() - 1]) {
			return nums[0];
		}
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			cout << left << ", " << right <<endl;
			if (left == right || nums[left] < nums[right]) {
				break;
			}
			int mid = left + (right - left) / 2;
			if (nums[mid] >= nums[left] && nums[mid] >= nums[right]) {
				left = mid + 1;
			} else if (nums[mid] <= nums[left] && nums[mid] <= nums[right]) {
				right = mid;
			}
		}
		return nums[left];
	}

};

int main() {
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	Solution s;
	cout << s.findMin(v) << " @";
}

