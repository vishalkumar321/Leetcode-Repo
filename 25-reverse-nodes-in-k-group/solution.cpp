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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int count =0; 
        ListNode* temp =head;
        ListNode* prev =NULL;
        ListNode* front =NULL;
        ListNode* traverseEnd =NULL;
        ListNode* traverseStart =NULL;
        bool m = true;

        while(temp){
            count++;
            temp = temp->next;
        }
        if(!head || !head->next || count<k) return head;

        temp = head;
        while(count>=k){
            traverseEnd = temp;
        for(int i=0; i<k; i++){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
            if(m){
                head = prev;
                m=false;
            }
            else{
                traverseStart->next = prev;
            }
            traverseStart = traverseEnd;
            count = count-k;
        }
        traverseEnd->next = temp;
        
        return head;
    }
};