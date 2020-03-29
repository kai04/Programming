/*
[[1,100],[11,22],[1,11],[2,12]]
*/
#include<bits/stdc++.h>
using namespace std;

     bool startsort(vector<int> p1,vector<int> p2){
        if(p1[0]<p2[0])
            return true;
        else if(p1[0]==p2[0]){
            if(p1[1]<=p2[1])
                return true;
            return false;
        }
        return false;
    }

    void PrintTiming(vector<pair<int,pair<int,char>>> t){
        int n = t.size();
        for(int i=0;i<n;i++){
            pair<int,pair<int,char>> p = t[i];
            cout<<"timing:"<<p.first<<" Interval no:"<<p.second.first<<" timing type:"<<p.second.second<<endl;
        }
    }
    bool mysort(pair<int,pair<int,char> > p1,pair<int,pair<int,char> > p2){
        if(p1.first<p2.first)
            return true;
        else if(p1.first==p2.first){
            pair<int,char> temp = p1.second;
            if(temp.second=='e')
                return true;
            else 
                false;
        }
        return false;
    }
    void previous_non_overlapping_interval(vector<vector<int>>& intervals,vector<int> &opt){
        int n = intervals.size();
        opt.resize(n);
        vector<pair<int,pair<int,char>>> timing;
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            pair<int,pair<int,char>> p1 = make_pair(start,make_pair(i,'s'));
            pair<int,pair<int,char>> p2 = make_pair(end,make_pair(i,'e'));
            timing.push_back(p1);
            timing.push_back(p2);
        }
        // cout<<"h1:"<<endl;
        sort(timing.begin(),timing.end(),mysort);
        // cout<<"h2:"<<endl;
        PrintTiming(timing);
        int last_end = -1;
        for(int i=0;i<2*n;i++){
            // cout<<""
            pair<int,pair<int,char>> p1 = timing[i];
            if(p1.second.second=='s'){
               opt[p1.second.first] = last_end; 
            }
            else{
                last_end = p1.second.first;
            }
        }
    }
    int maxNonOverlappingInterval(int interval,vector<int> &opt,vector<int> &dp){
        //base case
        
        if(interval<0)
            return 0;
        //memoization
            if(dp[interval]!=-1)
                return dp[interval];
        // cout<<"interval:"<<interval<<endl;
        dp[opt[interval]] = maxNonOverlappingInterval(opt[interval],opt,dp);
        dp[interval-1] = maxNonOverlappingInterval(interval-1,opt,dp);
        dp[interval] = max(1+dp[opt[interval]],dp[interval-1]);
        return dp[interval];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),startsort);
        vector<int> opt;
        previous_non_overlapping_interval(intervals,opt);
        for(auto it:opt)
            cout<<it<<" ";
        cout<<endl;
        //max non overlapping interval
        vector<int> dp(n,-1);
        dp[0] = 1;
        int non_overlapping_interval = 0; 
        non_overlapping_interval = maxNonOverlappingInterval(n-1,opt,dp);
        cout<<"h3:"<<endl;
        return n-non_overlapping_interval;
    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
        
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i][0] = x;
        a[i][1] = y;
    }

    int res = eraseOverlapIntervals(a);
    cout<<"RES:"<<res<<endl;
}