//https://leetcode.com/problems/count-numbers-with-unique-digits/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans=0;
        
        //int n;
        //cin>>n;
        vector<int> dp(11,0);
        dp[0]=1;
        dp[1]=9;
        for(int i=2;i<=n;i++){
            dp[i]=(10-i+1)*dp[i-1];
        }
        for(int i=0;i<=n;i++){
            ans+=dp[i];
        }
        return ans;
    }
};

int main(){
Solution *a = new Solution();
int n;
cin>>n;
cout<<a->countNumbersWithUniqueDigits(n)<<endl;
return 0;
}
