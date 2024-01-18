//https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="*"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res = a*b;
                s.push(res);
            } else if(tokens[i]=="/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res = a/b;
                s.push(res);
            } else if(tokens[i]=="+"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res = a+b;
                s.push(res);
            } else if(tokens[i]=="-"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res = a-b;
                s.push(res);
            } else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
    
};