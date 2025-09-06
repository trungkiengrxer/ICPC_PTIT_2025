#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define ll long long
#define Matrix vector<vector<int>>

using namespace std;

bool bfs(Matrix& residualGraph, int source, int sink, int par[], int n) {
    bool visited[n];

    fill(visited, visited + n, false);
    fill(par, par + n, -1);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    par[source] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v = 0; v < n; v++) {
            if(visited[v] == false && residualGraph[u][v] > 0) {
                if(v == sink) {
                    par[v] = u;
                    return true;
                }
                
                q.push(v);
                par[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int FordFulkerson(Matrix& graph, int source, int sink, int n) {
    int u, v;

    Matrix residualGraph = graph; // residual graph
    int par[n]; // parent array
    int max_flow = 0;

    while(bfs(residualGraph, source, sink, par, n)) {
        int path_flow = INT_MAX;

        for(v = sink; v != source; v = par[v]) {
            u = par[v];
            path_flow = min(path_flow, residualGraph[u][v]);
        }

        for(v = sink; v != source; v = par[v]) {
            u = par[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

void solve(){
    int n;
    cin >> n;

    Matrix graph(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];
    
    int source = 0, sink = n - 1;
    cout << "Max Flow: " << FordFulkerson(graph, source, sink, n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}