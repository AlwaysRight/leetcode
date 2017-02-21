/*
 * solution.cpp
 *
 *  Created on: 2017��2��20��
 *      Author: bb
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

	//���������ξ���, �ĸ�����ѭ���� �ж�ת��ʱ������
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



};

