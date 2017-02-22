/*
 * str.cpp

 *
 *  Created on: 2017年2月22日
 *      Author: bb
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Str {
public:
	// 找到第一个不重复的字符，返回下标,只有小写字母
	int firstUniqChar(string s) {
		//可以双循环， 也可以设个26的flag 两次循环。
		int flag[26] = {0};
		for(int i = 0; i < s.length(); i++){
			flag[s[i]-'a']++;
		}
		for(int i = 0; i < s.length(); i++){
			if(flag[s[i]-'a'] == 1){
				return i;
			}
		}
		return -1;
	}
};

//int main(){
//	Str s;
//	cout << s.firstUniqChar("121");
//}

