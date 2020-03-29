#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int bsearch(ll low,ll high,ll key){
     cout<<"low:"<<low<<" high:"<<high;
     if(low==high){
         return low;
     }

    ll mid = low + ((high-low)/2);
    cout<<" mid:"<<mid<<endl;
    if((mid*mid)==key){
        return mid;
    }
    if((mid-1)*(mid-1)==key){
        return mid-1;
    }
    if((mid+1)*(mid+1)==key){
        return mid+1;
    }
    if((mid*mid)<key && ((mid+1)*(mid+1)>key)){
        return mid;
    }
    else if((mid*mid)>key && ((mid-1)*(mid-1)<key)){
        return mid-1;
    }
    else if((mid*mid)<key && ((mid+1)*(mid+1)<key)){
        return bsearch(mid+1,high,key);
    }
    else{
        return bsearch(low,mid-1,key);
    }
}
int sqrt(int A) {
    int ans = bsearch(0,A,A);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(){
    int n;
    cin>>n;
    cout<<"ans:"<<sqrt(n)<<endl;
    return 0;
}