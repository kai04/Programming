//https://www.interviewbit.com/problems/pair-with-given-difference/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size();
    int i=0;
    int j=1;
    int ans = 0;
    for(int x:A){
        cout<<x<<" ";
    }
    cout<<endl<<"---------------------"<<endl;
    while(i<=j && i<n && j<n){
        int diff = A[j] - A[i];
        cout<<"i:"<<i<<" j:"<<j<<" A[i]:"<<A[i]<<" A[j]:"<<A[j]<<" diff:"<<diff<<endl;
        if(diff<B){
            j++;
        } else if(diff>B){
            i++;
        } else{
            ans = 1;
            break;
        }
    }
    return ans;
}

int solve1(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size();
    int ans =0;
    for(auto d: A)
        cout<<d<<" ";
    cout<<endl<<"==============================="<<endl;
    for(int i=0;i<n;i++){
        int f = B-A[i];
        auto it1 = lower_bound(A.begin(), A.end(), f);
        auto it2 = lower_bound(A.begin(), A.end(), -1*f);
        
        
        
        int j = -1;
        if(it1!=A.end() && *it1 ==f){
            j =  it1 - A.begin();
            cout<<"i:"<<i<<" j:"<<j<<" A[i]:"<<A[i]<<" A[j]:"<<*it1<<" diff:"<<f<<endl;
            if((A[i]-A[j])==B || (A[j]-A[i])==B){
                ans = 1;
                break;    
            }
        }
        if(it2!=A.end() && *it2 ==(-1*f)){
            j =  it2 - A.begin();
            cout<<"i:"<<i<<" j:"<<j<<" A[i]:"<<A[i]<<" A[j]:"<<*it2<<" diff:"<<(-1*f)<<endl;
            if((A[i]-A[j])==B || (A[j]-A[i])==B){
                ans = 1;
                break;    
            }
        }
        cout<<"-------------------------------"<<endl;
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int B;
	cin>>B;
    int ans = solve1(A,B);
	cout<<"ANS:"<<ans<<endl;
	
	return 0;
}