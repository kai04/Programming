
//no substring with atleast one among a,b,c with count=0
    #include <bits/stdc++.h>
    #include <string>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--){
          string s;
          cin>>s;
          int n=s.length();
          int ca=0,cb=0,cc=0;
          int i=0,j=0;
          long long count=0;
          while(j<n){
              if(s[j]=='a'){
                  ca++;
              }
              else if(s[j]=='b'){
                  cb++;
              }
              else{
                  cc++;
              }
              if(ca>0 && cb>0 && cc>0){
                  while(ca>0 && cb>0 && cc>0){
                      if(s[i]=='a'){
                          ca--;
                      }
                      else if(s[i]=='b'){
                          cb--;
                      }
                      else{
                          cc--;
                      }
                      i++;
                  }
                  count+=j-i+1;
              }
              else{
                  count+=j-i+1;
              }
              
              j++;
          }
          cout<<count<<endl;
        }
        return 0;
    }

