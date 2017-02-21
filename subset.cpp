#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Subset {
	/**
	 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
	 *
	 * Note: The solution set must not contain duplicate subsets.
	 *
	 * 思路： 还是递归回溯，注意判断相同的元素不用重复递归， 可以先排序
	 *
	 * 另外一个思路， 每次取出结果子集，添加一个元素。如果当前元素和上一个是重复的，就从上次新添加的子集里面加元素。
	 *
	 */
public:
	vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > v;
		vector<int> temp;
		sort(nums.begin(), nums.end());
		v.push_back(temp);
		subsetsWithDup(nums, v, 0, temp);
		return v;
	}

	void subsetsWithDup(vector<int>& nums, vector<vector<int> > &v, int index,
			vector<int>& temp) {
		if (index >= nums.size()) {
			return;
		}
		for (int i = index; i < nums.size(); i++) {
			if (i == index || nums[i] != nums[i - 1]) {
				temp.push_back(nums[i]);
				v.push_back(temp);
				subsetsWithDup(nums, v, i + 1, temp);
				temp.pop_back();
			}
		}
	}

};

//int main() {
//	Subset s;
//	vector<int> nums;
//	nums.push_back(4);
//	nums.push_back(4);
//	nums.push_back(4);
//	nums.push_back(1);
//	nums.push_back(4);
//	vector<vector<int> > v = s.subsetsWithDup(nums);
//
//	for (int i = 0; i < v.size(); i++) {
//		for (int j = 0; j < v[i].size(); j++) {
//			cout << v[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

