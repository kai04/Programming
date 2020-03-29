#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    long long N, K, unfairness = INT_MAX,min1=0,max1=0,punfairness=INT_MAX;
    cin >> N >> K;
    long long list[N];
    vector<long long> vec(N);
    for (int i=0; i<N; i++)
    {
        cin >> list[i];
        vec[i]=list[i];
    }
    
    sort(vec.begin(),vec.end());
     //it=unique_copy (list,list+N,vec.begin());
    //vector<int>::iterator it=unique_copy(vec.begin(),vec.end());
    vector<long long>::iterator it=unique (vec.begin(),vec.end());
    vec.resize(distance(vec.begin(),it));
    /*for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        cout<<*it<<endl;
    }*/
    //cout<<" -----------"<<endl;
    for(int i=0;i<(vec.size()-K+1);i++){
        max1=*max_element(vec.begin()+i,vec.begin()+i+K);
        min1=*min_element(vec.begin()+i,vec.begin()+i+K);
       // cout<<"max:"<<max1<<endl;
       //cout<<"min:"<<min1<<endl;
        //punfairness=(max1-min1);
        unfairness=min(unfairness,(max1-min1));
    }

    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    cout << unfairness << "\n";
    return 0;
}

