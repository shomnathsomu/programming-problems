#include <bits/stdc++.h>
using namespace std;

vector <int> node[10000];
int vis[10000];

int BFS(int Start, int End)
{
    queue <int> q;
    q.push(Start);

    vis[Start] = 0;

    while(!q.empty())
    {
        int nxt = q.front();
        q.pop();

        for(int j = 0; j < node[nxt].size(); j++)
        {
            int temp = node[nxt][j];
            if(!vis[temp])
            {
                vis[temp] = vis[nxt] + 1;
                q.push(temp);
                if(temp == End) return vis[temp];
            }
        }
    }

    return 0;
}

int main()
{
    int num_edge;

    cin >> num_edge;

    for(int i = 0; i < num_edge; i++){
        int x, y;
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }

    int st, en;

    cin >> st >> en;

    int ans;

    ans = BFS(st, en);

    cout << ans << endl;

    return 0;
}

/*

14
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
1 11

*/
