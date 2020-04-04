int par[10005], money[10005], n, m, sum;

int unionfind(int r){
    if(par[r] == r) return r;
    return par[r] = unionfind(par[r]);
}

main(int argc, char const* argv[])
{
    DI(T);
    while(T--){

        DII(n, m);

        fl(i, 1, n+1) par[i] = i;
        fl(j, 1, n+1){
            DI(p);
            money[j] = p;
        }
        sum = -1;
        for(int e = 1; e <= m; e++){
            DII(x, y);
            int u, v;

            u = unionfind(x+1);
            v = unionfind(y+1);

            if(u != v)
            {
                par[v] = u;
                money[u] += money[v];

                sum = money[u];
            }
        }

        P("%s\n", (!sum)?"POSSIBLE":"IMPOSSIBLE");
    }
}
