/*
 * str.cpp

 *
 *  Created on: 2017��2��22��
 *      Author: bb
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Str {
public:
	// �ҵ���һ�����ظ����ַ��������±�,ֻ��Сд��ĸ
	int firstUniqChar(string s) {
		//����˫ѭ���� Ҳ�������26��flag ����ѭ����
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

