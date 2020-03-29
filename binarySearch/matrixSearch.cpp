#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool bsearch(ll low,ll high,ll elt,vector<int> &x){
    if(low>high){
        return false;
    }
    ll mid = low + ((high-low)/2);
    if(x[mid]==elt){
        return true;
    }
    else if(x[mid]<elt){
        return bsearch(mid+1,high,elt,x);
    }
    else {
        return bsearch(low,mid-1,elt,x);   
    }
}
int binary_search1(ll low,ll high,ll key,vector<int> &a){
     if(low>=high){
         return low;
     }

    ll mid = low + ((high-low)/2);
    if (a[mid] >= key && (mid == 0 || a[mid-1] < key)) return mid;
    if (a[mid] < key) return binary_search1(mid + 1, high, key, a);
    else return binary_search1(low, mid-1, key, a);
}

int main() {
    int n;
    cin>>n;
    vector<int> last;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(j==n-1){
                last.push_back(a[i][j]);
            }
        }
    }
    ll key;
    cin>>key;
    int row = binary_search1(0,n-1,key,last);
    //vector<int> b = a[row];
    // cout<<"Row no:"<<row<<endl;
    bool flag = false;
    flag = bsearch(0,n-1,key,a[row]);
    if(flag){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;   
    }
	return 0;
}