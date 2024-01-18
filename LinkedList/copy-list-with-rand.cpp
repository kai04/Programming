//https://leetcode.com/problems/copy-list-with-random-pointer/submissions/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        unordered_map<Node*,Node*> m;
        while(curr!=NULL){
            auto it = m.find(curr);
            if(it==m.end()){
                Node *temp = new Node(curr->val);
                if(prev!=NULL){
                    prev->next = temp;
                }
                m[curr] = temp;
                prev = temp;
                // add random pointer
                Node* rand = curr->random;
                if(rand!=NULL){
                    auto it1 = m.find(rand);
                    if(it1==m.end()){
                        Node *temp1 = new Node(rand->val);
                        m[rand] = temp1;
                    }
                    temp->random = m[rand];
                }
            } else{
                if(prev!=NULL){
                    prev->next = m[curr];
                }
                prev = m[curr];
                // add random pointer
                Node* rand = curr->random;
                if(rand!=NULL){
                    auto it1 = m.find(rand);
                    if(it1==m.end()){
                        Node *temp1 = new Node(rand->val);
                        m[rand] = temp1;
                    }
                    m[curr]->random = m[rand];
                }
            }
            curr=curr->next;
        }
        return m[head];
    }
};