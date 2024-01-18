//https://www.interviewbit.com/problems/convert-the-amount-in-number-to-words/
#include<bits/stdc++.h>
using namespace std;

vector<string> ones = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
vector<string> tens = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
string create_twos(int x){
    string ret = "";
    if(x==0){
        return ret;
    }
    if(x<=19){
        return ones[x-1];
    }
    int p = x/10;
    int q = x%10;
    ret = tens[p-2];
    ret = ret + "-" +  create_twos(q);
    return ret;
}
void create(string s, string &ans){
    int n = s.length();
    if(n==9||n==8){
        string s1,s2;
        if(n==9){
            s1 = s.substr(0,2);
            s2 = s.substr(2,n-2);    
        } else if(n==8){
            s1 = s.substr(0,1);
            s2 = s.substr(1,n-1);
        }
        int x1 = stoi(s1);
        string s3 = create_twos(x1);
        ans+=s3;
        ans+=string("-crore-");
        create(s2,ans);
    } else if(n==7||n==6){
        string s1,s2;
        if(n==7){
            s1 = s.substr(0,2);
            s2 = s.substr(2,n-2);    
        } else if(n==6){
            s1 = s.substr(0,1);
            s2 = s.substr(1,n-1);
        }
        int x1 = stoi(s1);
        string s3 = create_twos(x1);
        ans+=s3;
        ans+=string("-lakh-");
        create(s2,ans);
    } else if(n==5||n==4){
        string s1,s2;
        if(n==5){
            s1 = s.substr(0,2);
            s2 = s.substr(2,n-2);    
        } else if(n==4){
            s1 = s.substr(0,1);
            s2 = s.substr(1,n-1);
        }
        int x1 = stoi(s1);
        string s3 = create_twos(x1);
        ans+=s3;
        ans+=string("-thousand-");
        create(s2,ans);
    } else if(n==3){
        string s1 = s.substr(0,1);
        string s2 = s.substr(1,n-1);
        int x1 = stoi(s1);
        string s3 = create_twos(x1);
        ans+=s3;
        ans+=string("-hundred-");
        int x2 = stoi(s2);
        string s4 = create_twos(x2);
        ans+=s4;
    } else if(n==2 || n==1){
        int x1 = stoi(s);
        string s4 = create_twos(x1);
        ans+=s4;
    }
}
vector<string> split(string s, char delimeter){
    vector<string> tokens;
    string token;
    istringstream is(s);
    while(getline(is,token,delimeter)){
        tokens.push_back(token);
    }
    return tokens;
}
int helper(string B, unordered_map<string,int> &m){
    vector<string> words = split(B,'-');
    int ans = 0;
    int n = words.size();
    int i=n-1;
    for(auto it:words){
        cout<<it<<" ";
    }
    cout<<endl;
    while(i>=0){
        string word = words[i];
        int q2 = m[word];
        if(word=="crore"){
            i--;
            int q1 = 0;
            while(i>=0){
                if(m.find(words[i])!=m.end()){
                    q1 = m[words[i]] + q1;
                }
                i--;
            }
            int q3 = q2*q1;
            ans = q3 + ans;    
        } else if(word=="lakh"){
            int j = i-1;
            int q1 = 0;
            int q2 = m[word];
            while(j>=0 && words[j]!="crore"){
                if(m.find(words[j])!=m.end()){
                    q1 = m[words[j]] + q1;
                }
                j--;
            }
            int q3 = q2*q1;
            ans = q3 + ans;
            i = j;
        }  else if(word=="thousand"){
            int j = i-1;
            int q1 = 0;
            int q2 = m[word];
            while(j>=0 && words[j]!="crore" && words[j]!="lakh"){
                if(m.find(words[j])!=m.end()){
                    q1 = m[words[j]] + q1;
                }
                j--;
            }
            int q3 = q2*q1;
            ans = q3 + ans;
            i = j;
        } else if(word=="hundred"){
            int j = i-1;
            int q1 = 0;
            int q2 = m[word];
            while(j>=0 && words[j]!="crore" && words[j]!="lakh" && words[j]!="thousand"){
                if(m.find(words[j])!=m.end()){
                    q1 = m[words[j]] + q1;
                }
                j--;
            }
            int q3 = q2*q1;
            ans = q3 + ans;
            i = j;
        } else if(word=="hundred"){
            i--;
        } else{
            if(m.find(words[i])!=m.end()){
                int q3 = m[words[i]];
                ans = q3 + ans;
            }
            i--;
        }
        
    }
    return ans;
}

void preprocess(unordered_map<string,int> &m){
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["ten"] = 10;
    m["eleven"] = 11;
    m["twelve"] = 12;
    m["thirteen"] = 13;
    m["fourteen"] = 14;
    m["fifteen"] = 15;
    m["sixteen"] = 16;
    m["seventeen"] = 17;
    m["eighteen"] = 18;
    m["nineteen"] = 19;
    m["twenty"] = 20;
    m["thirty"] = 30;
    m["fourty"] = 40;
    m["fifty"] = 50;
    m["sixty"] = 60;
    m["seventy"] = 70;
    m["eighty"] = 80;
    m["ninety"] = 90;
    m["hundred"] = 100;
    m["thousand"] = 1000;
    m["lakh"] = 100000;
    m["crore"] = 10000000;
}


int solve(string A, string B) {
    string ans = "";
    unordered_map<string,int> m;
    // create(A,ans);
    preprocess(m);
    int ret = helper(B,m);
    cout<<"ANS:"<<ret<<endl;
    return 1;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int ans = solve(s1,s2);
    return 0;
}
