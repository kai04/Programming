#include<bits/stdc++.h>
using namespace std;
int countSubArrWithSum0(vector<int> a){
    int n = a.size();
    bool flag = true;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            flag = false;
            break;
        }
    }
    if(flag)
        return (n*(n+1)/2);
    map<int,int> freq;
    freq[a[0]] = 1;
    int count=0;
    for(int i=1;i<n;i++){
        a[i] = a[i] +a[i-1];
        if(freq.find(a[i])!=freq.end()||a[i]==0){
            count++;
        }
        freq[a[i]] = 1;
    }
    return count;
    
}
int fn(vector<int> &arr){
    int n=arr.size();
    unordered_map<int, int> prevSum; 
    int res = 0;  
    int currsum = 0; 
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == 0)  
            res++;         
        if (prevSum.find(currsum) != prevSum.end())  
            res += (prevSum[currsum]); 
        prevSum[currsum]++; 
    } 
    return res;
}
int Solution::solve(vector<vector<int> > &A) {
    int R = A.size();
    int C = 0;
    if(R!=0){
        C = A[0].size(); 
    }
    int new_count=0;
    for(int l=0;l<R;l++){
        vector<int> temp(C,0);
        for(int r=0;r<R;r++){
            if(l<=r){
                if(l==r){
                    for(int i=0;i<C;i++){
                        temp[i] =  A[r][i];
                    }
                }
                else{
                    for(int i=0;i<C;i++){
                        temp[i] = temp[i] + A[r][i];
                    }   
                }
                /*cout<<"Printing Vector Temp...."<<endl;
                for(auto it:temp)
                    cout<<it<<" ";
                cout<<endl;*/
                int count1 = fn(temp);
                new_count+=count1;
                /*cout<<"l:"<<l<<" r:"<<r<<" count:"<<count1<<" Total:"<<new_count<<endl;
                cout<<"---------------------------------"<<endl;*/
                
            }
        }
    }
    return new_count;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int res = solve(a);
    cout<<"RES:"<<res<<endl;
    return 0;
}

