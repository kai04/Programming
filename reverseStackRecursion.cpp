//https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
    while(!s.empty()){
        int x=s.top();
        s.pop();
        cout<<x<<" ";
    }
    cout<<endl;
}
void insertAtBottom(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
    }
    else{
        int k =s.top();
        s.pop();
        insertAtBottom(s,x);
        s.push(k);
    }
}
void reverse(stack<int> &s){
    if(!s.empty()){
        int x=s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s,x);
    }
    return;
}
int main() {
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    cout<<"Before ..."<<endl;
    printStack(s);
    reverse(s);
    cout<<"After ..."<<endl;
    printStack(s);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

