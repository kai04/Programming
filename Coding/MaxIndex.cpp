/*
 * MaxIndex.cpp
 *
 *  Created on: 30-Mar-2018
 *      Author: saurav
 */


#include <bits/stdc++.h>
using namespace std;

bool mysort(pair<int,int> p,pair<int,int> q){
    if(p.first<q.first)
        return true;
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(make_pair(x,i));
        }
        sort(A.begin(),A.end(),mysort);
        int max1=0;
        int i=0,j=n-1;
        while(i<=j){
            // cout<<"===================="<<endl;
            // cout<<"i:"<<i<<" j:"<<j<<endl;

            if(A[i].second<=A[j].second){
                max1=max(max1,(A[j].second-A[i].second));
                // cout<<"max1:"<<max1<<endl;
                j--;
            }
            else{
                // cout<<"i snd:"<<A[i].second<<" j snd:"<<A[j].second<<endl;
                i++;
                continue;
            }


        }
        cout<<max1<<endl;
    }
	//code
	return 0;
}



