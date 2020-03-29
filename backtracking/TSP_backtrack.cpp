/*
test case 1:
5
200 20 30 10 11
15 200 16 4 2
3 5 200 2 4
19 6 18 200 3
16 4 7 16 200
output 28

test case 2:
4
0 10 15 20 
10 0 35 25 
15 35 0 30 
20 25 30 0
output 80

*/
#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
#define INF 1000000


void printGraph(int **graph,int n){
	cout<<"Printing graph ....";
	cout<<endl<<"-------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"-------------------------------------"<<endl;
}

bool isAllVisited(int *visited,int n){

	for(int i=0;i<n;i++){
		if(visited[i]==-1)
			return false;
	}
	return true;
}

// int minPathCost=INT_MAX/2; 
int TSP(int curr,int *visited,int n,int **graph,int minPathCost){
	visited[curr]=1;
	//base case
	if(isAllVisited(visited,n)){
		return (graph[curr][0]);
	}
	//choose
	for(int i=0;i<n;i++){
		if(i!=curr && graph[curr][i]!=(INT_MAX/2) && visited[i]==-1){
			visited[i]=1;
			//recurse
			int cost = TSP(i,visited,n,graph,minPathCost);
			minPathCost = min(minPathCost,cost+graph[curr][i]);
			//backtrack
			visited[i]=-1;
			// cost = cost-graph[curr][i];
		}
	}
	return minPathCost;	
}

int main(){
	//take input
	int n;
	cin>>n;
	int **graph = new int*[n];
	for(int i=0;i<n;i++){
		graph[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
			if(graph[i][j]>100){
				graph[i][j] = INT_MAX/2;
			}
		}
	}
	printGraph(graph,n);
	//initialize visited with -1
	int * visited = new int[n];
	for(int i=0;i<n;i++){
		visited[i]=-1;
	}
	//call
	int minPathlen = TSP(0,visited,n,graph,INT_MAX/2);
	cout<<"ANS:"<<minPathlen<<endl;
	return 0;
}