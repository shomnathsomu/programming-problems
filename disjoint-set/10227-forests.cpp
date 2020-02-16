char s[6];
int x, y, vis[101], res;
set <int> pe0ple[101];

main(int argc, char const* argv[])
{
    DI(T);
    gch;
    while(T--){
        DII(p, t);
        gch;

        res = 0;
        fl(k, 1, p+1) pe0ple[k].clear();
        CLR(vis);

        while(gets(s)){
            if(!strlen(s)) break;
            stringstream ss(s);
            ss >> x >> y;
            pe0ple[x].insert(y);
      }

        fl(i, 1, p+1){
            if(!vis[i]){
                res++;
                fl(j, i+1, p+1){
                    if(pe0ple[i] == pe0ple[j]) vis[j] = 1;
                }
            }
        }

        PI(res);
        if(T) nl;
    }
}
