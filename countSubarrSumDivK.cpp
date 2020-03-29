#include <bits/stdc++.h> 
using namespace std; 
  

int subCount(vector<int> arr, int n, int k) 
{ 
 
    vector<int> remCount(k,0); 
  
 
    int cumSum = 0; 
    for (int i = 0; i < n; i++) { 
        cumSum += arr[i]; 
 
        remCount[((cumSum % k) + k) % k]++; 
    } 

    for(int i=0;i<k;i++){
        cout<<"i:"<<i<<" mod[i]:"<<mod[i]<<endl;
    }  
    int result = 0; // Initialize result 
  
    for (int i = 0; i < k; i++) 
 
        if (mod[i] > 1) 
            result += (mod[i] * (mod[i] - 1)) / 2; 

    result += mod[0]; 
  
    return result; 
} 


int main() 
{ 
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << subCount(arr, n, k) << endl;  
    return 0; 
} 
