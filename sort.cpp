#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const string& s1, const string& s2) {
	return s1 + s2 < s2 + s1;
}
class Solution {
public:
	string convert(int num) {
		string s = "";
		while (num >= 1) {
			char c = (num % 10) + '0';
			s = c + s;
			num = num / 10;
		}
		return s;
	}
	string largestNumber(vector<int>& nums) {
		vector<string> v;
		for (unsigned int i = 0; i < nums.size(); i++) {
			v.push_back(convert(nums[i]));
		}
		string s = "";
		sort(v.begin(), v.end(), comp);
		for (unsigned int i = 0; i < v.size(); i++) {
			s = v[i] + s;
		}
		return s;
	}
};

