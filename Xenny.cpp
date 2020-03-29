#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
long long T,x,y;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>T;
	while(T--){
	cin>>x>>y;
ll rank=((x+y)*(x+y+1)/2)+x+1;
cout<<rank<<endl;

}
    return 0;
}
