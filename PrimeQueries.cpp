#include <bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
#define mod 1000000007;

bool isPrime(ll num)
{
     if (num <= 1) return false;
     if (num % 2 == 0 && num > 2) return false;
     for(int i = 3; i < floor(sqrt(num)); i++)
     {
         if (num % i == 0)
             return false;
     }
     return true;
}


ll F(vector<ll> &a,ll L,ll R,ll X,ll Y){
	ll number,exponent;
	   ll result = 0;
     for( ll i = X;i <= Y;i++) {
         if( isPrime(i) ) {
             for( ll j = L; j<= R;j++) {
                  number = a[j];
                  exponent = 0;
                  while( (number%i)== 0 ) {
                     exponent = exponent + 1; 
                     number = number/i;
                  }
                  result = result + exponent;
              }
         }
     }
     return result;

}
int main()
{
long long N,Q,p;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>N;
	vector<ll> a(N);
	for(int i=0;i<N;i++){
		cin>>p;
		a[i]=p;
	}
	cin>>Q;
	vector<vector<ll> v(4)> ip(Q);	
	//cout<<endl<<"Q:"<<Q<<endl;
	for(ll i=0;i<Q;i++){
		ll L,R,X,Y,res;
		cin>>L>>R>>X>>Y;
		ip[i].insert(L);
		ip[i].insert(R);
		ip[i].insert(X);
		ip[i].insert(Y);
	}

	for(ll i=0;i<Q;i++){
		res=F(a,ip[i].at(0),ip[i].at(1),ip[i].at(2),ip[i].at(3));
		cout<<res<<endl;
	}



    return 0;
}
