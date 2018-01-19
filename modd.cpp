#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin >> n>>m;
    vector<int> a(n);
    vector<int> odd(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            if(a[i]%2==1)
                odd[i]=1;
            else
                odd[i]=0;
        }
        else{
        if(a[i]%2==1)
            odd[i]=odd[i-1]+1;
        else
            odd[i]=a[i-1];
        }
    }
    int i=0,j=0;
    int oddc=0;
    int count1=0;
    while(i<=j&&j<n){
        //cout<<"i:"<<i<<" j:"<<j<<" oddc:"<<oddc<<" count:"<<count1<<endl;
        if(a[j]%2==1){
            oddc++;
        }
        
        if(oddc==m){
            count1++;
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            if(a[i]%2==0)
            {
             j--;   
            }
            oddc--;
            i++;
        }
        j++;
        //cout<<"i:"<<i<<" j:"<<j<<" oddc:"<<oddc<<" count:"<<count1<<endl;
        //cout<<"=================================="<<endl;
    }
    cout<<count1<<endl;
    return 0;
}
    