#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c=='|' ||c=='&'||c=='^');
}
int covertChar(int c){
    if(c=='T'){
        return 1;
    }
    return 0;
}
void PrintResult(string input,vector<int> &dp){
    cout<<"String:"<<input<<endl;
    for(int i=0;i<dp.size();i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl<<"-------------------------------"<<endl;
}
vector<int> cntTrueUtils(string A,map<string, vector<int>> &dp){
    if(dp.find(A)!=dp.end()){
        return dp[A];
    }

    int n = A.length();
    // cout<<"hey"<<" size:"<<n<<endl;
     vector<int> res;
    for(int i=0;i<n;i++){
        // cout<<"char:"<<A[i]<<" i:"<<i<<endl;
        if(isOperator(A[i])){
            cout<<"operator:"<<A[i]<<endl;
            string prefixA = A.substr(0,i);
            string postfixA = A.substr(i+1);
            vector<int> prefixRes = cntTrueUtils(prefixA,dp);
            vector<int> postfixRes = cntTrueUtils(postfixA,dp);
           cout<<"Prefix:"<<prefixA<<" postfixA:"<<postfixA<<endl;
            for(int j=0;j<prefixRes.size();j++){
                for(int k=0;k<postfixRes.size();k++){
                    int temp;
                    if(A[i]=='|'){
                        temp =  prefixRes[j] | postfixRes[k];
                        res.push_back(temp);
                    }
                    else if(A[i]=='&'){
                        temp =  prefixRes[j] & postfixRes[k];
                        res.push_back(temp);
                    }
                    else if(A[i]=='^'){
                        temp =  prefixRes[j] ^ postfixRes[k];
                        res.push_back(temp);
                    }
                    cout<<"input:"<<A<<" i:"<<i<<" A[i]:"<<A[i]<<" j:"<<j<<" prefixOut[j]:"<<prefixRes[j]<<" k:"<<postfixRes[k]<<" tempRes:"<<temp<<endl;
                }
            }
        }
        
    }
    if(res.size()==0){
            int t = covertChar(A.c_str()[0]);
            cout<<"t:"<<t<<endl;
             res.push_back(t);       
        }
        dp[A] = res;
        PrintResult(A,dp[A]);
        
        return res;
}
int cnttrue(string A) {
    int ret  = 0;
    map<string,vector<int>> dp;
    vector<int> res = cntTrueUtils(A,dp);
    for(int i=0;i<res.size();i++){
        if(res[i]==1){
            ret++;
        }
    }
    return ret;
}

int main(){
    string s;
    cin>>s;
    int res = cnttrue(s);
    cout<<res<<endl;
    return 0;
}