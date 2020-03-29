//https://leetcode.com/problems/word-ladder/
#include<bits/stdc++.h>
using namespace std;
void printQueue(queue<pair<string,pair<int,int>>> q){
    cout<<"---------------------------------"<<endl;
    while(!q.empty()){
        pair<string,pair<int,int>> curr = q.front();
        q.pop();
        string s = curr.first;
        pair<int,int> p = curr.second;
        int len = p.first;
        cout<<"|";
        int prev_i = p.second;
        cout<<"("<<s<<","<<len<<")"<<"|";
    }
    cout<<endl;
}
 int bfs(map<string,int> &visited,string endWord,queue<pair<string,pair<int,int>>> &q,vector<string>& wordList){
        // cout<<"q:"<<q.size()<<endl;
        while(!q.empty()){
            printQueue(q);
            pair<string,pair<int,int>> curr = q.front();
            q.pop();
            string s = curr.first;
            pair<int,int> p = curr.second;
            int len = p.first;
            int prev_i = p.second;
            visited[s]=1;
            for(int i=0;i<s.size();i++){
                if(i!=prev_i){
                    for(int j=0;j<26;j++){
                        int c  = 'a' + j;
                        string new_s =s;
                        new_s[i] = c;
                        cout<<"word:"<<new_s<<endl;
                        if(new_s!=s && visited[new_s]==-1 && find(wordList.begin(),wordList.end(),new_s)!=wordList.end()){
                            q.push(make_pair(new_s,make_pair(len+1,i)));
                            visited[new_s]=1;
                                   if(new_s==endWord){
                                       return len+1;
                                   }
                        }
                    }
                    cout<<"=============================="<<endl;
                }
            }
        }
        return -1;
        // if(q.empty())
            return -1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,pair<int,int>>> q;
        int n =wordList.size();
        map<string,int> visited;
        // vector<int> visited(n,-1);
        //check if end word present or not 
        // vector<string>:: iterator it1 = find(wordList.begin(),wordList.end(),endWord);
        bool flag1= false,flag2= false;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord){
                flag1 = true;
            }
            if(wordList[i]==endWord){
                flag2 = true;
            }
            visited[wordList[i]]=-1;
        }
        q.push(make_pair(beginWord,make_pair(1,-1)));
           int res = bfs(visited,endWord,q,wordList); 
                return res;
            
            
        // else return -1;
        
    }


    int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    string s1,s2;
    cin>>s1>>s2;
    int res = ladderLength(s1,s2,words);
    cout<<res<<endl;
    return 0;
    }