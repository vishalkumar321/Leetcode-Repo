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
#include <cmath>
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int count = 0;
        int ans = 0;

        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            count++;
        }

        temp = head;
        for (int i = count - 1; i >= 0; i--) {
            if (temp->val == 1) {
                ans = ans + pow(2, i);
            }
            temp = temp->next;
        }
        return ans;
    }
};