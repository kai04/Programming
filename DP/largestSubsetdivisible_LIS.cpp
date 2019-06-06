//https://leetcode.com/problems/largest-divisible-subset/submissions/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return nums;
        sort(nums.begin(),nums.end());
        vector<vector<int>> LIS(n);
        for(int i=0;i<n;i++)
            LIS[i].push_back(nums[i]);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(LIS[i].size()<LIS[j].size()+1){
                        LIS[i] = LIS[j];
                        LIS[i].push_back(nums[i]);
                    }
                    
                }
            }
        }
        /*for(int i=0;i<n;i++){
            cout<<i<<"-> ";
            for(int j=0;j<LIS[i].size();j++){
                cout<<LIS[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int ans_index=0;
        for(int i=0;i<n;i++){
            if(LIS[i].size()>LIS[ans_index].size()){
                ans_index=i;
            }
        }
        return LIS[ans_index];
        
    }
};