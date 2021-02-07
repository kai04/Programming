//https://leetcode.com/problems/contiguous-array/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i] = -1;
            }
        }
        
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0){
                ans = max(ans,(i+1));
            }
            if(m.find(sum)!=m.end()){
                ans = max(ans,i-m[sum]);
            }else{
                m[sum] = i;    
            }
            
        }      
        return ans;
    }
};