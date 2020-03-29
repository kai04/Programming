#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	if(a.first != b.first)
		return (a.first < b.first);
	return (a.second < b.second);
}

int main() {
   int n;
    cin>>n;
    vector<pair<int,int> > time(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        time[i].first=x;//start
        time[i].second=y;//end
    }
    sort(time.begin(),time.end(),compare);

   // for(int i=0;i<n;i++)
    //	cout<<time[i].first<<" "<<time[i].second<<endl;
    int t1=-1,t2=-1;
    for(int i=0;i<n;i++){
        if(t1<time[i].first)
            t1=time[i].second;
        else if(t2<time[i].first)
            t2=time[i].second;
        else{
            cout<<"NO\n";
            return 0;
        }

    }
    cout<<"YES\n";


    return 0;
}