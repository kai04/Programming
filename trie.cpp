/*["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]*/
//https://leetcode.com/problems/implement-trie-prefix-tree/submissions/
class TrieNode
{
public:
    TrieNode *next[26];
    bool isEndofWord;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        isEndofWord = b;
    }
};
class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *currNode = root;
        for(int i=0;i<word.length();i++){
            if(currNode->next[word[i]-'a']!=NULL){
                //char found
                TrieNode *nextNode = currNode->next[word[i]-'a'];
                currNode = nextNode;
            }
            else{
                // char not found
                TrieNode *newnode = new TrieNode();
                currNode->next[word[i]-'a'] = newnode;
                currNode = newnode;   
            }
        }
        currNode->isEndofWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *currNode = root;
        for(int i=0;i<word.length();i++){
            if(currNode->next[word[i]-'a']!=NULL){
                //char found
                TrieNode *nextNode = currNode->next[word[i]-'a'];
                currNode = nextNode;
            }
            else{
                // char not found
                return false;   
            }
        }
        if(currNode->isEndofWord)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode *currNode = root;
        for(int i=0;i<word.length();i++){
            if(currNode->next[word[i]-'a']!=NULL){
                //char found
                TrieNode *nextNode = currNode->next[word[i]-'a'];
                currNode = nextNode;
            }
            else{
                // char not found
                return false;   
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */