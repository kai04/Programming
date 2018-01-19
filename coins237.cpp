#include <bits/stdc++.h>
using namespace std;
int count1=0;
vector<vector<int>> v(0);
void rec(int n,vector<int> vec){
    
    if(n<0){
        cout<<endl;
     return;
    }
    if(n==0)
    {
        v.push_back(vec);
        cout<<n<<endl;
        count1++;
        return;
    }
    vec.push_back(n);
     cout<<n<<" ";
    rec(n-2,vec);
    rec(n-3,vec);
    rec(n-7,vec);
    
    
}
int main() {
    int n;
    vector<int> vec(0);
    cin>>n;
    rec(n,vec);
    cout<<"count:"<<count1<<endl;
    for()
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
