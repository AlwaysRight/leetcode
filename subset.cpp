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
	 * ˼·�� ���ǵݹ���ݣ�ע���ж���ͬ��Ԫ�ز����ظ��ݹ飬 ����������
	 *
	 * ����һ��˼·�� ÿ��ȡ������Ӽ������һ��Ԫ�ء������ǰԪ�غ���һ�����ظ��ģ��ʹ��ϴ�����ӵ��Ӽ������Ԫ�ء�
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

