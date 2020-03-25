int par[50005], cs=0, cnt, n, m;

int unionfind(int r){
    if(par[r] == r) return r;
    return par[r] = unionfind(par[r]);
}

main(int argc, char const* argv[])
{
    while(~S("%d%d", &n, &m)){
        if(!n && !m) break;
        fl(i, 1, n+1) par[i] = i;
        cnt = n;

        for(int e = 1; e <= m; e++){
            DII(x, y);
            int u, v;

            u = unionfind(x);
            v = unionfind(y);

            if(u != v)
            {
                par[v] = u;
                cnt--;
            }
        }

        PC(++cs);
        PI(cnt);
    }
}
