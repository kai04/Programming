//https://www.hackerrank.com/contests/amazon-arrays/challenges/largest-possible-number/problem
//https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
#include <bits/stdc++.h>
using namespace std;
bool compare(int xin,int yin){
    int x=xin;
    int y=yin;
    bool flag=false;
    int k=floor(log10(x));
    int l=floor(log10(y));
    while(k>=0 && x>0 && y>0 && l>=0){
        int p=x/pow(10,k);
        int q=y/pow(10,l);
        x=x%(int)pow(10,k);
        y=y%(int)pow(10,l);
        // cout<<p<<" "<<q<<endl;
        k--;
        l--;
        if(p<q){
            return true;
        }
        else if(p>q){
            return false;
        }
        else{
            if(p==q && k<0){
                // cout<<"p:"<<p<<" q:"<<q<<" l:"<<l<<" (y/pow(10,l-1))):"<<(y/pow(10,l))<<endl;
                if(xin/pow(10,floor(log10(xin)))>(y/pow(10,l)))
                    return false;
                else 
                    return true;
            }
            if(p==q && l<0){
                // cout<<"p:"<<p<<" q:"<<q<<" k:"<<k<<" (x/pow(10,k-1))):"<<(x/pow(10,k))<<endl;
                if(yin/pow(10,floor(log10(yin)))>(x/pow(10,k)))
                    return true;
                else 
                    return false;    
            }
            continue;
        }
        
    }
    return flag;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),compare);
    // for(auto it:a)
    //     cout<<it<<" ";
    // cout<<endl;

    string res="";
    for(int j=a.size()-1;j>=0;j--)
        res+=to_string(a[j]);
    cout<<res<<endl;
    

    return 0;
}
