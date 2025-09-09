//The number of vertices (V) equals the number of edges (E) in a connected component.
//Every vertex has a degree of exactly two.

#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAXN = 200005;
vector<int> adj[MAXN];
bool vis[MAXN];
 
// Flag to check if the component is a simple cycle
bool is_cyclic_component = true;
 
void dfs(int u) {
    vis[u] = true;
 
    // Check if the current vertex has a degree of exactly 2
    if (adj[u].size() != 2) {
        is_cyclic_component = false;
    }
 
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int cyclic_components_count = 0;
 
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            is_cyclic_component = true;
            dfs(i);
 
            // A component is a simple cycle if all its vertices have a degree of 2,
            // and it has at least 3 vertices.
            if (is_cyclic_component && adj[i].size() == 2) {
                cyclic_components_count++;
            }
        }
    }
 
    cout << cyclic_components_count << endl;
 
    return 0;
}
