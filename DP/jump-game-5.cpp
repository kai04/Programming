//https://leetcode.com/problems/jump-game-v
class Solution {
public:
    vector<int> find_all_index(int i, int n,int d, vector<int>& a){
        vector<int> res;
        for(int j=i+1;j<n &&j-i<=d;j++){
            if(a[j]<a[i]){
                res.push_back(j);
            } else{
                break;
            }
        }

        for(int j=i-1;j>=0 && i-j<=d;j--){
            if(a[j]<a[i]){
                res.push_back(j);
            } else{
                break;
            }
        }
        return res;        
    }
    void printAll(int i, vector<int> &r){
        cout<<"Printing .... Index:"<<i<<endl;
        for(int q:r){
            cout<<q<<" ";
        }
        cout<<endl<<"-----------------------------"<<endl;
    }
    int dfs(int i, int n, vector<int> &dp, vector<int>& a, int d){
        vector<int> t = find_all_index(i, n, d, a);
        // printAll(i, t);
        if(t.size()==0){
            dp[i] = 1;
            return dp[i];
        }

        //memoization
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=0;j<t.size();j++){
            if(dp[t[j]]==-1){
                dp[i] = max(dp[i], 1+dfs(t[j], n, dp, a, d));
            } else {
                dp[i] = max(dp[i], 1+dp[t[j]]);
            }
        }
        return dp[i];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int res = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==-1){
                dp[i] = dfs(i, n, dp, arr, d);
            }
        }
        for(int x: dp){
            // cout<<x<<" ";
            res = max(res,x);
        } 
        // cout<<endl;
        return res;   
    }
};