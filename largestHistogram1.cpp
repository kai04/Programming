#include <bits/stdc++.h>

using namespace std;

int largestHistogramArea(vector<int> &A){
    int n = A.size();
    vector<int> leftMin(n,-1);
    vector<int> rightMin(n,n);
    stack<int> s,r;
    // precomputing indices of first element less than
    // current element at left and right
    s.push(0);
    r.push(n-1);
    for(int i=1;i<n;i++){
        if(A[s.top()] < A[i]){
            leftMin[i] = s.top();
        }
        s.push(i);
    }

    for(int i=n-2;i>=0;i--){
        if(A[r.top()] < A[i]){
            rightMin[i] = r.top();
        }
        r.push(i);
    }


}

int main(){
    vector<int> A;
    int n;
    cin>>n;
    for(int i=0;i>n;i++){
        cin>>A[i];
    }
    int ans = largestHistogramArea(A);
    cout<<"ANS:"<<ans<<endl;
    return 0;
}