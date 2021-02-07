//https://leetcode.com/contest/biweekly-contest-30/problems/stone-game-iv/
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        vector<int> squares;
        for(int i=1;i*i<=n;i++){
            squares.push_back(i*i);
            dp[i*i] = true;
        }
        for(int i=1;i<=n;i++){
          for(int j=0;j<squares.size();j++){
              if(i>squares[j] && !dp[i-squares[j]])
              {  dp[i] = true;
                 break;
              }
          }
        }
        return dp[n];
    }
};