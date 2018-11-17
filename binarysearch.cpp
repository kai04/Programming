#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int binarysearch(vector<int> &vec,int p,int low,int high){
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

int main() {
    int T,x,n,c;
    cin>>T;
    //while(T--)
      cin>>n>>c;
    vector<int> stall(n);
    for(int i=0;i<n;i++){
        cin>>x;
        stall[i]=x;
    }
    int index=binarysearch(stall,4,0,n-1);
    if(index!=-1)
        cout<<"Element found at index:"<<index<<endl;
    else
        cout<<"Element not found"<<endl;
    
      
    return 0;
}

