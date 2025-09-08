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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0); // Dummy node for the result
        ListNode* curr = head;
        int carry = 0;

        // Traverse both lists and add corresponding digits
        while (l1 != NULL || l2 != NULL || carry > 0) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;  // Carry for next iteration
            int digit = sum % 10;  // Current digit

            curr->next = new ListNode(digit); // Add digit to the result
            curr = curr->next;
        }

        return head->next; // Return the result list, skipping the dummy node
    }
};
