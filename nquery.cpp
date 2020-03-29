#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N,Q,lb,T,x,count=0,k,dis,i;
    cin >> T;
    for(int t=0;t<T;t++){
        cin>>N>>Q;
        vector<int> vec(N);
        for(int i=0;i<N;i++){
            //cin>>x;
            cin>>vec[i];
        }
       // cout<<"N:"<<N<<endl<<"Q:"<<Q<<endl<<"T:"<<T<<endl;
        sort(vec.begin(),vec.end());
        for(int q=0;q<Q;q++){
            cin>>lb;
             //cout<<"q:"<<q<<endl<<"lb:"<<lb<<endl;
            count=0;
         vector<int>::iterator it=upper_bound(vec.begin(),vec.end(),lb);
            int j=distance(vec.begin(),it);
           // cout<<"j:"<<j<<" size:"<<vec.size()<<endl;
            for(int s=j;s<vec.size();s++){
                count++;
            }
            j--;
            i=0;
            dis=j-i;
           //cout<<"initisl count:"<<count<<endl;
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            while(j>i&&(vec[j]+dis>=lb)){
            //if(vec[j]+dis>=lb){
                x=lb-vec[j];
                vec[j]+=x;
                count++;
                i+=x;
                j--;
                
            //}
             //   cout<<"i:"<<i<<" j:"<<j<<endl;
            }
            cout<<count<<endl;
        }
    
    }
    return 0;
}

