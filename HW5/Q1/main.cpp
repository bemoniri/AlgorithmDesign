#include <bits/stdc++.h>
#include <queue>

using namespace std;
int v, m, d;

void add_edge(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}
int farthest_marked(int marked[], int dist []) {
    int max_dist = -1;
    int max_index = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (dist[marked[i]] > max_dist) {

            max_dist = dist[marked[i]];
            max_index = marked[i];
        }
    }
    return max_index;
}
int BFS(vector<int> adj[], int src, int v, int dist[]);

int main()
{
    //cout<<"NumVertices    NumMarked    MaxDist"<<endl;

    cin >> v;
    cin >> m;
    cin >> d;

    vector<int> adj[v];
    int marked_vertices[m];

    //cout<<"Enter Marked:"<<endl;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x ;
        marked_vertices[i] = x - 1;
    }

    //cout<<"Enter Edges:"<<endl;
    int E =  v - 1; //tree
    for (int i = 0; i < E; i++){
        int t1, t2;
        cin >> t1;
        cin >> t2;
        add_edge(adj, t1-1, t2-1);
    }


    // First BFS from a random node (node 0)
    int dist[v] = {0};
    BFS(adj, 1, v, dist);

    // Find Farthest Marked Node
    //for (int i = 0; i < v; i++)   cout <<dist[i]<<"   ";

    int F1 =  farthest_marked(marked_vertices, dist);

    // BFS from F1 to find F2
    int dist1[v] = {0};
    BFS(adj, F1, v, dist1);
    int F2 =  farthest_marked(marked_vertices, dist1);
    // for (int i = 0; i < v; i++)   cout <<dist1[i]<<"   ";

    // BFS from F2
    int dist2[v] = {0};
    BFS(adj, F2, v, dist2);
    //for  (int i = 0; i < v; i++)   cout <<dist2[i]<<"   ";

    int num = 0;
    for (int i = 0; i < v; i++){
        if (dist1[i] <= d && dist2[i] <= d) {
            //cout << dist1[i] << dist2[i];
            num++;
        }
    }
    cout<<num;
    return 0;
}

int BFS(vector<int> adj[], int src, int v, int dist[])
{

    queue<int> q;
    int visited[v] = {0};
    int parents[v] = {0};

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;

    visited[src] = 1;
    dist[src] = 0;
    parents[src] = -1;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < adj[u].size(); v++) {
            if (visited[adj[u][v]]) continue;
            visited[adj[u][v]] = 1;
            parents[v] = u;
            dist[adj[u][v]] = dist[u] + 1;
            q.push(adj[u][v]);
        }
    }
    return 1;
}