#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
void generate_prime(int n){
	bool sieve[n+1] = {false};
	for(int i=2;i<=n;i++){
		if(sieve[i]==false){
			if(n%i==0)
				prime.push_back(i);
			sieve[i]=true;
			for(int j=i;j<=n;j=j+i){
				sieve[j]=true;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	generate_prime(n);
	int max1= *max_element(prime.begin(), prime.end());
	cout<<max1<<endl;
	return 0;
}