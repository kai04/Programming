#include<bits/stdc++.h>
using namespace std;

int getMinimumSwapsRequiredToMakeArrayEqual (vector<char> a, vector<char> b) {
   // write your logic here
   int n = a.size();
   int c_a0 = 0;
   int c_a1 = 0;
   int c_b0 = 0;
   int c_b1 = 0;
   int c_01=0;
   int c_10=0;
   for(int i=0;i<n;i++){
    //   cout<<"i:"<<i<<" a[i]:"<<a[i]<<" "<<(a[i]==1)<<" "<<(a[i]=='1')<<endl;
       if(a[i]=='1'){
           c_a1++;
       }
       else{
           c_a0++;
       }
       
       if(b[i]=='1'){
           c_b1++;
       }
       else{
           c_b0++;
       }
   }

       int ans =0;
       for(int i=0;i<n;i++){
           if(a[i]=='0' && b[i]=='1'){
               c_01++;
           }
           if(a[i]=='1' && b[i]=='0'){
               c_10++;
           }
       }
       ans+=c_01/2;
       ans+=c_10/2;
       c_01 = c_01 %2;
       c_10 = c_10 %2;
       if(c_10==c_01){
           ans += c_10;
       }
       else{
           ans =-1;
       }
       return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> a(n);
    for(int i_a=0; i_a<n; i_a++)
    {
      cin >> a[i_a];
    }
    vector<char> b(n);
    for(int i_b=0; i_b<n; i_b++)
    {
      cin >> b[i_b];
    }

    int out_;
    out_ = getMinimumSwapsRequiredToMakeArrayEqual(a, b);
    cout << out_;
}