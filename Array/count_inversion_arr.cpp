// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;
typedef long long int lli;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   
    
    lli inversionCountHelper(vector<ll> &A, int l, int h){
        int m = l + (h-l)/2;
        int sz = h-l+1;
        if(sz<=1){
            return 0;
        } else if(sz==2){
            if(A[l]>A[h]){
                int v = A[l];
                A[l] = A[h];
                A[h] = v;
                return 1;
            }
        }
        lli leftInv = inversionCountHelper(A, l,m);
        lli rightInv = inversionCountHelper(A,m+1,h);

        lli cnt=0;
        vector<ll> t(h-l+1);
        int k =0,i=l,j=m+1;

        while(i<=m && j<=h && k<h-l+1){
            if(A[i]<=A[j]){
                t[k++] = A[i++];
            } else{
                cnt = cnt + (m-i+1);
                t[k++] = A[j++];
            }
        }
        if(i>m){
            while(k<h-l+1){
                t[k++] = A[j++];
            }
        } else{
            while(k<h-l+1){
                t[k++] = A[i++];
            }
        }

        for(int i=l,p=0;i<=h;i++,p++){
            A[i] = t[p];
        }
        return (leftInv + rightInv + cnt);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        //base case

        vector<ll> A(arr, arr+N);
        // Your Code Here
        return inversionCountHelper(A,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends