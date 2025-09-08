/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> p;

        for (auto list : lists) {
            if (list != nullptr) {
                p.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!p.empty()) {
            ListNode* smallest = p.top();
            p.pop();

            current->next = smallest;
            current = current->next;

            if (smallest->next) {
                p.push(smallest->next);
            }
        }
        return dummy->next;
    }
};