//https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
#include <bits/stdc++.h>
using namespace std;
    
int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int p = n/2;
    int ans = INT_MAX;
    int tot = accumulate(nums.begin(),nums.end(),0);
    for(int mask =0;mask<(1<<n);mask++){
        int s1 = __builtin_popcount(mask);
        if(s1==p){
            int cursum = 0;
            for(int j =0;j<n;j++){
                if(mask & (1<<j))
                    cursum+=nums[j];
            }
            int diff = tot-cursum;
            ans = min(ans,abs(cursum-diff));
        } 
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i =0;i<n;i++){
        cin>>A[i];
    }
    int ans = minimumDifference(A);
    cout<<"ANS:"<<ans;
    return 0;
}