//https://www.geeksforgeeks.org/maximum-product-subarray/
//https://leetcode.com/problems/maximum-product-subarray/
#include <bits/stdc++.h>
using namespace std;
 int maxProduct(vector<int>& nums) {
        int ans =INT_MIN;
        int n=nums.size();
        if(n==1)
            return nums[0];
        int max_prod=1;
        int min_prod=1;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
               max_prod=nums[i]*max_prod;
                min_prod=min(nums[i]*min_prod,1);
            }
            else if(nums[i]==0){
                flag=true;
                max_prod=1;
                min_prod=1;
            }
            else{
                int temp=max_prod;
                max_prod=max(min_prod*nums[i],1);
                min_prod=temp*nums[i];
            }
            ans=max(ans,max_prod);
        }
        if(flag&& ans==1){
            ans=INT_MIN;
            for(int i=0;i<n;i++){
                ans=max(ans,nums[i]);
            }
        }
        return ans;
    }
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> inp(n);
        for(int i=0;i<n;i++){
            cin>>inp[i];
        }
        cout<<maxProduct(inp)<<endl;
    }
	//code
	return 0;
}
