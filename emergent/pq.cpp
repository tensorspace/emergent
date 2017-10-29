#include<queue>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
 	ListNode *mergeKLists(vector<ListNode *> &lists) {
		auto comp = [](const ListNode* lhs, const ListNode* rhs) { return lhs->val > rhs->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
		ListNode *dummy = new ListNode(0), *tail = dummy;

		for (auto& list : lists)
			if (list) pq.push(list);

		while (!pq.empty()) {
			tail->next = pq.top();
			tail = tail->next;
			pq.pop();
			if (tail->next) pq.push(tail->next);
		}

		return dummy->next;
	}
};

void main() {
	ListNode a(1), b(2), c(3), d(4);
	a.next = &c;
	b.next = &d;
	ListNode *p1(&a), *p2(&b);
	vector<ListNode*> vln(2);
	Solution sl;
	vln[0] = p1;
	vln[1] = p2;
	sl.mergeKLists(vln);
}