#include <bits/stdc++.h>
#define DI(X) int X; scanf("%d", &X)
#define fl(i, a, b) for(int i=a; i<b; i++)
using namespace std;

int par[MX], res1, res2, u, v;
char c;

int unionfind(int r){
    if(par[r] == r) return r;
    return par[r] = unionfind(par[r]);
}

main(int argc, char const* argv[])
{
    DI(T);
    while(T--){
        DI(n);
        getchar();
        fl(i, 1, n+1) par[i] = i;
        res1=0, res2=0;
        while(~scanf("%c", &c)){
            if(c == '\n') break;
            DII(x, y);
            getchar();

            u = unionfind(x);
            v = unionfind(y);

            if(c == 'q'){
                if(u != v) res2++;
                else res1++;
            }
            else if(c == 'c'){
                if(u != v){
                    par[v] = u;
                }
            }
        }
        P("%d,%d\n", res1, res2);
        if(T) nl;
    }
}
