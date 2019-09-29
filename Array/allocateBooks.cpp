
#include<bits/stdc++.h>
using namespace std;

bool isAllocationPossible(vector<int> &A,int sum,int val){
    int n = A.size();
    int cnt = 1;
    int curr_sum = 0;
    for(int i=0;i<n;i++){
        if(curr_sum+A[i]<=sum){
           curr_sum=curr_sum+A[i]; 
        }
        else{
            curr_sum = A[i];
            cnt++;
        }
    }
    if(cnt>val){
        return false;
    }
    return true;
}
int binarysearch(int l,int h,int val,vector<int> &A){
    //base case
    if(l>h)
        return l;
    int mid  = l+(h-l)/2;
    bool flag1= isAllocationPossible(A,mid,val);
    bool flag2= isAllocationPossible(A,mid+1,val);
    // int y = isAllocationPossible(A,mid+1);
    // cout<<"low:"<<l<<" high:"<<h<<" mid:"<<mid<<" flag1:"<<flag1<<" flag2:"<<flag2<<endl;
    if(flag1 && !flag2){
        return mid;
    }
    else if(flag1 && flag2){
        return binarysearch(l,mid-1,val,A);
    }
    else{
        return binarysearch(mid+1,h,val,A);
    }
}

int books(vector<int> &A, int B) {
    int n = A.size();
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int total_sum = 0;
    if(n<B)
        return -1;
    for(int i=0;i<n;i++){
        maxi = max(maxi,A[i]);
        mini = min(mini,A[i]);
        total_sum  = total_sum + A[i];
    }
    int low = maxi;
    //int high = total_sum/B  ;
    int high = total_sum  ;
    int ans =  binarysearch(low,high,B,A);
    return ans;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = books(a,m);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}