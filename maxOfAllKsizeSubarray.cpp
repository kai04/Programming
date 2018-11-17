//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a;
        deque<int> d;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        int max1=INT_MIN;
        int temp=INT_MIN;
        for(int i=0;i<n;i++){
            if(i<k){
                if(d.empty()){
                    d.push_front(i);
                }
                else{
                    
                    while(!(d.empty())&& a[i]>=a[d.front()]){
                        d.pop_front();
                    }
                    
                    if(d.empty()){
                        // cout<<"h1:"<<a[i]<<endl;
                        d.push_front(i);
                    }
                    else if(a[i]>=a[d.front()])
                    {
                        // cout<<"h2:"<<a[i]<<endl;
                        d.push_front(i);
                    }
                    else{
                        // cout<<"h3:"<<a[i]<<endl;
                        while(!(d.empty()) && a[i]>=a[d.back()]){
                            d.pop_back();
                        }
                        d.push_back(i);
                    }
                }

            }
            else{
                temp=a[d.front()];
                max1=max(max1,temp);
                cout<<max1<<" ";
                //remove elements from front which are out of bound of window;
                while(!(d.empty())&& (i-d.front())>=k){
                    d.pop_front();
                    if(!(d.empty()))
                        max1=a[d.front()];
                    else
                       max1=INT_MIN;
                }
                //remove element from back if current element are greater than its back
                while(!(d.empty())&& a[i]>=a[d.back()]){
                    d.pop_back();
                }
                d.push_back(i);
                
            }
            temp=a[d.front()];
            max1=max(max1,temp);
            // cout<<"i:"<<i<<endl;
            // for(auto it:d){
            //     cout<<a[it]<<" ";
            // }
            // cout<<endl<<"================================"<<endl;
            

        }
    cout<<max1<<" "<<endl;
       
        
    }
    //code
    return 0;
}

