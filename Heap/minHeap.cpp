#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool myComparator(pair<int,int> p1,pair<int,int> p2){
    if(p1.first<p2.first){
        return true;
    }
    return false;
}
void minHeapPriorityQueue(vector<vector<int>> &A){
    int n = A.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>, myComparator> pq;
    for(int i=0;i<n;i++){
        int x = A[i][0];
        int y = A[i][1];
        int res =  (x*x) + (y*y);
        int z = sqrt(z);

    }
    while(!pq.empty()){
        int p = pq.top().first;
        cout<<"Point:("<<A[(pq.top().second)][0]<<","<<A[(pq.top().second)][1]<<") dist origin:"<<p<<endl;
        pq.pop();
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> A(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>A[i][0]>>A[i][1];
    }
    minHeapPriorityQueue(A);
    return 0;
}
