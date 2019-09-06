#include<bits/stdc++.h>
using namespace std;

int Start, End, initial;
int vis[1000];
int f = 0, cnt = 0, g = 0;

vector <int> v[1000];

void dfs(int initial)
{
    vis[initial] = 1;
    for(int i = 0; i < v[initial].size(); i++){
        cnt++;
        int temp = v[initial][i];
        if(temp == End){
            g = max(g, cnt);
            f = 1;
        }
        if(!vis[temp]) dfs(temp);
    }
}

main()
{
    int edge, a, b;
    cin >> edge;

    for(int i = 0; i < edge; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> Start >> End;

    dfs(Start);

    if(f) cout << "Yes ---- " << g << endl;
    else cout << "No\n";

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
