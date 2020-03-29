#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
int binarysearch(vector<int> &vec,int p,int low,int high){
    //low=0;
    //high=vec.size()-1;
    if(high>=low){
    int mid=(low+high)/2;
    if(vec[mid]==p)
        return mid;
    else if(p>vec[mid])
        {
        return binarysearch(vec,p,mid+1,high);
        }
        else{
            return binarysearch(vec,p,low,mid-1);
        }
    }

        return -1;
    
    
}

bool check_cows(int n, vector<int> &stall, int mid,int c){
    int prev =stall[0];
    int temp=1;
    for(int i=1;i<n;i++){
        if((stall[i]-prev)>=mid){
            temp++;
            //cout<<"prev:"<<prev<<" stall[i]:"<<stall[i]<<" temp:"<<temp<<endl;
            if(temp==c)
                return true;
            prev=stall[i];
        }
        
    }
    
    return false;
}
int main() {
    int T,x,n,c;
    cin>>T;
    set<pair<int,int>> sol;
    while(T--){
      cin>>n>>c;
    vector<int> stall(n);
    for(int i=0;i<n;i++){
        cin>>x;
        stall[i]=x;
        if(i>0)
            sol.insert(make_pair(stall[i-1],stall[i]));
    }
    
    sort(stall.begin(),stall.end());
    //cout<<"size:"<<stall.size()<<endl;
    /*for(int i=0;i<n;i++){
        cout<<stall[i]<< " ";
    }
    cout<<endl;*/

    
    int mid;
    int range=stall[n-1]-stall[0];
    //cout<<"range:"<<range<<endl;
          int low=0;
        int high=range;
        while(low+1<high){
       mid=(low+high)/2;
           
            bool ret=check_cows(n, stall, mid, c);
             //cout<<"mid:"<<mid<<" "<<"return:"<<ret<<endl;
        if(ret){		
				low = mid;
			}
			else{
				high = mid;
			}
            
        
    }
    cout<<mid<<endl;
       
    }
    
    return 0;
}

