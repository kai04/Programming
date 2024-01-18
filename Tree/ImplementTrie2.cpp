#include <bits/stdc++.h> 
using namespace std;
class TrieNode{
    public:
    vector<TrieNode*> m_children;
    bool m_is_word;
    int m_prefix_cnt;
    int m_word_cnt;
    TrieNode() : m_children(26,nullptr),m_is_word(false), m_prefix_cnt(0), m_word_cnt(0){}
};
class Trie{
    public:
    TrieNode* root;
    Trie(): root(new TrieNode()){
        // Write your code here.
    }

    void printTrie(){
        TrieNode* prev = nullptr;
        stack<pair<TrieNode*,char>> s;
        s.push({root,'*'});
        while(!s.empty()){
            pair<TrieNode*,char> t = s.top();
            TrieNode* curr = t.first;
            char c1 = t.second;
            for(int i=0;i<26;i++){
                char c = 'a'+i;
                if(curr->m_children[c]!=nullptr){
                    if(curr==root){
                        cout<<"ROOT Current:["<<c<<"] curr pref count:["<<curr->m_prefix_cnt<<"] curr word count:["<<curr->m_word_cnt<<"] curr is word:["<<curr->m_is_word<<"] "<<endl;
                    } else {
                        cout<<"Current:["<<c<<"] curr pref count:["<<curr->m_prefix_cnt<<"] curr word count:["<<curr->m_word_cnt<<"] curr is word:["<<curr->m_is_word<<"] "<<endl;
                        
                    }
                    s.push({curr->m_children[c],c});
                }
            }
            prev = curr;
            s.pop();
        }
    }
    void insert(string &word){
        // Write your code here.
        int n = word.length();
        TrieNode* curr = this->root;
        TrieNode* prev = nullptr;
        // cout<<"Inserting.... word:"<<word<<" Trie Root:"<<this->root<<endl;
        for(int i=0;i<n;i++){
            int t1 = word[i]-'a';
            if(curr-> m_children[word[i]-'a']==nullptr){
                curr-> m_children[word[i]-'a'] = new TrieNode;
            }
            curr->m_prefix_cnt = curr->m_prefix_cnt + 1;
            // if(curr==this->root){
            //     cout<<"Current is ROOT:"<<curr<<" next char:"<<word[i]<<" next Pointer:"<< curr->m_children[word[i]-'a']<<" Index:"<<t1<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
            // } else{
            //     cout<<"Current is not ROOT:"<<curr<<" prev:"<<prev<<" next char:"<<word[i]<<" next Pointer:"<< curr->m_children[word[i]-'a']<<" Index:"<<t1<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
            // }
            prev = curr;
            curr = curr->m_children[word[i]-'a'];
        }
        curr->m_is_word = true;
        curr->m_word_cnt = curr->m_word_cnt+1;
        curr->m_prefix_cnt = curr->m_prefix_cnt + 1;
        // cout<<"Current is not ROOT:"<<curr<<" prev:"<<prev<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
        // cout<<"******************************"<<endl;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        int n = word.length();
        TrieNode* curr = root;
        // cout<<"countWordsEqualTo.... word:"<<word<<" Trie Root:"<<this->root<<endl;
        for(int i=0;i<n;i++){
            if(curr!=nullptr){
                // cout<<"Current:"<<curr<<" next char:"<<word[i]<<" next Pointer:"<< curr->m_children[word[i]-'a']<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
                curr = curr->m_children[word[i]-'a'];
            } else{
                return 0;
            }
        }
        // cout<<"Current is not ROOT:"<<curr<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
        // cout<<"******************************"<<endl;
        return curr->m_word_cnt;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int n = word.length();
        TrieNode* curr = this->root;
        // cout<<"countWordsStartingWith.... word:"<<word<<" Trie Root:"<<this->root<<endl;
        for(int i=0;i<n;i++){
           if(curr!=nullptr){
                // cout<<"Current:"<<curr<<" next char:"<<word[i]<<" next Pointer:"<< curr->m_children[word[i]-'a']<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
                curr = curr->m_children[word[i]-'a'];
            } else{
                return 0;
            }
        }
        // cout<<"Current:"<<curr<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
        // cout<<"******************************"<<endl;
        return curr->m_prefix_cnt;
    }

    void erase(string &word){
        // Write your code here.
        int n = word.length();
        TrieNode* curr = this->root;
        // cout<<"Erasing.... word:"<<word<<" Trie Root:"<<this->root<<endl;
        for(int i=0;i<n;i++){
            if(curr!=nullptr){
                curr->m_prefix_cnt = curr->m_prefix_cnt - 1;
                // cout<<"Current:"<<curr<<" next char:"<<word[i]<<" next Pointer:"<< curr->m_children[word[i]-'a']<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
                curr = curr->m_children[word[i]-'a'];
            }
        }
        curr->m_word_cnt = curr->m_word_cnt-1;
        if(curr->m_word_cnt==0){
            curr->m_is_word = false;
            curr->m_prefix_cnt = curr->m_prefix_cnt - 1;
            // cout<<"Current:"<<curr<<" next Pointer:"<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
            delete curr;
        } else{
            curr->m_prefix_cnt = curr->m_prefix_cnt - 1;
            // cout<<"Current:"<<curr<<" next Pointer:"<<" prefix cnt:"<<curr->m_prefix_cnt<<" word count:"<<curr->m_word_cnt<<endl;
        }
        // cout<<"******************************"<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int op;
        cin>>op;
        Trie* obj = new Trie();
        for(int i=0;i<op;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(s1=="insert"){
                obj->insert(s2);
            } else if(s1=="countWordsEqualTo"){
                int ans = obj->countWordsEqualTo(s2);
                cout<<"countWordsEqualTo:"<<s2<<" ["<<ans<<"]"<<endl;
            }  else if(s1=="countWordsStartingWith"){
                int ans = obj->countWordsStartingWith(s2);
                cout<<"countWordsStartingWith:"<<s2<<" ["<<ans<<"]"<<endl;
            }  else if(s1=="erase"){
                obj->erase(s2);
            }        
        }
        cout<<"=================================="<<endl;
    }
    return 0;
}
