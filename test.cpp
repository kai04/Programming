#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,M,x,sum,prev,prevj,dump,remsum,temp1;
    cin>>N>>M;
    
    vector<int> vec(N);
    vector<int> vec1(N);
    set<int> kk;
    for(int i=0;i<N;i++){
        cin>>x;
        vec[i]=x;
    }
    sort(vec.begin(),vec.end());
   
    int count=0;
   
    
    for(int i=0;i<N-1;i++)
    {
        
        for(int j=i+1;j<N;j++)
        {
          
            kk.erase(kk.begin(),kk.end());
                 copy((vec.begin()+j+1), vec.end(), inserter(kk, kk.begin()));
           
           if(vec[i]==prev||vec[j]==prevj)
            {
                dump=0;
              //  i++;
            }
            else
            {
            sum=vec[i]+vec[j];
                remsum=M-sum;
          
           
               for(set<int>::iterator it=kk.begin();it!=kk.end();it++){
                if((*it)<=remsum){
                    count++;
                 
                }
            }
                
                
            }
           
            prevj=vec[j];
        }
        prev=vec[i];

    }
    cout<<count<<endl;
   
       
    return 0;
}

