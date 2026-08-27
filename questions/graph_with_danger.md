given a graph where every edge have a danger level d.
danger level of a path is defined as the maximum danger level among all edges.

find the shortest path from src to dst such that the danger level of path is minimum.

// approach

state dijstraka + bs
set<dist,node,max danger level till now>

use bs to get D.

dist[1][0]=0;
while(!s.empty()){
[d,u,dg]
if(dist[u][dg]!=d) continue;
for([v,w,dv]){
if(dv<D && d+w<dist[v][max(dv,dg)])
dist[v][max(dv,dg] = d+w;
s.insert()
}
}

Problem: Safest Cheapest Route

You are given a directed graph with n nodes and m edges. Each edge (u, v) has two values: a cost w and a danger level d.

Define the danger level of a path as the maximum danger level among all edges used in that path.

Among all paths from node 1 to node n, first find the minimum possible danger level achievable (i.e., the smallest value D such that some path from 1 to n uses only edges with danger ≤ D).

Then, among all paths that achieve this minimum danger level, find the one with minimum total cost.

Output two numbers: the minimum achievable danger level, and the minimum cost among paths achieving it.

```c++
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int,3>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w, d;
        cin >> u >> v >> w >> d;
        g[u].push_back({v, w, d});
        g[v].push_back({u, w, d});
    }

    const long long INF = 4e18;
    vector<pair<long long,long long>> dist(n + 1, {INF, INF});  // (danger, cost)
    dist[1] = {0, 0};

    set<pair<pair<long long,long long>, int>> s;  // {(danger,cost), node}
    s.insert({{0, 0}, 1});

    while (!s.empty()) {
        auto [state, u] = *s.begin();
        s.erase(s.begin());
        if (dist[u] != state) continue;   // stale check

        auto [dg, cost] = state;
        for (auto &e : g[u]) {
            int v = e[0], w = e[1], dv = e[2];
            pair<long long,long long> newState = {max(dg, (long long)dv), cost + w};
            if (newState < dist[v]) {          // lexicographic compare
                dist[v] = newState;
                s.insert({newState, v});
            }
        }
    }

    if (dist[n].first == INF) cout << "unreachable\n";
    else cout << dist[n].first << " " << dist[n].second << "\n";
}
```
