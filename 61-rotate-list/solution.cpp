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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k==0){
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = head;
        int count = 1;

        while(temp->next){
            count++;
            temp = temp->next;
        }
            k = k%count;
            int linkToBroke = count-k;

        for(int i=1; i<linkToBroke; i++){
            prev = prev->next;
        }

        temp->next = head;
        head = prev->next;
        prev->next = NULL;
        return head;
    }
};