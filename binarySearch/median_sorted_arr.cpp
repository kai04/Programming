//https://www.interviewbit.com/problems/median-of-array/
#include<bits/stdc++.h>
using namespace std;
/*
A=[1,3,4,7,10,12]
B=[2,3,6,15]
c=[1,2,3,3,4|,6,7,10,12,15]
[l1,l2,r1,r2]
[1,3,4][7,10,12]
[2,3] [6,15]
------------------------------
A=[1,3,4,10,12]
B=[2,3,6,15]
c=[1,2,3,3,4,|6,10,12,15]
*/
double calculate_median(int l1,int r1,int l2,int r2,int n1,int n2){
    int x = ceil((n1+n2)/2);
    if((n1+n2)%2==0){
        return (double)(max(l1,l2)+min(r1,r2))/2.0;
    } else{
        return (double)max(l1,l2);
    }
}

double find_median(const vector<int> &A, const vector<int> &B){
    int n1 = A.size();
    int n2 = B.size();
    //base case 
    if(n1==0){
        int k = n2/2;
        if(n2%2==0){
            return (double)(B[k]+B[k-1])/2.0;
        } else{
            return (double)B[k];
        }
    } 
    if(n2==0){
        int k = n1/2;
        if(n1%2==0){
            return (double)(A[k]+A[k-1])/2.0;
        } else{
            return (double)A[k];
        }
    }
    if(n1>n2){
        return find_median(B,A);
    }
  
    int x = ceil((double)(n1+n2)/2.0);
    cout<<"N1:"<<n1<<" N2:"<<n2<<" X:"<<x<<endl;
    int low = 0,high = n1;
    int l1=INT_MIN,r1=INT_MAX,l2=INT_MIN,r2=INT_MAX;
    while(low<=high){
        l1=INT_MIN,r1=INT_MAX,l2=INT_MIN,r2=INT_MAX;
        int mid1 = low + (high-low)/2;
        int mid2 = x-mid1;
        if(mid1-1>=0 && mid1-1<n1)
            l1 = A[mid1-1];
        if(mid1>=0 && mid1<n1)
            r1 = A[mid1];
        if(mid2-1>=0 && mid2-1<n2)
            l2 = B[mid2-1];
        if(mid2>=0 && mid2<n2)
            r2 = B[mid2];

         cout<<"x:"<<x<<" mid1:"<<mid1<<" mid2:"<<mid2<<" low:"<<low<<" high:"<<high<<" l1:"<<l1<<" r1:"<<r1<<" l2:"<<l2<<" r2:"<<r2<<endl;
        //best case scenario
        if(l1<=r2 && l2<=r1){
            break;
        } else if(l1>r2){
            high =  mid1-1;
        } else {
            low = mid1+1;
        }
    }
    return calculate_median(l1,r1,l2,r2,n1,n2);
}

double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
        A=[1,3,4,7,10,12]
        B=[2,3,6,15]
    */
    double ans = find_median(A,B);
    return ans;
    
}

int main(){
    int m,n;         
    cin>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];        
    }
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];        
    }
    double d1 = findMedianSortedArrays(a,b);
    cout<<"Median:"<<d1<<endl;
    cout<<"=============================="<<endl;
    double d2 = solve(a,b);
    cout<<"Median:"<<d2<<endl;
    return 0;
}
