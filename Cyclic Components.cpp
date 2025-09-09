The number of vertices (V) equals the number of edges (E) in a connected component.
Every vertex has a degree of exactly two.

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
bool vis[MAXN];
int component_verts = 0;

void dfs(int u, bool &all_degrees_two) {
    vis[u] = true;
    component_verts++;

    if (adj[u].size() != 2) {
        all_degrees_two = false;
    }
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, all_degrees_two);
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
            component_verts = 0;
            bool all_degrees_two = true;
            dfs(i, all_degrees_two);
            if (all_degrees_two && component_verts >= 3) {
                cyclic_components_count++;
            }
        }
    }

    cout << cyclic_components_count << endl;

    return 0;
}
