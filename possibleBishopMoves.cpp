#include <bits/stdc++.h>
using namespace std;

int solve(int A, int B)
{
    int tr_x = A, tr_y = B;
    int tl_x = A, tl_y = B;
    int bl_x = A, bl_y = B;
    int br_x = A, br_y = B;
    int cnt = 0;

    // top left
    //  x-1,y-1
    while (tl_x > 0 && tl_y > 0)
    {
        // cout<<"Top Left x:"<<tl_x<<" y"<<tl_y<<endl;
        tl_x--;
        tl_y--;
    }

    if (tl_x == 0 || tl_y == 0)
    {
        tl_x++;
        tl_y++;
    }

    // top right
    // x-1,y+1
    while (tr_x > 0 && tr_y < 9)
    {
        // cout<<"Top Right x:"<<tr_x<<" y"<<tr_y<<endl;
        --tr_x;
        ++tr_y;
    }

    if (tr_x == 0 || tr_y == 9)
    {
        tr_x++;
        tr_y--;
    }

    // bottom left
    // x+1,y-1
    while (bl_x < 9 && bl_y > 0)
    {
        // cout<<"Bottom Left x:"<<bl_x<<" y"<<bl_y<<endl;
        ++bl_x;
        --bl_y;
    }

    if (bl_x == 9 || bl_y == 0)
    {
        bl_x--;
        bl_y++;
    }

    // bottom right
    // x+1,y+1
    while (br_x < 9 && br_y < 9)
    {
        // cout<<"Bottom Right x:"<<br_x<<" y"<<br_y<<endl;
        ++br_x;
        ++br_y;
    }

    if (br_x == 9 || br_y == 9)
    {
        br_x--;
        br_y--;
    }
    // cout << "br_x:" << br_x << " br_y:" << br_y << "\nbl_x:" << bl_x << " bl_y:" << bl_y << "\ntl_x:" << tl_x << " tl_y:" << tl_y <<"\ntr_x:"<<tr_x<<" tr_y:"<<tr_y<<endl;
    cnt = abs(tl_x-br_x) + abs(bl_x - tr_x);
    return cnt;
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << solve(A, B);
    return 0;
}