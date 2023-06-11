//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if(n==1)
            return 0;
        vector<int> lmax(n,INT_MIN);
        vector<int> rmax(n,INT_MIN);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        for(int i = 1; i<n;i++){
            lmax[i] = max(lmax[i-1],height[i]);
        }
        for(int i = n-2; i>=0;i--){
            rmax[i] = max(rmax[i+1],height[i]);
        }
        for(int i = 0; i<n;i++){
            int t_i = min(lmax[i],rmax[i]);
            int h_i = t_i - height[i];
            if(h_i>0){
                ans +=h_i;
            }
        }
        return ans;
    }
};