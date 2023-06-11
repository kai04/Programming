//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/
#include <bits/stdc++.h>
const int mod = 1e9+7;
using namespace std;
vector<int> parent,cost;
vector<int> setsize;
typedef long long ll;
void make(int u){
	parent[u] = u;
	setsize[u] = 1;
}

int find(int v){
	if(parent[v]==v)
		return v;
	//path compression;
	return parent[v] = find(parent[v]);
}

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void union_by_size(int a, int b){
	int parent_a = find(a);
	int parent_b = find(b);
	if(parent_a!=parent_b){
		if(setsize[parent_a]<setsize[parent_b]){
			swap(&parent_a, &parent_b);
		}
		parent[parent_b] = parent_a;
		setsize[parent_a] += setsize[parent_b];
		setsize[parent_b] = 0; 
	}
}

int main() {
	int n,k;
	cin >> n;    //Reading input from STDIN
	parent.resize(n+1);
	cost.resize(n+1);
	setsize.resize(n+1,0);
	unordered_map<int,int> m;
	for(int i = 1;i<=n;i++){
		cin>>cost[i];
		make(i);
		m[i]=cost[i];
	}
	cin>>k;
	while(k--){
		int i,j;
		cin>>i>>j;
		union_by_size(i,j);
	}
	
	for(int i=1;i<=n;i++){
		int par = find(i);
		m[par] = min(m[par],cost[i]);
	}
	unordered_map<int,int> m1;
	for(int i=1;i<=n;i++){
		int par = find(i);
		if(m[par]==cost[i])
			m1[par]++;
	}
	
	ll res = 1;
	for(auto it: m1){
		res = ((res% mod) * (it.second % mod))%mod;
	}
	cout<<res<<endl;
	return 0;
}