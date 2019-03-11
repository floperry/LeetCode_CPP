#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(0);
		ListNode *p = l1, *q = l2, *curr = head;
		int carry = 0;
		while (p != NULL || q != NULL) {
			int x = (p != NULL) ? p->val : 0;
			int y = (q != NULL) ? q->val : 0;
			int sum = x + y + carry;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			if (p != NULL) p = p->next;
			if (q != NULL) q = q->next;
		}
		if (carry > 0) {
			curr->next = new ListNode(carry);
		}
		return head->next;
	}
};

int main() {
	std::vector<int> num1 = { 2, 4, 3 }, num2 = { 5, 6, 4 };

	std::cout << "num1: ";
	for (int i : num1) {
		std::cout << i;
	}
	std::cout << std::endl;

	std::cout << "num2: ";
	for (int i : num2) {
		std::cout << i;
	}
	std::cout << std::endl;

	Solution solution;
	ListNode *l1 = new ListNode(num1[0]), *l2 = new ListNode(num2[0]);
	ListNode *p = l1, *q = l2;
	
	for (int i = 1; i < num1.size(); i++) {
		p->next = new ListNode(num1[i]);
		p = p->next;
	}
	for (int i = 1; i < num2.size(); i++) {
		q->next = new ListNode(num2[i]);
		q = q->next;
	}
	
	ListNode *sum = solution.addTwoNumbers(l1, l2);
	std::cout << "sum: ";
	while (sum != NULL) {
		std::cout << sum->val;
		sum = sum->next;
	}
	std::cout << std::endl;

	system("PAUSE");
	return 0;
}