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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* oddHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* evenTail = nullptr;

        int index = 1;
        ListNode* curr = head;

        while (curr) {
            if (index % 2 == 1) {
                if (!oddHead) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            } else {
                if (!evenHead) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }
            index++;
            curr = curr->next;
        }

        if (evenTail) {
            evenTail->next = nullptr;
        }
        oddTail->next = evenHead;
        return oddHead;
    }
};