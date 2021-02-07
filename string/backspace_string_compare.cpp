//https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<S.length();i++){
            if(S[i]=='#' && !s1.empty()){
                s1.pop();
            }
            else{
                if(S[i]!='#')
                    s1.push(S[i]); 
            }
        }
        
        for(int i=0;i<T.length();i++){
            if(T[i]=='#' && !s2.empty()){
                s2.pop();
            }
            else{
                if(T[i]!='#')
                    s2.push(T[i]); 
            }
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        string p1;
        string p2;
        while(s1.size()){
            char c1 = s1.top();
            char c2 = s2.top();
            s1.pop();
            s2.pop();
            if(c1!=c2){
                return false;
            }
            p1 = string(c1,1) + p1;
            p2 = string(c2,1) + p2;
            
        }
        // cout<<p1<<" "<<p2<<endl;
        return true;
        
    }
};
