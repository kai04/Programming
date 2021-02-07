//https://leetcode.com/problems/maximum-length-of-pair-chain/
static bool compare(vector<int> p1,vector<int> p2){
    if(p1.size()>0 && p2.size()>0 && p1[0]<=p2[0]){
        return true;
    }
    return false;
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> lis(n,1);
        sort(pairs.begin(),pairs.end(),compare);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
        }
        int ans = 1;
        for(int i=0;i<n;i++){
            ans = max(ans,lis[i]);
        }
        return ans;
    }
};