//https://leetcode.com/problems/next-greater-element-ii/description/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        vector<int> ret(n,-1);
        // vector<int> nge(n,-1);
        stack<pair<int,int>> s;
        for(int i=0;i<2*n;i++){
            if(s.empty()){
                s.push(make_pair(nums[i],i));
            } else{
                pair<int,int> t = s.top();
                if(s.top().first>nums[i]){
                    s.push(make_pair(nums[i],i));                    
                } else {
                    while(!s.empty() && s.top().first<nums[i]){
                        if(s.top().second<n)
                            ret[s.top().second] = nums[i];
                        s.pop();
                    }
                    s.push(make_pair(nums[i],i));
                }
            }
        }
        return ret;
    }
};