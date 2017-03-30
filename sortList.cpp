#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head) {
			return NULL;
		}
		ListNode* left = head;
		ListNode* right = head, *tail = head;
		ListNode* pre = NULL;
		while (tail && (tail->next != NULL)) {
			tail = tail->next->next;
			pre = right;
			right = right->next;
		}
		if (pre) {
			pre->next = NULL;
		}
		if (left == right) {
			return left;
		}
		left = sortList(left);
		right = sortList(right);
		return merge(left, right);
	}

	ListNode* merge(ListNode* l, ListNode* r) {
		ListNode* head = NULL;
		ListNode* cur = NULL;
		while (l && r) {
			ListNode * nnext;
			if (l->val < r->val) {
				nnext = l;
				l = l->next;
			} else {
				nnext = r;
				r = r->next;
			}
			if (head == NULL) {
				head = nnext;
				cur = head;
			} else {
				cur->next = nnext;
				cur = nnext;
			}
		}
		while (r) {
			if (head == NULL) {
				head = r;
				cur = head;
			} else {
				cur->next = r;
				cur = r;
			}
			r = r->next;
		}
		while (l) {
			if (head == NULL) {
				head = l;
				cur = head;
			} else {
				cur->next = l;
				cur = l;
			}
			l = l->next;
		}
		return head;
	}

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */

	ListNode* insertionSortList(ListNode* head) {
		if (!head) {
			return head;
		}
		ListNode*p, *q, *pprev;
		p = head->next;
		pprev = head;
		while (p != NULL) {
			ListNode* qprev = NULL;
			for (q = head; (q->val <= p->val) && (q != p);
					qprev = q, q = q->next)
				;
			if (q == p) {
				pprev = p;
				p = p->next;
				continue;
			}
			pprev->next = p->next;
			ListNode* insert = p;
			p = p->next;

			if (qprev != NULL) {
				qprev->next = insert;
			} else {
				head = insert;
			}
			insert->next = q;

		}
		return head;
	}

};

