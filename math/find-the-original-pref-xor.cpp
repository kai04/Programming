//https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n,0);
        ans[0] = pref[0];
        for(int i=1;i<n;i++){
            int a = pref[i] ^ pref[i-1];
            ans[i] = a; 
        }
        return ans;
    }
};