#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int shortestTSPdistance(vector<vector<int> > dist) {  
    int n = dist.size();  
    int lim = 1 << n;  
    // int dp[lim][n]; 
    //initialize all city cost to visit is infinity 
    // memset(dp, INF, sizeof(dp));
    vector<vector<int> > dp(lim,vector<int>(n,INF));  
    for (int i = 0; i < n; i++) {  
        dp[0][i] = dist[0][i];    // base case of visiting just 1 city  
    }  
    for (int mask = 1; mask < lim; mask++) {  
        for (int i = 0; i < n; i++) { 
        	//if last city is not visited in mask then continue
        	// because by definition last city should be visited in current mask 
            if (mask & (1 << i) == 0) {      
                continue;  
            }  
            for (int j = 0; j < n; j++) { 
            	int x=(mask & (1 << j));
            	//if curr city is not visited yet in mask
                if ((mask & (1 << j)) == 0) {  
                	
                	// cout<<"j:"<<j<<" mask:"<<mask<<" mask && (1 << j):"<<x<<endl;
                    continue;  
                }  
                //unvisit curr city in mask and call this othermask
                int otherMask = mask ^ (1 << j);  
                dp[mask][i] = min(dp[mask][i], dp[otherMask][j] + dist[i][j]);
                // cout<<"i:"<<i<<" j:"<<j<<" mask:"<<mask<<" (mask && (1 << j)):"<<x<<" othermask:"<<otherMask<<" dp[otherMask][j]:"<<dp[otherMask][j]<<" dp[mask][i]:"<<dp[mask][i]<<endl;  
            }  
        }  
    }  
    int ans = INF;  
    for (int i = 0; i < n; i++) {  
        ans = min(ans, (dp[lim - 1][i])+dist[i][0]);  
    } 
    /*
    for (int mask = 0; mask < lim; mask++) {  
        for (int l = 0; l < n; l++) {
        	cout<<dp[mask][l]<<" ";
        }
        cout<<endl; 
    }*/
    return ans;  
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector< vector<int> > dist(n+1,vector<int>(n+1));
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				if(i==j){
					dist[i][j]=0;
				}
				else{
					int x;
					cin>>x;
					dist[i][j]=x;
				}
			}
		}
		int ans = shortestTSPdistance(dist);
		cout<<ans<<endl;
	}

	return 0;
}
