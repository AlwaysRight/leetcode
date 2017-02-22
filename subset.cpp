#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Subset {

public:
	//=============================1==========================
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
	//==============================2======================================

	/**
	 *
	 * Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

	 Example:
	 Input: [4, 6, 7, 7]
	 Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
	 Note:
	 The length of the given array will not exceed 15.
	 The range of integer in the given array is [-100,100].
	 The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
	 *
	 */

	vector<vector<int> > findSubsequences(vector<int>& nums) {
		vector<vector<int> > result;
		vector<int> tmp;
		findSubsequences(nums, result, tmp, 0);
		return result;
	}

	void findSubsequences(vector<int>& nums, vector<vector<int> >& res, vector<int>& tmp,  int start){
		if(start >= nums.size()){
			return;
		}
		for(int i = start; i < nums.size(); i++){
			bool isReapeted = false;
			for(int j = start; j < i; j++){
				//重复元素的判断
				if(nums[j] == nums[i]){
					isReapeted = true;
				}
			}
			if((start == 0 ||  (nums[i] >= tmp[tmp.size() - 1])) && (!isReapeted)){
				// 注意第一个元素也要判断重复
				tmp.push_back(nums[i]);

				if(tmp.size() > 1){
					res.push_back(tmp);
				}
				findSubsequences(nums, res, tmp, i + 1);
				tmp.pop_back();
			}
		}
	}
};

int main() {
	Subset s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	vector<vector<int> > v = s.findSubsequences(nums);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

