#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n,x;
    cin >> n;
    vector<int> vec(n);
    int a[n];
    
    for(int i=0;i<n;i++){
        cout<<"Enter Number:"<<endl;
        cin>>x;
	vec[i]=x;
        a[i]=vec[i];
    }
    sort(vec.begin(),vec.end());
     for(int i=0;i<n;i++){
        
        cout<<vec[i]<<endl;
    }
        return 0;
}
