//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
{
#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function*/
int maxLen(int A[],int n)
{
  //Your code here
  map<int,int> m;
  int max1 = 0;
  m[A[0]] = 0;
//   cout<< A[0]<<" ";
  for(int i=1;i<n;i++){
      A[i] = A[i] + A[i-1];
    //   cout<<A[i]<<" ";
  }
//   cout<<endl;
  for(int i=1;i<n;i++){
      //A[i] = A[i] + A[i-1];
      map<int,int>::iterator it = m.find(A[i]);
      if(it!=m.end()){
          int j = m[A[i]];
          max1 = max(max1,(i-j));
        //   cout<<"i:"<<i<<" j:"<<j<<" A[i]:"<<A[i]<<endl;
      }
      else if(A[i]==0){
          max1 = max(max1,(i+1));
      }
      else{
          m[A[i]] = i;
      }
  }
  return max1;
}