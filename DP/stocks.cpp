//https://www.hackerrank.com/challenges/stockmax/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'stockmax' function below.x>y && x>z
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY prices as parameter.
 */

long max1(long x,long y,long z){
    if(x>=y && x>=z){
        return x;
    }
    else if(y>=x && y>=z){
        return y;
    }
    else{
        return z;
    }
}
long f(int i,int share,vector<int> &a,vector<vector<long>> &dp){
    int n = a.size();
    //base case
    if(i==n){
        if(share>0){
            return INT_MIN/2;
        }
        else{
            return 0;
        }
    }
    if(dp[i][share]!=0){
        return dp[i][share];
    }
    //buy
    long x  = f(i+1,share+1,a,dp) - a[i];
    //sell
    long y = 0 ;
    if(share>0){
        y = f(i+1,0,a,dp)+share*a[i];
    }
    //notxn
    long z = f(i+1,share,a,dp);
    dp[i][share] = max1(x,y,z);
    //cout<<"i:"<<i<<" share:"<<share<<" x:"<<x<<" y:"<<y<<" z:"<<z<<" dp[i][share]:"<<dp[i][share]<<endl;
    return dp[i][share];
}
/*long stockmax(vector<int> prices) {
    int n = prices.size();
    vector<vector<long>> dp(n,vector<long>(n+1,0));
    long ans = f(0,0,prices,dp);
    return ans;
}*/
long stockmax(vector<int> prices) {
    long sz = prices.size();
    if (sz == 1) 
        return 0; 
    long ans = 0, maxx=0;
    for (int i = sz-1; i >= 0; i--) { 
    if (prices[i] > maxx) 
        maxx = prices[i]; 
        ans += (maxx - prices[i]);
    } 
    return ans; 
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string prices_temp_temp;
        getline(cin, prices_temp_temp);

        vector<string> prices_temp = split(rtrim(prices_temp_temp));

        vector<int> prices(n);

        for (int i = 0; i < n; i++) {
            int prices_item = stoi(prices_temp[i]);

            prices[i] = prices_item;
        }

        long result = stockmax(prices);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
