//https://leetcode.com/problems/employee-importance/submissions/
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
int bfs(vector<vector<int>> &graph,vector<int> &visited,int src,unordered_map<int,int> &imp){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    int ans = 0;
    while(!q.empty()){
        int v = q.front();
        ans +=imp[v];
        q.pop();
        for(int i=0;i<graph[v].size();i++){
            if(visited[graph[v][i]]==0){
                visited[graph[v][i]] = 1;
                q.push(graph[v][i]);
            }
        }
    }
    return ans;
}
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = 0;
        unordered_map<int,int> imp;
        for(int i=0;i<employees.size();i++){
            int v = employees[i]->id;
            imp[v] = employees[i]->importance; 
            n = max(n,v);
        }
        vector<vector<int>> graph(n+1);
        for(int i=0;i<employees.size();i++){
            graph[employees[i]->id] = employees[i]->subordinates;
        }
        vector<int> visited(n+1,0);
        int ans = bfs(graph,visited,id,imp);
        return ans;
    }
};