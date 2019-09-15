#include <bits/stdc++.h>
using namespace std;

const int mx = 100100;
const long long INF = 1e18;

vector <int> g[mx], cost[mx];

struct node
{
    int z, w;
    node(int x, int y){z = x;w = y;}
    bool friend operator < (node a, node b){
        return a.w > b.w;
    }
};

long long int d[mx], par[mx];

int dijkstra(int n)
{
    memset(d, 63, sizeof d);
    memset(par, -1, sizeof(par));

    priority_queue <node> q;

    q.push(node(1, 0));
    d[1] = 0;

    while(!q.empty())
    {
        node top = q.top();
        q.pop();

        int u = top.z;
        if(u == n) return d[n];

        for(int i = 0; i < (int)g[u].size(); i++)
        {
            int v = g[u][i];
            if(d[u] + cost[u][i] < d[v])
            {
                d[v] = d[u] + cost[u][i];
                par[v] = u;
                q.push(node(v, d[v]));
            }
        }
    }
    return -1;
}
int main()
{
    int n, e;

    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    int ret = dijkstra(n);

    if(ret == -1) puts("No path!");
    else
    {
        int u = n;
        vector <int> out;
        while(u != -1)
        {
            out.push_back(u);
            u = par[u];
        }

        cout << "cost = " << ret << endl;

        reverse(out.begin(), out.end());

        for(int i = 0; i < out.size(); i++)
            cout << out[i] << " ";

        cout << endl;
    }
}
