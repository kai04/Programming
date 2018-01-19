#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007
/*int binarysearch(vector<int> &vec,int p,int low,int high){
    if(high>=low){
    int mid=(low+high)/2;
    if(vec[mid]==p)
        return mid;
    else if(p>vec[mid])
        {
        return binarysearch(vec,p,mid+1,high);
        }
        else{
            return binarysearch(vec,p,low,mid-1);
        }
    }

        return -1;
    
   }
*/
int main()
{
long long T,a_s,b_s,c_s,p,res,res1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>T;
	while(T--){
		res=0;
		res1=0;
		cin>>a_s>>b_s>>c_s;
		vector<ll> a(a_s);
		vector<ll> b(b_s);
		vector<ll> c(c_s);
		for(int i=0;i<a_s;i++){
			cin>>p;
			a[i]=p;
		}
		for(int i=0;i<b_s;i++){
			cin>>p;
			b[i]=p;
		}
		for(int i=0;i<c_s;i++){
			cin>>p;
			c[i]=p;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		
		for(int j=0;j<b_s;j++){
			ll x=0,y=0,z=0;
			y=b[j];
			vector<ll>::iterator low,up;
  			low=lower_bound (c.begin(), c.end(), y);           
  			up= upper_bound (a.begin(), a.end(), y);
  			//cout<<"Index in C:"<<distance(c.begin(),low)<<endl;
  			//cout<<"Index in A:"<<distance(a.begin(),up-1)<<endl;
  			int r=distance(a.begin(),up-1);
  			int s=distance(c.begin(),low);
			/*int r=binarysearch(a,y,0,a.size()-1);
			int s=binarysearch(c,y,0,c.size()-1);*/
			for(int i=r;i>=0;i--){
				x+=a[i];
				}	
			for(int k=0;k<=s;k++){
				z+=c[k];
			}
			ll temp=(y*(r+1))%mod;
			ll resx=(x+temp)%mod;
			ll temp1=(y*(s+1))%mod;
			ll resz=(z+temp1)%mod;

			//res+=(x+(y*(r+1)));
			//res*=(z+(y*(s+1)));
			res1=(resx*resz)%mod;

			


		}

		/*for(int i=0;i<a_s;i++){
			x=a[i];
			for(int j=0;j<b_s;j++){
				y=b[j];
				if(x<=y){
				for(int k=0;k<c_s;k++){
					z=c[k];
					if((x<=y)&&(y>=z)){
						//cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
						res=(x + y)%mod; 
						res*=(y + z)%mod;
						res=res%mod;
						res1=(res1+res)%mod;	
					}
				}
				}
			}
		}*/
		cout<<res1<<endl;	


}

    return 0;
}
