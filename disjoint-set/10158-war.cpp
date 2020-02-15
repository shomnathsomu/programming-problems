int par[MX], p, q, u, v, c, x, y;

int unionfind(int r){
    if(par[r] == r) return r;
    return par[r] = unionfind(par[r]);
}

main(int argc, char const* argv[])
{
    DI(n);

    fl(i, 0, 2*n) par[i] = i;

    while(S3(c, x, y)==3){
        if(!c && !x && !y) break;

        u = unionfind(x);
        v = unionfind(y);
        p = unionfind(x+n);
        q = unionfind(y+n);

        if(c == 1){
            if(u == q || v == p) P("-1\n");
            else {
                par[v] = u;
                par[q] = p;
            }
        }
        else if(c == 2){
            if(u == v || p == q) P("-1\n");
            else {
                par[q] = u;
                par[p] = v;
            }
        }
        else if(c == 3){
            if(u == v || p == q) P("1\n");
            else P("0\n");
        }
        else if(c == 4){
            if(u == q || v == p) P("1\n");
            else P("0\n");
        }
    }
}
