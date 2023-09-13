//https://leetcode.com/problems/decode-string/
class Solution {
public:
    int processDigit(stack<char> &st){
        string num="";
        while(!st.empty() && st.top()>='0' && st.top()<='9'){
            num = string(1,st.top()) + num;
            st.pop();
        }
        stringstream ss;
        ss<< num;
        int num1;
        ss>>num1;
        return num1;
    }

    string preProcessString(stack<char> &st){
        string ret="";
        while(!st.empty() && st.top()>='a' && st.top()<='z'){
            ret = string(1,st.top()) + ret;
            st.pop();
        }
        return ret;
    }

    string postProcessString(string s1, int m){
        string ret = "";
        for(int i=0;i<m;i++){
            ret = ret + s1;
        }
        return ret;
    }

    void postProcess(stack<char> &st, string s1){
        for(char c:s1){
            st.push(c);
        }
    }


    string decodeString(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string s1 = preProcessString(st);
                st.pop(); // pop '[' from stack
                int n1 = processDigit(st);
                string s2 =  postProcessString(s1, n1);
                postProcess(st, s2);
            } else {
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = string(1,st.top())+ans;
            st.pop();
        }
        return ans;
    }
};