#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> a[arr_i];
    }
    int x,y;
    cin>>x>>y;
    // sort(a.begin(),a.end());
    vector<int>:: iterator lower=lower_bound(a.begin(),a.end(),x);
    vector<int>:: iterator upper=upper_bound(a.begin(),a.end(),y);
    cout<<"lower bound of "<<x<<" found at index:"<<(lower-a.begin())-1<<" distance of x from start is:"<<distance(a.begin(),lower)<<endl;
    cout<<"upper bound of "<<y<<" found at index:"<<(upper-a.begin())-1<<" distance of x from start is:"<<distance(a.begin(),upper)<<endl;
    return 0;
}
