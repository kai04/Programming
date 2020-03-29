#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        //vector<int> jid(n);
        //vector<int> jdead(n);
        //vector<int> jprofit(n);
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int jid,jdead,jprofit;
            cin>>jid>>jdead>>jprofit;
            s.insert(make_pair(jprofit,jdead));
            //cin>>jid[i]>>jdead[i]>>jprofit[i];
        }
        int intvl=0;
        int cost=0;
        int jcount=0;
        for(auto it=s.rbegin();it!=s.rend();it++){
            int profit=it->first;
            int deadline=it->second;
            //cout<<"deadline:"<<deadline<<" profit:"<<profit<<endl;
            if(deadline>intvl){
                cost+=profit;
                jcount++;
                intvl++;
            }
            
        }
        cout<<jcount<<" "<<cost<<endl;
    }
	//code
	return 0;
}
