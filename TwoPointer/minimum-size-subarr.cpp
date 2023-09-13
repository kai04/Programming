//https://leetcode.com/problems/minimum-size-subarray-sum/description/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int n = nums.size();
        int i=0,j=-1,sum=0;
        while(i<n && j<n){
            // cout<<"prev i:"<<i<<" j:"<<j<<" sum:"<<sum<<" ans:"<<ans<<endl;
            if(sum<target||sum<=0){
                j++;
                if(j<n)
                    sum +=nums[j];
            } else{
                while(i<n && sum>=target){
                    // cout<<"next1 i:"<<i<<" j:"<<j<<" sum:"<<sum<<" ans:"<<ans<<endl;
                    ans = min(ans,(j-i+1));
                    sum-=nums[i];
                    i++;
                }
            }
            // cout<<"next i:"<<i<<" j:"<<j<<" sum:"<<sum<<" ans:"<<ans<<endl;
            // cout<<"-------------------------------"<<endl;
        }
        if(j==n){
            j--;
                while(i<n && sum>=target){
                    // cout<<"next2 i:"<<i<<" j:"<<j<<" sum:"<<sum<<" ans:"<<ans<<endl;
                    ans = min(ans,(j-i+1));
                    sum-=nums[i];
                    i++;
                }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};