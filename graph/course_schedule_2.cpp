//https://leetcode.com/problems/course-schedule-ii/submissions/
class Solution {
public:
    void printStack(stack<int> s){
        cout<<"Printing...."<<endl;
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl<<"--------------------------"<<endl;
    }
    void dfs(int u,vector<vector<int>> &graph,stack<int> &s,vector<int> &state,vector<int> &parent,bool &is_back_edge){
        state[u] = 1;
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(state[v]==0){
                parent[v] = u;
                dfs(v,graph,s,state,parent,is_back_edge);
            }
            else{
                if(state[v]==1 && state[u]==state[v] && parent[v]!=u){
                    //back edge detected
                    is_back_edge = true;
                }
            }
        }
        s.push(u);
        state[u] = 2;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        stack<int> s;
        vector<int> state(numCourses,0);
        vector<int> parent(numCourses,-1);
        bool is_back_edge = false;
        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                dfs(i,graph,s,state,parent,is_back_edge);
            }
        }
        vector<int> ans;
        if(s.size()!=numCourses || is_back_edge){
            return ans;
        }
        // printStack(s);
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
