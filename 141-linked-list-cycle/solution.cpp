/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* marker = new ListNode(0);
        ListNode* temp =head;

        while(temp){
            if(temp->next==marker){
                return true;
            }
            ListNode* nextNode = temp->next;
            temp->next = marker;
            temp = nextNode;
        }
        return false;
    }
};



// class Solution {
// public:
//     bool hasCycle(ListNode *head) {

//         if(head==NULL || head->next==NULL){
//             return false;
//         }
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast!=NULL && fast->next!=NULL){
//             slow= slow->next;
//             fast = fast->next->next;
            
//             if(slow==fast) return true;
//         }
//         return false;
//     }
// };