//https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
    int isPossible(vector<int> &a, int sum){
        bool ret = true;
        int curr_sum=0;
        int p = 1;
        for(int i=0;i<a.size();i++){
            // if(p>k){
            //     ret = false;
            //     break;
            // }
            if(a[i]>sum) return a.size()+1;
            if(curr_sum+a[i]<=sum){
                curr_sum = curr_sum+a[i];
            } else{
                curr_sum=a[i];
                p++;
            }
        }
        return p;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int curr_sum=0;
        for(auto it:nums){
            curr_sum+=it;
        }
        int l=0,h=curr_sum;
        int ans = curr_sum;
        while(l<h){
            int m = l + (h-l)/2;
            int res = isPossible(nums, m);
            // cout<<"l:"<<l<<" h:"<<h<<" m:"<<m<<" res:"<<res<<" k:"<<k<<endl;
            if(res<=k){
                h = m;
                ans = min(m,ans);
            } else{
                l = m+1;
            }
        }
        return ans;
    }
};