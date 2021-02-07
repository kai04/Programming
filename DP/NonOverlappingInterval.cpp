//https://leetcode.com/problems/non-overlapping-intervals/submissions/
class Solution {
public:
    void print_interval(vector<pair<int,int>> &I){
        cout<<"Printing....."<<endl;
        int n = I.size();
        for(int i=0;i<n;i++){
            cout<<"("<<I[i].first<<","<<I[i].second<<")"<<endl;
        }
        cout<<"-----------------------------"<<endl;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0)
            return 0;
        vector<pair<int,int>> Interval(n);
            for(int i=0;i<n;i++){
                Interval[i] = make_pair(intervals[i][0],intervals[i][1]);
            }
        sort(Interval.begin(),Interval.end());
        vector<int> p(n,-1);
        for(int j=1;j<n;j++){
            for(int i =j-1;i>=0;i--){
                if(Interval[i].second <= Interval[j].first){
                    p[j] = i;
                    break;
                }
            }
        }
        /*for(auto it:p)
            cout<<it<<" ";
        cout<<endl;*/
        // print_interval(Interval);
        vector<int> dp(n,n);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            if(p[i]==-1){
                dp[i] = i;
            }
            else{
                dp[i] = dp[p[i]]+(i-p[i]-1);
            }
        }
        /*for(auto it:dp)
            cout<<it<<" ";
        cout<<endl;*/
     return dp[n-1];   
    }
};
