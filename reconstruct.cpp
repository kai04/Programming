#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
static multiset<int> A;
int rec(multiset<int> s,int n){
    int e1,e2,e3,s1,s2,s3,s4,s5,s6,s7,p,sum;
    if(n>2){
    s.erase(0);
    e1=*next(s.begin(),0);
    e2=*next(s.begin(),1);
    A.insert(e1);
    A.insert(e2);
    
    //cout<<"e1:"<<e1<<" e2:"<<e2<<endl;
    sum=e1+e2;
    if(*next(s.begin(),2)==sum){
        e3=*next(s.begin(),3);
    }
    else{
        e3=*next(s.begin(),2);
    }
    A.insert(e3);
    s1=e1;
    s2=e2;
    s3=e3;
    s4=e1+e2;
    s5=e2+e3;
    s6=e1+e3;
    s7=e1+e2+e3;
    s.erase(s1);
    s.erase(s2);
    s.erase(s3);
    s.erase(s4);
    s.erase(s5);
    s.erase(s6);
    s.erase(s7);
   p=rec(s,n-3);
    }
    else if(n==2){
          for(multiset<int> ::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
        
    }
        s.erase(0);
         e1=*next(s.begin(),0);
        e2=*next(s.begin(),1);
        s1=e1;
        s2=e2;
        s3=e1+e2;
        cout<<"e1:"<<e1<<" e2:"<<e2<<endl;
    /*    for(multiset<int> ::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
        
    }*/
        A.insert(e1);
        A.insert(e2);
         s.erase(s1);
        s.erase(s2);
        s.erase(s3);
        p=rec(s,n-2);
    }
    else if(n==1){
        s.erase(0);
        e1=*next(s.begin(),0);
        A.insert(e1);
        s.erase(e1);
        p=rec(s,n-1);
    }
    else{
        return 1;
    }
    return p;
}
int main() {
    int N,x,e1,e2,e3,sum;
    cin>>N;
    multiset<int> s;
    for(int i=0;i<pow(2,N);i++)
    {   
        cin>>x;
        s.insert(x);
    }
    rec(s,N);
    for(multiset<int> ::iterator it=A.begin();it!=A.end();it++){
        cout<<*it<<endl;
        
    }
  
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
static multiset<int> A;
int rec(multiset<int> s,int n){
    int e1,e2,e3,s1,s2,s3,s4,s5,s6,s7,p,sum;
    if(n>2){
    s.erase(0);
    e1=*next(s.begin(),0);
    e2=*next(s.begin(),1);
    A.insert(e1);
    A.insert(e2);
    
    //cout<<"e1:"<<e1<<" e2:"<<e2<<endl;
    sum=e1+e2;
    if(*next(s.begin(),2)==sum){
        e3=*next(s.begin(),3);
    }
    else{
        e3=*next(s.begin(),2);
    }
    A.insert(e3);
    s1=e1;
    s2=e2;
    s3=e3;
    s4=e1+e2;
    s5=e2+e3;
    s6=e1+e3;
    s7=e1+e2+e3;
    s.erase(s1);
    s.erase(s2);
    s.erase(s3);
    s.erase(s4);
    s.erase(s5);
    s.erase(s6);
    s.erase(s7);
   p=rec(s,n-3);
    }
    else if(n==2){
          for(multiset<int> ::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
        
    }
        s.erase(0);
         e1=*next(s.begin(),0);
        e2=*next(s.begin(),1);
        s1=e1;
        s2=e2;
        s3=e1+e2;
        cout<<"e1:"<<e1<<" e2:"<<e2<<endl;
    /*    for(multiset<int> ::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
        
    }*/
        A.insert(e1);
        A.insert(e2);
         s.erase(s1);
        s.erase(s2);
        s.erase(s3);
        p=rec(s,n-2);
    }
    else if(n==1){
        s.erase(0);
        e1=*next(s.begin(),0);
        A.insert(e1);
        s.erase(e1);
        p=rec(s,n-1);
    }
    else{
        return 1;
    }
    return p;
}
int main() {
    int N,x,e1,e2,e3,sum;
    cin>>N;
    multiset<int> s;
    for(int i=0;i<pow(2,N);i++)
    {   
        cin>>x;
        s.insert(x);
    }
    rec(s,N);
    for(multiset<int> ::iterator it=A.begin();it!=A.end();it++){
        cout<<*it<<endl;
        
    }
  
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
