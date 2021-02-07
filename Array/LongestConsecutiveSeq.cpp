//https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]] = 1;
        }
        int max_chain = 0;
        for(int i=0;i<n;i++){
            int curr_chain = 1;
            int x = nums[i];
            if(m.find(x-1)==m.end()){
                while(m.find(x+1)!=m.end()){
                    curr_chain++;
                    x = x+1;
                }    
            }
            max_chain = max(curr_chain,max_chain);
        }
        return max_chain;
    }
};
