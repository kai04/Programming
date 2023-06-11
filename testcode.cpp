/*
A = {1,2,2,1,3,1}
Ans = {12,6,6,12,4,12}

prefixProduct =1 2 4 4 12 12
suffixProduct = 12 12 6 3 3 1

TC: O(N)
SC: O(N) 
prefixProductSofar = 1 * A[i-1]
Ith element
suffixProduct[i+1]
ANS[i] = prefixProductSofar * suffixProduct[i+1]


given array of positive integers of size n. return array of size n where each element is number of smaller consecutive elements than current element from given array
s = [8]
A = [1,7,5,4,8]
prev_greater_element = [-1,-1,1,1,1]

0 - (-1+1) = 0
1 - (1+1)-1-) = 1
2 - (2- (1+1)) 

j = prev_greater_element[i]
if(j!=-1)
	ANS[i] = i-(j+1) +1
else
	ANS[i] = i+1 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> solve_new(vector<int> &A){
	int n = A.size();
	vector<int> suffProd(n,1);
	vector<int> ans(n);
	for(int i = n-1;i>=0;i--){
		if(i==n-1){
			suffProd[i] = A[i];
		} else {
			suffProd[i] = suffProd[i+1]* A[i];
		}
	}

	int prefProd = 1;
	for(int i = 0;i<n;i++){
		if(i==0){
			ans[i] = suffProd[i+1];
			prefProd *= A[i];
		} else if(i==n-1){
			ans[i] = prefProd;
			prefProd *= A[i];
		}else {
			ans[i] = prefProd * suffProd[i+1];
			prefProd *= A[i];
		}
	}
	return ans;
}
vector<int> solve(vector<int> &A){
	int n = A.size();
	vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		int j = A[i];
		if(j!=-1){
			ans[i] = i-(j+1);
		} else {
			ans[i] = i ;
		}
	}
	return ans;
}
vector<int> find_prev_greater(vector<int> &A){
	int N = A.size();
	vector<int> prev_greater_element(N,-1);
	stack<int> s;
	int i= 0;
	while(i<N){
		if(!s.empty())
		{
			int x = s.top();
			if(A[x]>A[i]){
				prev_greater_element[i] = x;
				s.push(i);
				i++;
			} else {
				s.pop();
			}
		} else {
			s.push(i);
			prev_greater_element[i] = -1;
			i++;
		}
	}
	return prev_greater_element;
}


int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	// vector<int> prev = find_prev_greater(A);
	vector<int> ans = solve_new(A);
	for(int x:ans){
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}



