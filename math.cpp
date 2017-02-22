/*
 * math.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: bb
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	//=========== 1=================
	/**
	 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

	 * For example:
	 * Given n = 13,
	 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
	 */
	int countDigitOne(int n) {
		if (n < 1) {
			return 0;
		}
		if (n < 10) {
			return 1;
		}
		vector<int> digits;
		while (n > 0) {
			digits.push_back(n % 10);
			n = n / 10;
		}
		int count = 0;
		int i;
		for (i = 0; i < digits.size(); i++) {
			cout << digits[i] << "~" << endl;
			int digit = digits[i];
			int flag;
			if (digit < 1) {
				flag = 1;
			}
			int c = 1;
			for (int j = 0; j < digits.size(); j++) {
				cout << ":" << digits[j] << endl;
				if (j != i) {
					c = c * (digits[j] + 1);
				}
			}
			count += c;
		}
		return count;
	}

	//===============================2=====================
	//是否是整数的平方。二分查找
	bool isPerfectSquare(int num) {
		if (num == 1) {
			return true;
		}
		long top = num / 2;
		long down = 1;
		long mid = 0;
		long number = (long)(num);
		while (down <= top) {
			mid = (top + down) / 2;
			long result = mid * mid;
			if (result == number) {
				return true;
			} else if (result < number) {
				down = mid + 1;
			} else {
				top = mid - 1;
			}
		}
		return false;
	}
};

//int main() {
//	Solution s;
//	cout << s.isPerfectSquare(808201);
//}
