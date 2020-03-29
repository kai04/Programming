#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long recursion(long long x){
    if((x/10)==0)
        return x;
    else{
        return(x%10+recursion(x/10));
        
    }
}

long long compute(long long n){
      long long result=recursion(n);
    while((result/10)!=0)
        result=recursion(result);
    
    return result;
}
int main() {
    long long n,k,x,s,temp,temp1,i;
    string p,str;
    cin>>p>>k;
    string::size_type sz = 0;  
    /*s=log10(n)+1;
    temp1=n;
    //cout<<"s:"<<s;
    while(k>1){
        temp=n*pow(10,s);
        //cout<<"temp:"<<temp<<endl;
            n=temp+temp1;
        k--;
    }*/
    //cout<<"Number:"<<n<<endl;
    //cout<<"N:"<<p<<endl;
    /*long long result=recursion(n);
    while((result/10)!=0)
        result=recursion(result);*/
    i=0;
    long long result=0;
    while(i<p.length()){
        if((p.length()-i)>=10)
            { 
            str=p.substr(i,10);
            }
        else{
            temp1=p.length()-i;
            str=p.substr(i,temp1);
        }
    long long ll = stoll (str,&sz,0);
    result+=compute(ll);
     i+=10;   
    }
    result=result*k;
    result=recursion(result);
    cout<<result<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

