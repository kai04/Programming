//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n,0);
        bool nozero = true;
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]==0){
                    nozero = false;
                    counts[i] = 1;
                }
                    
            }
            else{
                if(nums[i]==0){
                    nozero = false;
                    counts[i] = counts[i-1]+1;
                }
                else{
                    counts[i] = counts[i-1];
                }
            }
        }
        if(nozero){
            return n-1;
        }
        
        int i=0,j=0;
        int  res = -1;
        while(i<=j && j<n){
            int count0;
            if(i==0){
                count0 = counts[j];
            }
            else{
                count0 = counts[j] - counts[i-1];
            }
            
            if(count0>1){
                while(count0>1){
                    if(i==0){
                        count0 = counts[j];
                    }
                    else{
                        count0 = counts[j] - counts[i-1];
                    }
                    // cout<<"i:"<<i<<" j:"<<j<<" count 0:"<<count0<<endl;
                    if(count0>1){
                        i++;
                    }
                }
            }
            if(count0==0)
                res = max(res,j-i+1);
            else
                res = max(res,j-i);
            // cout<<"i:"<<i<<" j:"<<j<<" RES:"<<res<<endl;
            j++;
        }
        return res;
        
        
    }
};