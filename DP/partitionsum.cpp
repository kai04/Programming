    #include <bits/stdc++.h>
    using namespace std;
    int subset_sum(vector<int> a,int s,int n,vector<vector<int>> &dp){
        if(s<0)
            return 0;
        if(s==0)
            return 1;
        if(n<0) {
                return 0;
        }
        if(dp[s][n]==-1)
            {
                dp[s][n]=(subset_sum(a,s,n-1,dp) || subset_sum(a,s-a[n],n-1,dp));
            }
            return dp[s][n];
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            vector<int> a(n);
            int sum=0;
            for(int i=0;i<n;i++){
                cin>>a[i];
                sum+=a[i];
            }
            if(sum%2==0){
                //sort(a.begin(),a.end());
                sum=sum/2;
                vector<vector<int>> dp(sum+1,vector<int>(n+1,-1));
                if(subset_sum(a,sum,n-1,dp)==1){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        //code
        return 0;
    }