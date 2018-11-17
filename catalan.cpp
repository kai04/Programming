#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
//static int res=0;
int catalan(vector<int> &c,int n){
    int p,q;
    //res=0;
    c[0]=1;
    c[1]=1;
    //if(n<0)
    //    return 0;
    if(n==0||n==1)
        return 1;
    if(c[n]==-1){
        int res=0;
    for(int i=1;i<n;i++){
        p=catalan(c,i);
        q=catalan(c,n-i);
       
        res+=p*q; 
       //cout<<"i:"<<i<<" p:"<<p<<" q:"<<q<<" n:"<<n<<" res:"<<res<<endl;
    }
        c[n]=res;
        //cout<<"n:"<<n<<" c[n]:"<<c[n]<<endl;
    }
    
    return c[n];
    
}
int main() {
    int n;
    cin>>n;
    vector<int> c(n+1,-1);
    
    cout<<catalan(c,n)<<endl;
    vector<int>::iterator it = c.begin()+1;
    c.erase(c.begin());
    c.begin()=it;
    cout<<"result:"<<endl;
    for(auto it:c)
        cout<<it<<" ";
    cout<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

