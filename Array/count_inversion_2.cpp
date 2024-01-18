//https://www.codingninjas.com/studio/problems/count-inversions_615
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
void printArr(long long *arr, ll l, ll r){
    cout<<"Printing arr from ["<<l<<","<<r<<"]"<<endl;
    for(ll i=l;i<=r;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"========================"<<endl;
}
ll merge_sort(ll l, ll r,vector<ll> &res, long long *arr){
    //base cases
    if (l >= r) {
        // cout<<"l:"<<l<<" r:"<<r<<" ret:"<<0<<endl;
        return 0;
    }
    
    ll m = (l+r)/2;
    ll left = merge_sort(l, m, res,arr);
    ll right = merge_sort(m+1, r, res,arr);
    ll i=l,j=m+1,k=l;
    ll ret = 0;
    while(i<=m && j<=r){
        if(arr[i]>arr[j]){
            ret= ret+ (m-i+1);
            res[k] = arr[j];
            j++;
            k++;
        } else{
            res[k] = arr[i];
            i++;
            k++;
        }
    }
    if(i>m){
        while(j<=r){
            res[k] = arr[j];
            k++;
            j++;
        }
    } else{
        while(i<=m){
            res[k] = arr[i];
            k++;
            i++;
        }
    }
    for(int i=l;i<=r;i++){
        arr[i] = res[i];
    }
    // printArr(arr,l,r);
    return (left+right+ret);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    vector<ll> res(n);
    ll ans = merge_sort(0, n-1, res, arr);
    return ans;
}

int main(){
    int m;         
    cin>>m;
    ll *arr = (ll*)malloc((m+1)*sizeof(ll));
    for(int i=0;i<m;i++){
        cin>>arr[i];        
    }
    ll ans = getInversions(arr,m);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}
