//count all cells with sum of neighbours is prime
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<int> plist(0);
int binarysearch(vector<int> &vec,int p,int low,int high){
    if(high>=low){
    int mid=(low+high)/2;
    if(vec[mid]==p)
        return mid;
    else if(p>vec[mid])
        {
        return binarysearch(vec,p,mid+1,high);
        }
        else{
            return binarysearch(vec,p,low,mid-1);
        }
    }

        return -1;
    
   }
   //this function generte prime numbers
void preComputePrime(int n){
    bool a[n+1]={false};
    for(int i=2;i<n+1;i++){
        if(a[i]==false){
            plist.push_back(i);
            a[i]=true;
            int p =a[i];
            for(int j=i;j<n+1;j=j+i){
                a[j]=true;
            }
        }
    }
    sort(plist.begin(),plist.end());
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    preComputePrime(400);
     /*for(auto it:plist){
        cout<<it<<" ";
    }
    cout<<endl;*/
    int g[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    int count1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p,q,r,s;
            //p
            if(i-1<0)
                p=0;
            else
                p=g[i-1][j];
            //q
            if(i+1>=n)
                q=0;
            else
                q=g[i+1][j];
            //r
            if(j-1<0)
                r=0;
            else
                r=g[i][j-1];
            //s
            if(j+1>=n)
            { 
                s=0;
            }
            else{
                //cout<<"i:"<<i<<" j+1:"<<j+1<<endl;
                s=g[i][j+1];
            }
            //------------------------//
            int sum1=p+q+r+s;
            //cout<<"i:"<<i<<" j:"<<j<<" g[i][j]:"<<g[i][j]<<" sum1:"<<sum1<<" p:"<<p<<" q:"<<q<<" r:"<<r<<" s:"<<s<<endl;
            if(binarysearch(plist,sum1,0,plist.size()-1)!=-1)
                count1++;
            
            
            
        }
    }
    cout<<count1<<endl;
   
    
    return 0;
}
