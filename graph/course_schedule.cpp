//https://leetcode.com/problems/course-schedule/submissions/
class Solution {
public:
    void printQueue(queue<int> q){
        cout<<"Printing Queue ...."<<endl;
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl<<"-------------------------"<<endl;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses+1);
        int e = prerequisites.size();
        queue<int> q;
        vector<int> in_degree(numCourses,0);
        for(int i=0;i<e;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in_degree[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0){
                q.push(i);
            }
        }
        // printQueue(q);
        vector<int> visited(numCourses,-1);
        while(!q.empty()){
            int u = q.front();
            visited[u] = 1;
            q.pop();
            for(int i=0;i<graph[u].size();i++){
                int v = graph[u][i];
                in_degree[v]--;
                if(in_degree[v]==0 && visited[v]==-1){
                    q.push(v);   
                }
            }
            // printQueue(q);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==-1)
                return false;
        }
        return true;
    }
};