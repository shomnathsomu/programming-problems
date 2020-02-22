int n, t, m, f, l, t1, t2, t3, tmp, cnt, ans, vis[30], taken[30];
char ds[30], dc[30];
vi res, area, adj[30];

main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    while(S1(n) == 1) {
        FL(u, 0, 28) adj[u].clear();
        S1(m);
        S("%s", &ds);
        l = strlen(ds);
        area.clear();
        FL(i, 0, l) {
            t = ds[i] - 'A';
            area.pb(t);
            vis[t] = 1, taken[t] = 1;
        }

        FL(i1, 0, m) {
            S("%s", &dc);
            t1 = dc[0] - 'A';
            t2 = dc[1] - 'A';

            adj[t1].pb(t2);
            adj[t2].pb(t1);

            if(!taken[t1]) area.pb(t1);
            if(!taken[t2]) area.pb(t2);

            taken[t1] = 1;
            taken[t2] = 1;
        }

        ans = 0;
        FL(j, 0, area.sz())
        {
            FL(j1, 0, area.sz())
            {
                t3 = area[j1];
                if(vis[t3]) continue;
                cnt = 0;
                FL(k, 0, adj[t3].size())
                {
                    tmp = adj[t3][k];
                    if(vis[tmp]) cnt++;
                    if(cnt == 3)
                    {
                        res.pb(t3);
                        break;
                    }
                }
            }
            if(res.size()) ans++;
            FL(k1, 0, res.size()) vis[ res[k1] ] = 1;
            res.clear();
        }
        f=0;
        FL(k2, 0, area.sz()) if(vis[area[k2]]) f++;
        if(f == n) P("WAKE UP IN, %d, YEARS\n", ans);
        else P("THIS BRAIN NEVER WAKES UP\n");
        CLR(vis);
        CLR(taken);
    }
}
