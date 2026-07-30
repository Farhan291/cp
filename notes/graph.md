## some best problem

- https://www.luogu.com.cn/problem/P8063
- https://cses.fi/problemset/task/1202/
- https://cses.fi/problemset/task/1196/
- https://cses.fi/problemset/task/1195
- https://cses.fi/problemset/task/1680/
- https://www.spoj.com/problems/BUGLIFE/
- https://leetcode.com/submissions/detail/2065124319/
- https://leetcode.com/problems/path-with-minimum-effort/description/

## topo order mixed with dp

- https://codeforces.com/problemset/problem/825/E (must try)
- https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
- https://cses.fi/problemset/task/1757

two most important thing is dfs and bfs

## dfs using adj list

```cpp
void dfs(vector<vector<int>> &v, int vertex, vector<bool> &visited) {
  visited[vertex] = true;
  for (auto child : v[vertex]) {
    if (visited[child] == false) {
      dfs(v, child, visited);
    }
  }
}

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1);
  vector<bool> visited(n + 1, false);
  vector<int> bridges;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(v, i, visited);
      bridges.pb(i);
    }
  }
  cout << bridges.size() - 1 << nl;
  for (int i = 1; i < sz(bridges); i++) {
    cout << bridges[i - 1] << " " << bridges[i] << nl;
  }
}
```

## dfs on matrix

just dfs on neighbour up down left right

```
void dfs(vector<vector<int>>& mat , int i,int j, int oc,int nc){
    int m = mat.size();
    int n = mat[0].size();
    if(i<0 || j < 0 || i >=m || j>=n) return;
    if(mat[i][j]!=oc) return;
    mat[i][j]=nc;
    dfs(mat,i-1,j,oc,nc);
    dfs(mat,i+1,j,oc,nc);
    dfs(mat,i,j-1,oc,nc);
    dfs(mat,i,j+1,oc,nc);
   }
```

## cycle dection in undirected graph using dfs

```cpp
 bool dfs(vector<vector<int>>&v,int ve,vector<bool>&b,int parent){
        b[ve]=true;
        for(auto x:v[ve]){
            if(!b[x]){
                if(dfs(v,x,b,ve))
                return true;
            }
            else if(x!=parent){
                    return true;
                }
            }
        return false;
    }
```

## bfs using adj list

```cpp
void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1);
  vector<bool> visited(n + 1, false);
  queue<int> q;
  vector<int> parent(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    int vertex = q.front();
    q.pop();
    for (auto child : v[vertex]) {
      if (!visited[child]) {
        visited[child] = true;
        q.push(child);
        parent[child] = vertex;
      }
    }
  }
  if (!visited[n]) {
    cout << "IMPOSSIBLE" << nl;
    return;
  }
  vector<int> path;
  for (int i = n; i != -1; i = parent[i]) {
    path.pb(i);
  }
  reverse(all(path));
  cout << path.size() << nl;
  for (auto x : path) {
    cout << x << " ";
  }
  cout << nl;
}
```

## bfs on matrix

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int  m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        int dr[]= {-1,0,0,1};
        int dc[]= {0,-1,1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    mat[i][j]=2;
                }
            }
        }
        vector<vector<int>> level(m,vector<int>(n,0));
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int tr = i+dr[k];
                int tc = j+dc[k];
                if(tr<0 || tc<0 || tr>=m || tc>=n) continue;
                if(mat[tr][tc]!=1) continue;
                mat[tr][tc]=2;
                level[tr][tc]=level[i][j]+1;
                q.push({tr,tc});
            }
        }
        return level;

    }
};
```

## topo sort using bfs

```cpp
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> g(V);
        vector<int> indeg(V,0);
        for(int i=0;i<edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];
            g[v].push_back(u);
            indeg[u]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int z = q.front();
            order.push_back(z);
            q.pop();
            for(auto x:g[z]){
                indeg[x]--;
                if(indeg[x]==0) q.push(x);
            }
        }
        return order;
    }
};
```

## cycle dection in dag using bfs

same as topo order

## bipartie graph using dfs

```cpp
bool dfs(vector<vector<int>> &v, int ve, vector<int> &b, int color) {
  b[ve] = color;
  for (auto x : v[ve]) {
    if (b[x] == -1) {
      if (!dfs(v, x, b, 1 - color)) {
        return false;
      }
    } else if (b[x] == color)
      return false;
  }
  return true;
}

void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1);
  vector<int> b(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == -1) {
      bool ans = dfs(v, i, b, 0);
      if (!ans) {
        cout << "Suspicious bugs found!" << nl;
        return;
      }
    }
  }
  cout << "No suspicious bugs found!" << nl;
}

```

## shortest path using dijstraka

```cpp
void Mizuhara() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  set<pair<int, int>> s;
  vector<int> dist(n + 1, 4e18);
  vector<int> parent(n + 1, -1);
  dist[1] = 0;
  s.insert({0, 1});
  while (!s.empty()) {
    auto x = *s.begin();
    int u = x.second;
    int d = x.first;
    s.erase(x);
    if (dist[u] != d)
      continue;
    for (auto z : g[u]) {
      if (dist[u] + z.second < dist[z.first]) {
        dist[z.first] = dist[u] + z.second;
        parent[z.first] = u;
        s.insert({dist[z.first], z.first});
      }
    }
  }
  vector<int> path;
  int cur = n;
  while (cur != -1) {
    path.pb(cur);
    cur = parent[cur];
  }
  reverse(all(path));
  if (dist[n] == 4e18) {
    cout << -1 << nl;
    return;
  }
  cout << dist[n] << nl;
  for (auto x : path) {
    cout << x << " ";
  }
}
```
