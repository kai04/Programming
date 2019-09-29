//https://www.interviewbit.com/problems/hotel-bookings-possible/
#include<bits/stdc++.h>
using namespace std;
bool mysort(pair<int,pair<int,char>> p1,pair<int,pair<int,char>> p2){
    if(p1.first<p2.first){
        return true;
    }
    else if(p1.first==p2.first){
        if(((p1.second).first)==(p2.second).first)
            return false;
        else if((p1.second).second == ')')
            return true;
        else if((p2.second).second == ')')
            return false;
        else
            return true;
    }
    return false;
}

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,pair<int,char>>> a;
    for(int i=0;i<arrive.size();i++){
        if(arrive[i]!=depart[i]){
            a.push_back(make_pair(arrive[i],make_pair(i,'(')));
            a.push_back(make_pair(depart[i],make_pair(i,')')));
        }
    }
    // PrintInterval(a);
    sort(a.begin(),a.end(),mysort);
    // PrintInterval(a);
    stack<char> s;
    int maxsize=0;
    bool flag =true;
    for(int i=0;i<a.size();i++){
        if(s.empty()){
            s.push((a[i].second).second);
        }
        else if((a[i].second).second=='(' && s.top()=='('){
            s.push((a[i].second).second);
        }
        else if((a[i].second).second==')' && s.top()=='('){
            s.pop();
        }
        else{
            cout<<"something wrong"<<endl;
            cout<<"top:"<<s.top()<<" curr elt:"<<(a[i].second).second<<endl;
        }
        maxsize = s.size();
        // cout<<"i:"<<i<<" size:"<<maxsize<<endl;
        // PrintStack(s);
        if(maxsize>K){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){

    return 0;
}
