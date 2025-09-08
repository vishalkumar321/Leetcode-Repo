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

//  BRUTE FORCE APPROACH
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        int i=0;

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
         sort(arr.begin(),arr.end());

        temp = head;
        while(temp){
            temp->val =arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};

