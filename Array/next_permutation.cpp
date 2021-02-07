//https://www.interviewbit.com/problems/next-permutation/
int bsearch(int low,int high,int key,vector<int> &a){
    int ans = 0;
    int n = a.size();
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid<n && mid> 0  && a[mid]>key){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    int x = -1;
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            x = i;
            break;
        }
    }
    if(x!=-1){
        sort(A.begin()+x+1,A.end());
        int key = A[x];
        int pos = bsearch(x+1,n-1,key,A);
        // cerr<<"X:"<<x<<" pos:"<<pos<<" A[pos]:"<<A[pos]<<" A[x]:"<<A[x]<<endl;
        //swap
        A[x] = A[pos];
        A[pos] = key;    
    }
    else{
        sort(A.begin(),A.end());
    }
    
    return A;
}
