 #include<bits/stdc++.h>
using namespace std;   

    string frequencySort(string s) {
        map<char,int> m;
        for(char ch:s)
          m[ch]++;
        vector<pair<int,char>> p;
        for(auto it:m){
            p.push_back(make_pair(it.second,it.first));
        }
        cerr<<"h1"<<endl;
        sort(p.begin(),p.end());
        cerr<<"h2"<<endl;
        string res = "";
        for(int i = p.size();i>=0;i--){
            int j = p[i].first;
            cerr<<"i:"<<i<<" char:"<<p[i].second<<" cnt:"<<j<<endl;
            while(j>0){
                res.push_back(p[i].second);
                j--;
            }
        }
        cerr<<"h3"<<" RES:"<<res<<endl;
        return res;
    }


int main(){
    string x;
    cin>>x;
    //int res = solve(x,0);
    string res = frequencySort(x);
    cout<<"RES:"<<res<<endl;
    return 0;
}