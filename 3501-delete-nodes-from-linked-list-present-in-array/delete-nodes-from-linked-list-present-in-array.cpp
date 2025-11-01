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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        while (head && valuesToRemove.count(head->val)) {
            ListNode* temp = head;
            head = head->next;
        }

        if (!head)
            return nullptr;

        ListNode* current = head;
        while (current->next) {
            if (valuesToRemove.count(current->next->val)) {
                ListNode* temp = current->next;
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
