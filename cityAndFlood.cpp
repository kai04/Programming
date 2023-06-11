//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
#include <bits/stdc++.h>

using namespace std;
vector<int> parent;
vector<int> setsize;

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
	cin >> n>>k;    //Reading input from STDIN
	parent.resize(n+1);
	setsize.resize(n+1,0);
	for(int i = 1;i<=n;i++){
		make(i);
	}
	while(k--){
		int i,j;
		cin>>i>>j;
		union_by_size(i,j);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		int parent_i = find(i);
        cout<<"i:"<<i<<" parent[i]:"<<parent_i<<" size of i:"<<setsize[i]<<endl;
		if(i==parent_i){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}