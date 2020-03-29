#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll>dp(100001,0);
ll setsum(vector<ll> vec){
    ll sum1=0;
    for(vector<ll>::iterator it=vec.begin();it!=vec.end();it++){
       sum1+=(*it); 
    }
    return sum1;
}
ll compute(ll N,vector<ll>A){
    vector<ll>last(0);
    int i;
    for(i=N-1;i>=0;i--){
        if(A[i]>=0){
            //cout<<"i:"<<i<<" pushing.."<<A[i]<<endl;
            last.push_back(A[i]);
        }
        else
            break;
    }
    //last.pop_back();
    /*cout<<"before.."<<endl;
     cout<<"----------------"<<endl;
     for(vector<ll>::iterator it=last.begin();it!=last.end();it++){
            cout<<*it<<" ";
    }
    cout<<endl;*/
    //cout<<"i:"<<i<<endl;
     ll final_sum=0;
    if(A[i]<0){
    ll setsum1=setsum(last);
    int size_l=last.size();
    while((setsum1+(A[i]*(size_l+1)))>0){
        //cout<<"i:"<<i<<" pushing.."<<A[i]<<endl;
        last.push_back(A[i]);
        setsum1+=A[i];
        size_l=last.size();
        i--;
    }
   
    for(int j=i;j>=0;j--){
         //cout<<"i:"<<j<<" adding singlegton.."<<A[j]<<endl;
        final_sum+=A[j];
    }
    }
    /*cout<<"After.."<<endl;
    cout<<"----------------"<<endl;
     for(vector<ll>::iterator it=last.begin();it!=last.end();it++){
            cout<<*it<<" ";
    }
    cout<<endl;*/
   //cout<<"setsum:"<<setsum(last)<<" size:"<<last.size()<<endl;
    final_sum+=setsum(last)*last.size();
    return final_sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,T,x;
    cin>>T;
    while(T--){
      cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>x;
        A[i]=x;
    }
    sort(A.begin(),A.end());
    /*cout<<"Input.."<<endl;
    cout<<"----------------"<<endl;
     for(vector<ll>::iterator it=A.begin();it!=A.end();it++){
            cout<<*it<<" ";
    }
     cout<<endl;*/
    cout<<compute(N,A)<<endl;
    /*for(int i=0;i<=N;i++){
        cout<<dp[i]<<endl;
    }*/
    }
    return 0;
}

