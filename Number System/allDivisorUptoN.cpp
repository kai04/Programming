		


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N = 100;
	vector<vector<int>> divisor(N+1);
        for(int i=1;i<=N;i++){
            for(int j=i;j<=N;j=j+i){
            	if(j!=i)
                	divisor[j].push_back(i);                
           }
        }

        for(int i =0;i<N;i++){
        	cout<<" divisor of "<<i<<"--> ";
        	for(int j=0;j<divisor[i].size();j++){
        		cout<<divisor[i][j]<<" ";
        	}
        	cout<<endl;
        }
	return 0;
}
		
        