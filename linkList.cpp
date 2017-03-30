#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:

	// 每隔K个数 翻转链表的k个元素, 不够k个元素保持不变
	// e.g. 1-2-3-4-5 k = 2, => 2-1-4-3-5
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k < 2) {
			return head;
		}
		int len = 0;
		ListNode* n = head;
		while (n) {
			n = n->next;
			len++;
		}
		ListNode* lastHead = head;
		ListNode* newHead = head;
		ListNode* pre = head;
		ListNode* current = head->next;
		int fir = 1;
		while (k <= len) {
			int i = 1;
			while (i < k) {
				ListNode * tmp = current;
				current = current->next;
				tmp->next = pre;
				pre = tmp;
				i++;
			}
			if (fir) {
				head = pre;
				fir = 0;
			} else {
				lastHead->next = pre;
				lastHead = newHead;
			}
			len = len - k;
			if (len >= k) {
				newHead = current;
				pre = current;
				current = current->next;
			}
		}
		lastHead->next = current;
		return head;
	}

	//递归解法
	ListNode* reverseKGroup2(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k < 2) {
			return head;
		}
		int len = 0;
		ListNode* n = head;
		while (n) {
			n = n->next;
			len++;
		}
		head = reverseKGroup(head, k, len);
		return head;

	}

	ListNode* reverseKGroup(ListNode* head, int k, int len) {
		if (k > len) {
			return head;
		}
		ListNode* pre = head;
		ListNode* cur = pre->next;
		int i = 1;
		while (i < k) {
			ListNode* tmp = cur;
			cur = cur->next;
			tmp->next = pre;
			pre = tmp;
			i++;
		}
		head->next = reverseKGroup(cur, k, len - k);
		return pre;
	}

};


int main() {
	Solution s;
	ListNode * head = new ListNode(3);
	head->next = new ListNode(4);
	head = s.reverseKGroup(head,2);
	while (head) {
		cout << head->val << ", ";
		head = head->next;
	}
}
