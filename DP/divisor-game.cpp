//https://leetcode.com/problems/divisor-game/submissions/


class Solution {
public:
    bool divisorGame(int N) {
        vector<vector<int>> divisor(1001);
        for(int i=1;i<=1000;i++){
            for(int j=i;j<=1000;j=j+i){
                if(j!=i)
                    divisor[j].push_back(i);                
            }
        }
        vector<bool> dp(N+1,false);
        dp[1]=false;
        dp[2]=true;
        dp[3]=false;
        /*cout<<"divisor of 7:"<<endl;
        for(int j=0;j<divisor[7].size();j++){
            cout<<divisor[7][j]<<" ";
        }
        cout<<endl;*/
        for(int i=4;i<=N;i++){
            for(int j=0;j<divisor[i].size();j++){
                if(i-divisor[i][j]>=0)
                    dp[i] = dp[i] || ! dp[i-divisor[i][j]] ;   
            }
        }
        return dp[N];
    }
};
