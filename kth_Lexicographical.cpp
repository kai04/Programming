//Kth lexicographical path from (0,0) to (x,y) when u can move only right and bottom(H-Horizontal,V-Vertical);
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long fact(int a,int b)
{
    if(b==0)
        return 1;
    long long pat=1;
    for(int i=0;i<b;i++)
    {
        pat*=(a-i);
    }
    for(int i=2;i<=b;i++)
    {
        pat/=i;
    }
    return pat;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x,y,k;
    cin>>x>>y>>k;
    int tot=fact(x+y,x);
    int l=1;
    int r=tot;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        //cout<<mid<<endl;
        if(k==mid)
        {
            while(x--)
                cout<<'H';
            while(y--)
                cout<<'V';
            break;
        }
        if(k>mid)
        {
            l=mid+1;
            cout<<'H';
            x--;
            //cout<<"x "<<x<<endl;
        }
        else
        {
            r=mid-1;
            cout<<'V';
            y--;
            //cout<<"y "<<y<<endl;
        }
    }

    return 0;
}

