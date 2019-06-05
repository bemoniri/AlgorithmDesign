#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

# define V 900
int SUM = 0;
int n, m;
int max_flow = 0;


int bfs(int rGraph[V][V], int siz, int s, int t, int parent[]);
void fordFulkerson(int graph[V][V], int siz, int s, int t);


int main() {
    int graph[V][V] = {0};

    cin >> n >> m;
    int a[n] = {0};
    int b[n] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        SUM = SUM + a[i];
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];


    for (int i = 1; i <= n; i++) {
        graph[0][i] = a[i - 1];
        graph[i + n][2 * n + 1] = b[i - 1];
        graph[i][i + n] = INT_MAX;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y + n] = INT_MAX;
        graph[y][x + n] = INT_MAX;
    }


    int rGraph[V][V] = {0};

    for (int j = 0; j < 2*n+2; j++){
        for (int i = 0; i < 2*n+2; i++) {
            rGraph[j][i] = graph[j][i];
        }
    }

    fordFulkerson(rGraph, 2 * n + 2, 0, 2 * n + 1);

}

int bfs(int rGraph[V][V], int siz, int s, int t, int parent[]) {
    int visited[V] = {0};
    int dist[V] = {INT_MAX};

    queue<int> q;
    q.push(s);

    visited[s] = 1;
    parent[s] = -1;
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < siz; v++) {
            if (visited[v]) continue;
            if (rGraph[u][v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return visited[t];
}

void fordFulkerson(int rGraph[V][V], int siz, int s, int t) {

    int parent[siz];
    int u, v;

    while (bfs(rGraph, siz, s, t, parent) == 1) {
        int bottleneck = INT_MAX;
        v = t;
        do{ // Find bottleneck in path
            u = parent[v];
            if (rGraph[u][v] < bottleneck)
                bottleneck = rGraph[u][v];
            v = parent[v];
        } while (v != s);

        v = t;
        do{ // augment path
            u = parent[v];
            rGraph[v][u] = rGraph[v][u] + bottleneck;
            rGraph[u][v] = rGraph[u][v] - bottleneck;
            v = parent[v];
        } while (v != s);
    }

    for (int i = 1; i<=n; i++)
        max_flow += rGraph[0][i];

    if (max_flow == 0)
        cout << "YES" << endl;

    else {
        cout << "NO" << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            cout << rGraph[j][i] << " ";
        }
        cout << endl;
    }
}