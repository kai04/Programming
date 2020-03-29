//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>
using namespace std;


    int lengthOfLongestSubstring(string s) {
        map<char,int> count;
        int n = s.length();
        if(n<=1){
            return n;
        }
        int i=0,j=0;
        int ans=INT_MIN;
        int curr_len=0;
        while(i<n && j<n&& i<=j){
            if(count.find(s[j])!=count.end()){
                if(count[s[j]]==0){
                    count[s[j]]=1;
                    ans = max(ans,j-i+1);
                    j++;
                }
                else{
                    count[s[i]]--;
                    i++;
                }
            }
            else{
                count[s[j]]=1;
                ans = max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }

int main(){
   string s;
   cin>>s;
   int ans = lengthOfLongestSubstring(s);
   cout<<"ANS:"<<ans<<endl;
    return 0;
}