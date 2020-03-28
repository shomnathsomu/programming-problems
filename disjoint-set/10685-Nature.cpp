int par[5005], num[5005], res, c, r, k1;
char s[5005][5005], s1[5005], s2[5005];
map <string, int> mp;

int unionfind(int r){
    if(par[r] == r) return r;
    return par[r] = unionfind(par[r]);
}

main(int argc, char const* argv[])
{
    while(~S2(c, r))
    {
        if(!c && !r) break;
        fl(k, 0, c) {par[k] = k; num[k] = 1;}
        fl(i, 0, c) scanf("%s", s[i]);
        res = 1, k1 = 1;
        fl(j, 0, r)
        {
            scanf("%s%s", &s1,&s2);
            int u, v, x, y;

            if(!mp[ s1 ]) mp[ s1 ] = k1++;
            if(!mp[ s2 ]) mp[ s2 ] = k1++;

            x = mp[ s1 ];
            y = mp[ s2 ];

            u = unionfind(x);
            v = unionfind(y);

            if(u != v)
            {
                par[v] = u;
                num[u] += num[v];

                res = max(res, num[u]);
            }
        }
        PI(res);
        mp.clear();
        CLR(par);
        CLR(num);
    }

}
