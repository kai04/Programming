#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;

int main() {
 int H, W;
 cin >> H >> W;
 vector<vector<int>> DP(H, vector<int>(W, 0));
 vector<vector<char>>grid(H, vector<char>(W));
 for (int i = 0; i < H; i++) {
  for (int j = 0; j < W; j++) {
   cin >> grid[i][j];
  }
 }
 DP[0][0] = 1;
 for (int i = 1; i < DP.size(); i++) {
  if (grid[i][0] == '.') {
   DP[i][0] = DP[i - 1][0];
  }
  else {
   DP[i][0] = 0;
  }
 }
 for (int j = 1; j < DP[0].size(); j++) {
  if (grid[0][j] == '.') {
   DP[0][j] = DP[0][j - 1];
  }
  else{
   DP[0][j] = 0;
  }
 }
 for (int i = 1; i < H; i++) {
  for (int j = 1; j < W; j++) {
   if (grid[i][j] == '.') {
    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
    DP[i][j] %= MOD;
   }
   else {
    DP[i][j] = 0;
   }
  }
 }
 cout << DP[H - 1][W - 1] << endl;

return 0;
}