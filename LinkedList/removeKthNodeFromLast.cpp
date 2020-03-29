//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int j = 0;
        int i=0;
        ListNode* p = head;
        while(curr && j<n){
            curr = curr->next;
            j++;
        }
        if(!curr){
            head = head->next;
            return head;
        }
        ListNode* prev =head;
        while(curr){
            if(curr->next==NULL){
                ListNode* temp = prev->next;
                prev->next = temp->next;
                curr = curr->next;
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
