#include <bits/stdc++.h>
using namespace std;

int get_first(vector<bool> &a,int iter){
    int cnt = 0;
    int st = -1;
    for(int i=1;i<=100000;i++){
        if(a[i]==true){
            cnt++;
        }
        if(cnt==iter+1){
            st = i;
            break;
        }
    }
    return st;
}

int get_second(vector<bool> &a,int iter,int fst){
    int cnt = 0;
    int diff = -1;
    for(int i=fst+1;i<=100000;i++){
        if(a[i]==true){
            cnt++;
        }
        if(cnt==iter+1){
            diff = i;
            break;
        }
    }
    return diff;
}
int solve(int n)
{
    int loc=n;
    int gap=2;
    while(true)
    {
        if(loc % gap ==0)
            return 0;
        if(loc < gap)
            return 1;
        loc=loc-loc/gap;
        gap++;
    }
}
int main() {
    int t;
    cin>>t;
    /*vector<bool> sieve(100001,true);
    for(int iter=1;iter<=10000;iter++){
        int fst = get_first(sieve,iter);
        int scnd = get_second(sieve,iter,fst);
        if(fst!=-1 && scnd!=-1){
            int d = scnd - fst;
            // cout<<"first:"<<fst<<" scnd:"<<scnd<<" diff:"<<d<<endl;
            for(int i = fst;i<=100000;i = i+d){
                sieve[i] = false;
            }    
        }
        else{
            break;
        }
        
    }*/
    
    while(t--){
        int n;
        cin>>n;
        // cout<<sieve[n]<<endl;
        cout<<solve(n)<<endl;
    }
    //code
    return 0;
}