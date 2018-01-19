#include <iostream>
#include<cmath>
#define INT_MAX 999999
using namespace std;

int cost(int n, int i1,int i2,int j1,int j2,int k1,int k2)
{
    int sum=0;
    int i=0;
    while(i!=i2)
    {
        sum+=abs(i1-i)+1;
        i++;
    }
    while(i!=i2+j2)
    {
        sum+=abs(j1-i)+1;
        i++;
    }
    while(i!=n)
    {
        sum+=abs(k1-i)+1;
        i++;
    }
    return sum;
}
int solve(int n, int i1,int i2,int j1,int j2,int k1,int k2)
{
    if(i2+j2+k2==n)
    {
        return cost(n,i1,i2,j1,j2,k1,k2);
    }
    int a1=INT_MAX,a2=INT_MAX,a3=INT_MAX,a4=INT_MAX;
    if(i1>1)
    a1=solve(n-1,i1-1,i2,j1-1,j2,k1-1,k2);
    if(j1-i1>1)
    a2=solve(n-1,i1,i2,j1-1,j2,k1-1,k2);
    if(k1-j1>1)
    a3=solve(n-1,i1,i2,j1,j2,k1-1,k2);
    if(n-k1>1)
    a4=solve(n-1,i1,i2,j1,j2,k1,k2);
    int x= min(a1,min(a2,min(a3,a4)));
    return x;
}
int main() {
	int n;
	cin>>n;
	int **a=new int*[3];
	for(int i=0;i<3;i++)
	{
	    a[i]=new int[2];
	}
	for(int i=0;i<3;i++)
	{
	    cin>>a[i][0]>>a[i][1];
	}
	cout<<solve(n,a[0][0],a[0][1],a[1][0],a[1][1],a[2][0],a[2][1]);
	return 0;
}
