//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/
class Solution {
public:
    class TrieNode{
        public:
            vector<TrieNode*> m_children;
            TrieNode():m_children(2,nullptr){}
    };
    class Trie{
        public:
            TrieNode* root;
            Trie():root(new TrieNode()){}
            void insert(int n){
                TrieNode* curr = this->root;
                for(int i=30;i>=0;i--){
                    if(n & (1<<i)){
                        if(curr->m_children[1]==nullptr){
                            curr->m_children[1] = new TrieNode();
                            curr = curr->m_children[1];
                        } else{
                            curr = curr->m_children[1];
                        }    
                    } else{
                        if(curr->m_children[0]==nullptr){
                            curr->m_children[0] = new TrieNode();
                            curr = curr->m_children[0];
                        } else{
                            curr = curr->m_children[0];
                        }
                    }
                }
               
            }
            int search_xor(int n){
                int ret = 0;
                bitset<31> b(n);
                TrieNode* curr = this->root;
                string s_b = b.to_string();
                for(int i=30;i>=0;i--){
                    if(b.test(i)){
                        if(curr->m_children[0]!=nullptr){
                            ret = ret + (1<<i);
                            curr = curr->m_children[0];
                        } else{
                            curr = curr->m_children[1];
                        }
                    } else {
                        if(curr->m_children[1]!=nullptr){
                            ret = ret + (1<<i);
                            curr = curr->m_children[1];
                        } else{
                            curr = curr->m_children[0];
                        }
                    }
                }
                return ret;
            }
    };
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        Trie* obj = new Trie();
        for(int i=0;i<n;i++){
            obj->insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            int x = obj->search_xor(nums[i]);
            res = max(res,x);
        }
        return res;      
    }
};