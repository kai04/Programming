#include<bits/stdc++.h>
using namespace std;

   vector<int> get_digits(int n){
        vector<int> ret;
        while(n>0){
            ret.push_back((n%10));
            n = n/10;
            //cout<<"n:"<<n<<endl;
        }
        return ret;
    }
    bool isHappy(int n) {
        int x = n;
        map<int,bool> visited;
        
        while(x!=1){
			if(visited[x])
				break;
            vector<int> digits = get_digits(x);
            int sum=0;
            for(int i=0;i<digits.size();i++){
                sum+=pow(digits[i],2);
            }
            visited[x] = true;
            x = sum;
            cout<<"x:"<<x<<endl;
        }
        if(x==1){
            return true;
        }
        return false;
    }
    
    
    int main(){
		int n;
		cin>>n;
		bool res = isHappy(n);
		cout<<res<<endl;
	return 0;
	}
