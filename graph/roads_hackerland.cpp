//https://www.hackerrank.com/contests/june-world-codesprint/challenges/johnland/problem
#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

template<class T> inline void maximize(T &r, const T c) {
  r = max(r, c);
}

template<class T> inline void minimize(T &r, const T c) {
  r = min(r, c);
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100100;

struct DSU {
  int size;
  vector<int> p;
  vector<int> w;

  DSU(int n) :
    size(n),
    p(n, -1),
    w(n, 1) {}

  int Parent(int v) {
    if (p[v] == -1)
      return v;
    return p[v] = Parent(p[v]);
  }

  void Union(int u, int v) {
    u = Parent(u);
    v = Parent(v);
    if (w[u] < w[v])
      swap(u, v);
    p[v] = u;
    w[u] += w[v];
  }
};

vector<pt> g[N];
vector<pt> tree[N];
li total;
int subt[N];
vector<li> ans;

int Dfs(int v, int prev, int w) {
  subt[v] = 1;
  cout<<"Node:"<<v<<endl;
  for (pt &e : tree[v]) {
    if (e.first == prev)
      continue;
    cout<<"Calling dfs on:"<<e.first<<" with parent:"<<v<<endl;
    subt[v] += Dfs(e.first, v, e.second);
  }
  if (w >= 0) {
    li used = (total - subt[v]) * subt[v];
    while (w >= len(ans)) {
      ans.push_back(0);
    }
    ans[w] += used;
  }
  cout<<"v:"<<v<<" reach1:"<<subt[v]<<" reach2:"<<(total-subt[v])<<endl;
  cout<<"=============================================="<<endl;
  return subt[v];
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  total = n;
  vector<pair<int, pt>> edges;
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    --x, --y;
    edges.push_back({w, {x, y}});
    g[x].push_back({y, w});
    g[y].push_back({x, w});  
  }
  sort(edges.begin(), edges.end());

  DSU dsu(n);
  for (auto &e : edges) {
    int x = e.second.first;
    int y = e.second.second;
    int u = dsu.Parent(x);
    int v = dsu.Parent(y);
    if (u != v) {
      tree[x].push_back({y, e.first});
      tree[y].push_back({x, e.first});
      cout<<"x:"<<x<<" y:"<<y<<" edge wt:"<<e.first<<endl;
      cout<<"x:"<<y<<" y:"<<x<<" edge wt:"<<e.first<<endl;
      dsu.Union(u, v);
    }
  }
  // for(int u=0;u<n;u++){
  //   for(int j=0;j<tree[u].size();j++){
  //     int v = tree[u][j].first;
  //     int wt = tree[u][j].second;
  //     cout<<"u:"<<u<<" v:"<<v<<" wt:"<<(1<<wt)<<endl;  
  //   }
  // }
  cout<<"-------------------------"<<endl;
  Dfs(0, -1, -1);

  li r = 0;
  for (int i = 0; i < len(ans) || r; ++i) {
    while (i >= len(ans)) {
      ans.push_back(0);
    }
    r += ans[i];
    ans[i] = r & 1;
    r >>= 1;
  }
  bool started = false;
  for (int i = len(ans) - 1; i >= 0; --i) {
    bool on = ans[i] > 0;
    if (on) {
      started = true;
    }
    if (started) {
      putchar(on ? '1' : '0');
    }
  }
  if (!started) {
    puts("0");
  } else {
    puts("");
  }
  return 0;
}