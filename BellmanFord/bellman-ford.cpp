// A C++ program for Bellman-Ford's single source 
// shortest path algorithm.

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
