/* Sample program illustrating input/output */
#include<iostream>
#include<set>
using namespace std;
int main(void){

 

//Helpers for input and output

   long long N, K,p,x,temp,i,sum=0;
    long long result=0;
   cin >> N >> K;
    long long C[N];
    multiset<int> m,mnew;
   for(int i = 0; i < N; i++){
      cin >> C[i];
       m.insert(C[i]);
   }

    x=-1;
    while(m.size()>0){
        cout<<m.size()<<endl;
        x++;
        int p=0;
        if(m.size()>1){
        for(multiset<int>::iterator it=m.end();(it!=m.begin())&&(p<K);p++){
            multiset<int>::iterator n = --it;
            result+=(x+1)*(*it);
            m.erase(it);
            it = n;
        }
        }
        else
            {
            result+=(x+1)*(*m.begin());
            m.erase(m.begin());
        }
         //cout << result << "\n";
        }
        
    
  
    //cout <<endl<<"Sum:"<< sum << "\n";
   cout << result << "\n";
   
   return 0;
}
