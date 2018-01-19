#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace stdint main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    vector<int> v;
    while(n--) {
        int t; cin>>t;
        v.push_back(t);
    }
    n = v.size();
    
    //if(n==1) {cout<<1<<endl; return;}
    
    int l=0, r = n-1, max = 1, adv=0;
    while(l<r) {
        int min;
        //cout<<"l:"<<v[l]<<" r:"<<v[r];
        if(v[l] < v[r]) {
            min = v[l];
            l++;
        } else {
            min = v[r];
            r--;
        }
        int tmp = min - 1 + 2 - adv;
        //cout<<"min:"<<min<<" adv:"<<adv<<" tmp:"<<tmp<<endl;
        if(tmp > max) max = tmp;
        adv++;
    }
    cout<<max<<endl;
    return 0;
    }