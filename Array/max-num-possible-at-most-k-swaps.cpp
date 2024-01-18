//https://www.codingninjas.com/studio/problems/find-maximum-number-possible-by-doing-at-most-k-swaps_1169469?ieSlug=tower-research-capital-interview-experience-by-ishmeher-singh-ahuja-off-campus-mar-2020&ieCompany=tower-research-capital&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
using namespace std;
void printData(unordered_map<int,deque<int>> mp, vector<int> a){
    cout<<"Printing New vector...."<<endl;
    for(auto it:a){
        cout<<it<<" "; 
    }
    cout<<endl<<"-----------------------"<<endl;

    cout<<"Printing New deque...."<<endl;
    for(auto it:mp){
        cout<<it.first<<" -> ";
        deque<int> d = it.second;
        while(!d.empty()){
            cout<<d.front()<<" ";
            d.pop_front();
        } 
        cout<<endl;
    }
    cout<<endl<<"****************************"<<endl;
    

}
vector<int> maxNumberKSwaps(vector<int> &num, int k){
    // Write your code here.
    vector<int> v = num;
    int n = num.size();
    sort(v.begin(),v.end(),greater<int>());
    unordered_map<int,deque<int>> mp;
    for(int i=0;i<n;i++){
        mp[num[i]].push_front(i);
    }
    for (int i = 0; i < n && k>0; i++) {
        cout<<"i:"<<i<<" num[i]:"<<num[i]<<" v[i]:"<<v[i]<<endl;
        if(num[i]!=v[i]){
            if(mp.find(v[i])!=mp.end()){
                if(mp[v[i]].size()>0){
                    int ix = mp[v[i]].front();
                    int temp = num[i];
                    num[i] = v[i];
                    num[ix] = temp; 
                    mp[v[i]].pop_front();
                    mp[temp].pop_back();
                    mp[v[i]].push_back(i);
                    mp[temp].push_back(ix);
                    k--;
                }
            }
        }
        printData(mp,num);
        cout<<"==============================="<<endl;
    }
    return num;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> ans = maxNumberKSwaps(a,k);
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}