#include<bits/stdc++.h>
using namespace std;
    int cntChars(map<int,int> &m){
        int cnt = 0;
        int len = m.size();
        for(auto it:m){
            if(it.second>0)
                cnt++;
        }
        return cnt;
    }
    void printCount(map<int,int> &m){
    	for(auto it:m){
    		cout<<it.first<<" -> "<<it.second<<endl;
    	}
    	cout<<"-------------------------------"<<endl;
    }

    void changeCharCnt(map<int,int> &m,int x,int p){
    	cout<<"X:"<<x<<" p:"<<p<<endl;
    	if(p==0){
    		while(x>0){
    			int s = x%10;
    			// cout<<"s:"<<s<<endl;
    			x=x/10;
    			m[s]++;
    		}
    	}
    	else{
    		while(x>0){
    			int s = x%10;
    			// cout<<"s:"<<s<<endl;
    			x=x/10;
    			m[s]--;
    		}	
    	}
    	printCount(m);

    }
    
    int subarraysWithAtmostKDistinct(vector<int>& A, int K) {
        int n = A.size();
        int i=0,j=0,res=0;
        map<int,int> m;
        int cnt=0;
        while(j<n && i<=j){
        	if(cnt<=K){
        		// changeCharCnt(m,A[j],0);
        		m[A[j]]++;
        		j++;
        		// cout<<"HERE"<<endl;
        	}
        	// m[A[j]]++;
        	cnt = cntChars(m);
        	// cout<<"i:"<<i<<" j:"<<j<<" cnt:"<<cnt<<endl;
        	
        	
        	// printCount(m);
        	while(cnt>K){
        		m[A[i]]--;
        		// changeCharCnt(m,A[i],1);
        		cnt = cntChars(m);
        		i++;
        	}
        	res+=(j-i+1);
        }
        return res;
    }

int main(){
int n,k;
cin>>n>>k;
vector<int> a(n);
for(int i=0;i<n;i++){
	cin>>a[i];
}
int res1 = subarraysWithAtmostKDistinct(a,k);
int res2 = subarraysWithAtmostKDistinct(a,k-1);
cout<<"RES:"<<res1-res2<<endl;
return 0;
}
