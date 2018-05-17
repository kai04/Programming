
//Also known as count all anagram
//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include <bits/stdc++.h>
using namespace std;

bool check(map<char,int> count1){
    for(auto it:count1){
        if(it.second>0){
            return false;
        }
    }
    return true;
}

void printHelper(string result,map<char,int> &count1){
    if(check(count1)){
        cout<<result<<" ";
    }
    for(auto it:count1){
        char c=it.first;
        int cnt=it.second;
        if(cnt>0){
            //choose
            result+=c;
            count1[c]-=1;
            //explore
            printHelper(result,count1);
            //unchoose
            result.erase(result.length()-1,1);
            count1[c]+=1;
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        map<char,int> count1;
        for(int i=0;i<n;i++){
            count1[s[i]]+=1;
        }
        printHelper("",count1);
        cout<<endl;
    }
	//code
	return 0;
}
