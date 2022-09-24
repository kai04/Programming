//https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
//https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;
map<int,int> nextsmaller_fromLeft(vector<int> a){
    int n=a.size();
    map<int,int> ma;
    stack<int> s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){         
        if(s.size()!=0 && a[s.top()]<=a[i]){
            s.push(i);
            continue;
        }
        while(s.size()!=0 && a[s.top()]>a[i])
            {
                ma[s.top()]=i;
                s.pop();
            }
            // if(s.size()==0){
                s.push(i);
            // }
        }
        while(!s.empty()){
            ma[s.top()]=-1;
            s.pop();
        }
        return ma;
}

map<int,int> nextsmaller_fromRight(vector<int> a){
    int n=a.size();
    map<int,int> ma;
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){         
        if(s.size()!=0 && a[s.top()]<=a[i]){
            s.push(i);
            continue;
        }
        while(s.size()!=0 && a[s.top()]>a[i])
            {
                ma[s.top()]=i;
                s.pop();
            }
            // if(s.size()==0){
                s.push(i);
            // }
        }
        while(!s.empty()){
            ma[s.top()]=n;
            s.pop();
        }
        return ma;
}

int main() {
    
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    map<int,int> mLeft=nextsmaller_fromLeft(a);
	    map<int,int> mRight=nextsmaller_fromRight(a);
	   /* for(auto it:mLeft)
	        cout<<a[it.first]<<" -> "<< it.second<<endl;
	   cout<<"-------------------------"<<endl;
	   for(auto it:mRight)
	        cout<<a[it.first]<<" -> "<< it.second<<endl;*/
	    int res=INT_MIN;
	    for(int i=0;i<n;i++){
	        int indexLeft=mLeft[i];
	        int indexRight=mRight[i];
	        int k=(indexRight-1)-(indexLeft+1)+1;
	       // cout<<"i:"<<i<<" indexLeft:"<<indexLeft<<" indexRight:"<<indexRight<<" k:"<<k<<" Temp res:"<<a[i]*k<<endl;
	        res=max(res,(k*a[i]));
	    }
	    cout<<res<<endl;
	}
	return 0;
	
}
