#include <iostream>
using namespace std;
int n;
int calc(int i)
{
    if(i==1)
    return 1;
    return 0;
}
int solve(int i,int j,int **a,int ***dp,int val,int flag)
{
    if(i>n || j<0 || j>=5)
    return 0;
    if(dp[i][j][flag]!=-1)
    {
        return dp[i][j][flag];
    }
    if(flag==1)
    {
        if(val>0)
        {
            dp[i][j][1]=calc(a[i][j])+max(solve(i+1,j+1,a,dp,val-1,flag),max(solve(i+1,j,a,dp,val-1,flag),solve(i+1,j-1,a,dp,val-1,flag)));
        }
        else
        dp[i][j][1]=a[i][j]+max(solve(i+1,j+1,a,dp,0,flag),max(solve(i+1,j,a,dp,0,flag),solve(i+1,j-1,a,dp,0,flag)));
    }
    else
    {
        int a1,a2,a3,a4,a5,a6;
        a1=solve(i+1,j+1,a,dp,0,flag);
        a2=solve(i+1,j-1,a,dp,0,flag);
        a3=solve(i+1,j,a,dp,0,flag);
        a4=solve(i+1,j+1,a,dp,5,1-flag);
        a5=solve(i+1,j-1,a,dp,5,1-flag);
        a6=solve(i+1,j,a,dp,5,1-flag);
        dp[i][j][0]=a[i][j]+max(a1,max(a2,max(a3,max(a4,max(a5,a6)))));
    }
    return dp[i][j][flag];
}
int main() {
	cin>>n;
	int **a = new int*[n+1];
	for(int i=0;i<n+1;i++)
	{
	    a[i]=new int[5];
	}
	for(int i=0;i<5;i++)
	{
	    a[0][i]=0;
	}
	for(int i=n;i>0;i--)
	{
	    for(int j=0;j<5;j++)
	    {
	    	cin>>a[i][j];
	    	if(a[i][j]==2)
	    		a[i][j]=-1;
		}
	}
	int ***dp = new int**[n+1];
	for(int i=0;i<=n;i++)
	{
	    dp[i]=new int*[5];
	    for(int j=0;j<5;j++)
	       { 
	           dp[i][j]=new int[2];
	           dp[i][j][0]=-1;
	           dp[i][j][1]=-1;
	       }
	}
	int ans=solve(0,2,a,dp,0,0);
	cout<<ans<<endl;
	return 0;
}
