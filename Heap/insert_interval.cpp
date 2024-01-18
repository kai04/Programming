//https://www.codingninjas.com/studio/problems/interview-shuriken-49-insert-interval_285893?count=25&search=INTERVAL&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a,vector<int> &b) {
	return a[0]<b[0];
}
vector<vector<int>> addInterval(vector<vector<int>> &intervals, int n, vector<int> &newInterval)
{
    // Write your code here
    vector<vector<int>> ans;
    int merge_low = newInterval[0];
    int merge_high = newInterval[1];
    for(int i=0;i<n;i++){
        if(intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
        } else if(intervals[i][0]>newInterval[1]){
            ans.push_back(intervals[i]);
        } else{
           merge_low = min(merge_low,intervals[i][0]);
           merge_high = max(merge_high,intervals[i][1]); 
        }
    }
    vector<int> mergeInt(2);
    mergeInt[0] = merge_low;
    mergeInt[1] = merge_high;
    ans.push_back(mergeInt);
    sort(ans.begin(),ans.end(),comp);
    return ans;

}
void printIntervals(vector<vector<int>> &a){
    // cout<<"Printing intervals ...."<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i][0]<<" "<<a[i][1]<<endl;
    }   
    // cout<<"--------------------------------"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;         
        cin>>n;
        vector<vector<int>> a(n);
        vector<int> c(2);
        for(int i=0;i<n;i++){
            vector<int> b(2);
            cin>>b[0]>>b[1];
            a[i] = b;
        }
        cin>>c[0]>>c[1];
        // printIntervals(a);
        vector<vector<int>> d = addInterval(a,n,c);
        printIntervals(d);
    }
    
    return 0;
}

