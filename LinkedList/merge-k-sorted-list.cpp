//https://leetcode.com/problems/merge-k-sorted-lists/description/
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
 void printListNode(ListNode* t){
     cout<<"Printing Link list:"<<endl;
     while(t!=NULL){
         cout<<t->val<<" -> ";
         t = t->next;
     }
     cout<<endl<<"-----------------------------"<<endl;
 }
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        ListNode* res;
        vector<ListNode*> pointers;
        int n = lists.size();
        if(n==0){
            return NULL;
        }
        bool flag = false;
        // cout<<"Printing Lists ......."<<endl;
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL){
                flag = true; 
                // cout<<"List:"<<i<<endl;
                // printListNode(lists[i]);
                pointers.push_back(lists[i]);    
            }
        }
        // cout<<"========================"<<endl;
        n = pointers.size();
        if(n==0){
            return NULL;
        }
        int j=-1;
        int k = 0;
        ListNode* prev;
        while(flag){
            flag = false;
            int value = INT_MAX;
            for(int i=0;i<n;i++){
                if(pointers[i]!=NULL){
                    int v = pointers[i]->val;
                    if(v<value){
                        j = i;
                        value = v;
                    }
                    flag = true;    
                }
            }
            if(pointers[j]!=NULL){
                ListNode *curr = new ListNode(pointers[j]->val);
                pointers[j] = pointers[j]->next;
                if(k==0){
                    res = curr;
                    prev = curr;
                } else{
                    prev->next = curr;
                    prev = curr;
                }
            }
            // cout<<"Printing Final list k:"<<k<<endl;
            // printListNode(res);
            k++; 
        }
        return res;
    }
};