//LIS in O(nlogn)
#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> tail(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> a[arr_i];
    }
    int len=1;
    tail[0]=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<tail[0]){
            tail[0]=a[i];
        }
        else if(a[i]>tail[tail.size()-1]){
            len++;
            tail.push_back(a[i]);
        }
        else{
            vector<int>::iterator lower = upper_bound(tail.begin(),tail.end(),a[i]);
            while(lower!=tail.end()&& a[i]>(*lower)){
                lower++;
            }
            (*lower)=a[i];
        }
    }
    cout<<len<<endl;
    
}
