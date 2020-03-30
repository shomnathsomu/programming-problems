int par[MX], num[MX], k;
char s1[22], s2[22];
map <string, int> mp;

int unionfind(int r){
    if(par[r] == r) return r;
    return par[r] = unionfind(par[r]);
}

main(int argc, char const* argv[])
{
    DI(T);

    while(T--){
        DI(F);
        fl(i, 1, F+1){
            par[i] = i;
            num[i] = 1;
        }
        getchar();
        mp.clear();
        k = 1;
        fl(i1, 0, F){
            int u, v, x, y;
            S("%s %s", &s1, &s2);

            if(!mp[s1]) mp[s1] = k++;
            if(!mp[s2]) mp[s2] = k++;

            x = mp[s1];
            y = mp[s2];

            u = unionfind(x);
            v = unionfind(y);

            if(u!=v){
                par[v] = u;
                num[u] += num[v];
            }
            PI(num[u]);
        }
    }
}
