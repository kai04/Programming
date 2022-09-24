//https://leetcode.com/problems/jump-game/submissions/
//https://www.interviewbit.com/problems/jump-game-array/
//https://leetcode.com/problems/jump-game-ii/submissions/
class Solution {
public:
    bool canJump(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[n-1] = 1;
        int minIndexPossible = n-1;
        for(int i=n-2;i>=0;i--){
            if(i+A[i]>=minIndexPossible){
                minIndexPossible = i;
                dp[i] = 1;
            }
        }
        return dp[0];
    }
};


