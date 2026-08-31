#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define ar array
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
int dr[] = {0, -1, 1, 0};
int dc[] = {-1, 0, 0, 1};

class Solution {
public:
  int n, m;
  vector<vector<int>> tin;
  vector<vector<int>> tlow;
  int timer = 0;
  int bridge = 0;
  void dfs(int i, int j, int pi, int pj, vector<vector<int>> &g) {
    tin[i][j] = tlow[i][j] = timer++;
    for (int k = 0; k < 4; k++) {
      int nr = i + dr[k];
      int nc = j + dc[k];
      if (nr < 0 || nc < 0 || nr >= m || nc >= n)
        continue;
      if (g[nr][nc] == 0)
        continue;
      if (nr == pi && nc == pj)
        continue;
      if (tin[nr][nc] == -1) {
        dfs(nr, nc, i, j, g);
        tlow[i][j] = min(tlow[i][j], tlow[nr][nc]);
        if (tlow[nr][nc] > tin[i][j])
          bridge++;
      } else {
        tlow[i][j] = min(tlow[i][j], tin[nr][nc]);
      }
    }
  }
  int minDays(vector<vector<int>> &g) {
    m = sz(g);
    n = sz(g[0]);
    tin.assign(m, vi(n, -1));
    tlow.assign(m, vi(n, -1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == 1) {
          dfs(i, j, -1, -1, g);
        }
      }
    }
    return bridge;
  }
};
