//https://leetcode.com/problems/accounts-merge/description/
#include<bits/stdc++.h>
using namespace std;
void make_set(int v, int p, string &name, vector<int> &parent, vector<int> &rank, unordered_map<int, string> &account_name){
        parent[v] = p;
        rank[v] = 0; 
        account_name[v] = name;
}

int find_set(int v, vector<int> &parent, vector<int> &rank) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent, rank);
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank, unordered_map<int, string> &account_name){
    int p_u = find_set(u, parent, rank);
    int p_v = find_set(v, parent, rank);
    if(p_u != p_v){
        if(rank[p_u]< rank[p_v]){
            parent[p_v] = p_u;
            account_name[p_v] = account_name[p_u]; 
        } else if(rank[p_u]> rank[p_v]){
            parent[p_u] = p_v;
            account_name[p_u] = account_name[p_v];
        } else{
            parent[p_v] = p_u;
            account_name[p_v] = account_name[p_u];
            rank[p_u]++;
        }
    }
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    int cnt = 0;
    vector<int> parent(1001);
    vector<int> rank(1001);
    unordered_map<string,int> mymap;
    unordered_map<string,bool> added;
    unordered_map<int,int> setmap;
    unordered_map<int,string> account_name;
    for(int i=0;i<n;i++){
        make_set(i,i,accounts[i][0],parent,rank,account_name);
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            if(mymap.find(accounts[i][j])==mymap.end()){
                mymap[accounts[i][j]] = i;
                added[accounts[i][j]] = false;
            } else{
                int a1 = mymap[accounts[i][j]];
                union_set(a1,i,parent,rank,account_name); 
            }
        }
    }

    vector<vector<string>> results;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            if(!added[accounts[i][j]]){
                int x = find_set(mymap[accounts[i][j]],parent, rank);
                added[accounts[i][j]] = true;
                if(setmap.find(x)==setmap.end()){
                    vector<string> new_s;
                    new_s.push_back(accounts[i][j]);
                    results.push_back(new_s);
                    setmap[x] = results.size()-1;                
                } else{
                    int ix = setmap[x];
                    results[ix].push_back(accounts[i][j]);
                }    
            }
            
        }
        
    }

    for(int i=0;i<results.size();i++){
        int x = find_set(mymap[results[i][0]],parent, rank);
        int ix = setmap[x];
        sort(results[ix].begin(),results[ix].end());
        string name = account_name[x];
        results[ix].insert(results[ix].begin(),name);
    }

    return results;

}

vector<string> split(string s,char delimeter){
    istringstream ss(s);
    vector<string> tokens;
    string token;
    while(getline(ss,token,delimeter)){
        tokens.push_back(token);
    }
    return tokens;
}
void printInput(vector<vector<string>> &input){
    cout<<"Printing ......"<<endl;
    for(auto a1:input){
        for(auto a2:a1){
            cout<<a2<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------------------------"<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> accounts;
    vector<vector<string>> results;
    for(int i=0;i<n;i++){
        string input;
        cin>>input;
        vector<string> ss =  split(input,',');
        accounts.push_back(ss);
    }
    // printInput(accounts);

    results = accountsMerge(accounts);
    printInput(results);
    return 0;
}
