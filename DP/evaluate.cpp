//https://leetcode.com/problems/different-ways-to-add-parentheses/submissions/
//https://www.geeksforgeeks.org/all-ways-to-add-parenthesis-for-evaluation/
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c){
        return (c=='+'||c=='-'||c=='*');
    }

void PrintResult(string input,vector<int> &dp){
    cout<<"String:"<<input<<endl;
    for(int i=0;i<dp.size();i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl<<"-------------------------------"<<endl;
}
vector<int> diffWaysToComputeUtils(string input,map<string,vector<int>> &dp){
        //memoizitation
        if(dp.find(input)!=dp.end()){
            PrintResult(input,dp[input]);    
            return dp[input];
        }
            //For all i
            vector<int> res;
            for(int i=0;i<input.size();i++){
                if(isOperator(input[i])){
                    vector<int> prefixOut = diffWaysToComputeUtils(input.substr(0,i),dp);
                     vector<int> postfixOut = diffWaysToComputeUtils(input.substr(i+1),dp);
                    for(int j=0;j<prefixOut.size();j++){
                        for(int k=0;k<postfixOut.size();k++){
                        int c;
                            if(input[i]=='+'){
                                c = prefixOut[j]+postfixOut[k];
                            }
                            if(input[i]=='-'){
                                c = prefixOut[j]-postfixOut[k];
                            }
                            if(input[i]=='*'){
                                c = prefixOut[j]*postfixOut[k];
                            }
                            cout<<"input:"<<input<<" i:"<<i<<" input[i]:"<<input[i]<<" j:"<<j<<" prefixOut[j]:"<<prefixOut[j]<<" k:"<<postfixOut[k]<<" c:"<<c<<endl;
                            res.push_back(c);
                        }
                    }
                }
                
            }
            //base case
                if(res.size()==0){
                    res.push_back(atoi(input.c_str()));
                }
        PrintResult(input,dp[input]);
        dp[input] = res;
    return res;
    }
    
    vector<int> diffWaysToCompute(string input) {
        map<string,vector<int>> dp;
      return  diffWaysToComputeUtils(input,dp);
        
    }

int main(){
    string s;
    cin>>s;
    vector<int> res = diffWaysToCompute(s);
    PrintResult(s,res);
    return 0;
}