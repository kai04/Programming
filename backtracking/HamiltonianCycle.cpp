#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

vector<vector<int>> sol;
bool isVisitedAll(int* visited,int n){
	for(int i=0;i<n;i++){
		if(visited[i]==-1){
			return false;
		}
	}
	return true;
}

void printCycle(vector<vector<int>> &sol){
	int n = sol.size();
	for(int i=0;i<n;i++){
		int m = sol[i].size();
		cout<<"Cycle "<<i+1<<endl;
		for(int j=0;j<m;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl<<"----------------------------------"<<endl;
	}
	cout<<"==============================="<<endl;

}

/*bool hamiltonian(int curr,int **graph,int *visited,int n,vector<int> &cycle){
	visited[curr]=1;
	//base case
	if(isVisitedAll(visited,n)){
		//add solution
		sol.push_back(cycle);
		cycle.resize(0);
		return true;
	}
	for(int i=0;i<n;i++){
		//choose
		if(i!=curr && visited[i]==-1 && graph[curr][i]==1){
			visited[i] = 1;
			cycle.push_back(i);
			//recursion
			if(hamiltonian(i,graph,visited,n,cycle)){
				return true;
			}
			//backtrace
			cycle.pop_back();
			visited[i]=-1;
		}
	}
	return false;
}*/
void hamiltonian(int curr,int **graph,int *visited,int n,vector<int> &cycle){
	visited[curr]=1;
	//base case
	if(isVisitedAll(visited,n)){
		//add solution
		sol.push_back(cycle);
	}
	else{
		for(int i=0;i<n;i++){
			//choose
			if(i!=curr && visited[i]==-1 && graph[curr][i]==1){
				visited[i] = 1;
				cycle.push_back(i);
				//recursion
				hamiltonian(i,graph,visited,n,cycle);
				cycle.pop_back();
				visited[i]=-1;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	int **graph = new int*[n];
	for(int i=0;i<n;i++){
		graph[i] = new int[n];
	}
	//input adjaceny matrix
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	int *visited = new int[n];
	for(int j=0;j<n;j++){
			visited[j]=-1;
		}
	vector<int> cycle;
	cycle.push_back(0);
	visited[0]=1;
	hamiltonian(1,graph,visited,n,cycle);
	printCycle(sol);	
	
	
	return 0;
}