//https://www.geeksforgeeks.org/number-subarrays-m-odd-numbers/
/*
12 3
4 1 3 2 5 6 2 2 3 4 4 6
*/
//No of subarray with m odd count in an array
#include <bits/stdc++.h>
using namespace std;

int method2(vector<int> a,int n,int m){
	int lo=0,l=0,r=0,ro=0;
    int cnt=0;
    int ans=0;
    while(l<n && r<n){
        if(a[r]%2==1){
            cnt++;
        }
        // cout<<"l:"<<l<<" r:"<<r<<" cnt:"<<cnt<<endl;
        if(cnt==m){
            lo=l;
            ro=r;
            while(lo+1<n && (a[lo+1]%2)!=1){
                 lo++;       
            }
            while(ro+1<n && (a[ro+1]%2)==0){
                 ro++;       
            }
            ro++;
            
            
           
            // cout<<"Before:"<<endl;
            // cout<<"l:"<<l<<" lo:"<<lo<<" r:"<<r<<" ro:"<<ro<<" ans:"<<ans<<endl;
            
            if(l<n && (a[l]%2)==1){
                ans+=(ro-r);
                cnt--;
//                   cout<<"printing..."<<endl;
             
//                 for(int j=r;j<ro;j++){
//                     for(int k=l;k<=j;k++){
//                         cout<<a[k]<<" ";
//                     }
//                     cout<<endl;
//                 }
            
            }
            else{
                ans+=(lo-l+1)*(ro-r);
            // cout<<"printing..."<<endl;
            //  for(int i=l;i<=lo;i++){
            //     for(int j=r;j<ro;j++){
            //         for(int k=i;k<=j;k++){
            //             cout<<a[k]<<" ";
            //         }
            //         cout<<endl;
            //     }
            // }
                l=lo;
            }
            // cout<<"After:"<<endl;
            // cout<<"l:"<<l<<" lo:"<<lo<<" r:"<<r<<" ro:"<<ro<<" ans:"<<ans<<endl;
            // cout<<"=============================="<<endl;
            l++;
            r--;
            cnt--;
        }
        
        if(r<n){
            r++;
        }
    }
}
/*
Not correct method failed:
2, 2, 5, 6, 9, 2, 11
*/
int method1(vector<int> a,int n,int m){
     int i=0,j=0;
    int oddc=0;
    int count1=0;
    while(i<=j&&j<n){
        //cout<<"i:"<<i<<" j:"<<j<<" oddc:"<<oddc<<" count:"<<count1<<endl;
        if(a[j]%2==1){
            oddc++;
        }
        
        if(oddc==m){
            count1++;
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            if(a[i]%2==0)
            {
             j--;   
            }
            oddc--;
            i++;
        }
        j++;
        //cout<<"i:"<<i<<" j:"<<j<<" oddc:"<<oddc<<" count:"<<count1<<endl;
        //cout<<"=================================="<<endl;
    }
    return count1;
}
//most correct way
//ref:https://discuss.codechef.com/questions/103416/contiguous-subarray
int method3(vector<int> a,int n,int k){
	int save[1000010],odd[n];
    vector<int> prefix(n,0);
    memset(save,0,sizeof(save));
    save[0]++;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            odd[i] = 0;
        else
            odd[i] = 1;
        sum +=odd[i];
        prefix[i]=sum;
        if(sum >= k)
            ans +=save[sum-k];
        save[sum]++;
    }
    cout<<"odd array.."<<endl;
    for(auto it:odd){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"prefix array.."<<endl;
    for(auto it:prefix){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"save array.."<<endl;
    for(int i=0;i<n;i++){
        cout<<save[i]<<" ";
    }
    cout<<endl;
    return ans;
}
int main(){
    int n,m;
    cin >> n>>m;
    vector<int> a(n);
    vector<int> odd(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            if(a[i]%2==1)
                odd[i]=1;
            else
                odd[i]=0;
        }
        else{
        if(a[i]%2==1)
            odd[i]=odd[i-1]+1;
        else
            odd[i]=a[i-1];
        }
    }
    int count1=method1(a,n,m);
    int count2=method2(a,n,m);
     int count3=method3(a,n,m);
    // cout<<count1<<endl;
    cout<<count2<<endl;
    cout<<count3<<endl;
    return 0;
}
    