/**____________________________________________________ |
|                                                       |
|            Email:shomnathcse22@gmail.com              |
|    Codeforces == L1nK1n_ && Topcoder == L1nK1n        |
|_______________________________________________________**/
//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1007;
const int MAXE = 2007;
const int inf = (1<<31)-1;

int node, edge, d[MAXN];
int edge_u[MAXE], edge_v[MAXE], edge_cost[MAXE];

bool BellmanFord(){

    for (int jj=2; jj < node+1; jj++)
        d[jj] = inf;

    d[1] = 0;

    bool neg_cycle = false;

    for(int step = 1; step <= node; step++){

        bool updated = false;
        for(int j = 1; j <= edge; j++){

            int u = edge_u[j], v = edge_v[j];
            if(d[u] + edge_cost[j] < d[v]){

                updated = true;
                if(step == node){
                    neg_cycle = true;
                    return neg_cycle;
                }
                d[v] = d[u] + edge_cost[j];

            }

        }
        if(updated == false) break;

    }

    return neg_cycle;

}

int main(int argc, const char *argv[]) {

    int cs, a, b, c;
    scanf("%d", &cs);

    for(int ii=1; ii<cs+1; ii++){

        scanf("%d%d", &node, &edge);

        for(int i=1; i<edge+1; i++){
            scanf("%d%d%d", &a,&b,&c);
            edge_u[i] = a+1;
            edge_v[i] = b+1;
            edge_cost[i] = c;
        }

        printf("%s\n", BellmanFord() ? "possible" : "not possible");

    }

}
