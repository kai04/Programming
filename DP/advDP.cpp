//https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/editorial
//https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int L,G;
    cin>>L>>G;
    vector<int> crazy(L+1);
    vector<int> prefixSum(L+1,0);
    for(int i=1;i<=L;i++){
        cin>>crazy[i];
        prefixSum[i]=prefixSum[i-1]+crazy[i];
    }
    #define cost(i,j) (prefixSum[j]-prefixSum[(i)-1])*((j)-(i)+1)
    
    vector<vector<int>> f(G+1,vector<int>(L+1,INT_MAX));
    //base case
    for(int l=0;l<=L;l++){
        f[1][l] = cost(1,l);
    }
    for(int g=2;g<=G;g++){
        for(int l=0;l<=L;l++){
            for(int k=0;k<=l;k++){
                f[g][l] = min(f[g][l],(f[g-1][k] + cost(k+1,l) ));
            }
        }
    }
    

    /*for(int g=0;g<=G;g++){
        for(int l=0;l<=L;l++){
            cout<<f[g][l]<<"  ";        
        }
        cout<<endl;
    }*/
    cout<<f[G][L]<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

