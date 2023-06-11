//https://www.interviewbit.com/problems/pick-from-both-sides/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int sum =0;
    vector<int> psum(n),ssum(n);
    psum[0] = A[0];
    ssum[0] = A[n-1];
    for(int i=1;i<n;i++){
        psum[i] = psum[i-1] + A[i];
    }
    
    for(int i=1;i<n;i++){
        ssum[i] = ssum[i-1] + A[n-i-1];
    }
    
    int maxSum = INT_MIN;
    for(int t = 0; t<=B;t++){
        int r = t-1;
        int s =  B-t-1;
        int tsum;
        if(r>=0 && s>=0)
        	tsum = psum[r]+ssum[s];
        else if(r>=0)
        	tsum =  psum[r];
        else if(s>=0)
        	tsum =  ssum[s];
        else
        	tsum = 0;
        maxSum = max(maxSum, tsum);
        // cout<<"L elements:"<<r+1<< " R elements:"<<s+1<<" Left sum:"<<psum[r]<<" Right Sum:"<<ssum[s]<<" curr Sum:"<<tsum<<" Max so far:"<<maxSum<<endl;
        
    }
    return maxSum;
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
	cout<<"ANS:"<<solve(A,B)<<endl;
	
	return 0;
}