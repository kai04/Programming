#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>> res;
        map<int,int> ma;
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        stack<int> s;
        for(int i=0;i<n;i++){         
                if(s.size()!=0 && s.top()>=a[i]){
                    s.push(a[i]);
                    continue;
                }
                while(s.size()!=0 && s.top()<a[i])
                {
                    res.push_back(make_pair(s.top(),a[i]));
                    ma[s.top()]=a[i];
                    s.pop();
                }
                // if(s.size()==0){
                    s.push(a[i]);
                // }
        }
        while(!s.empty()){
            ma[s.top()]=-1;
            res.push_back(make_pair(s.top(),-1));
            s.pop();
        }
        for(int i=0;i<n;i++){
            cout<<ma[a[i]]<<" ";
            //cout<<res[i].first<<" -> "<<res[i].second<<endl;
            //cout<<res[i].second<<" ";
        }
        cout<<endl;
    }
	//code
	return 0;
}
