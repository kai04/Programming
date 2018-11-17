#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

void rec(set<ll> &myset,int n,int a,int b){
     set<ll> myset1;
    while(n>=0){
        cout<<"for n :"<<n<<endl;
       
    for(int i=0;i<(myset.size());i++){
       ll x=*myset.begin();
        myset1.insert(x+a);
        myset1.insert(x+b);
        cout<<"inserting.. for x:"<<x<< " "<< x+a<<" "<<x+b<<endl;
        myset.erase(*myset.begin());
        for(set<ll>::iterator it=myset.begin();it!=myset.end();it++){
        cout<< *it <<endl;
    }
    }
        n--;
        myset=myset1;
        cout<<"---------------"<<endl;
    }
}
int main() {
    int T,a,b,n;
    set<ll> myset;
    cin>>T;
    //while(T--){
    cin>>n>>a>>b;
        myset.insert(0);
        rec(myset,n,a,b);
 /* for(set<ll>::iterator it=myset.begin();it!=myset.end();it++){
        cout<< *it <<endl;
    }*/
    //}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

