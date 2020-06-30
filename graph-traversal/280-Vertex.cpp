int n, x, y, cnt, vis[111];
vector <int> v[111];

void DFS(int start){

    for(int i = 0; i < v[start].size(); i++){

        int u = v[start][i];
        if(!vis[ u ]){
            vis[ u ] = 1;
            DFS(u);
        }

    }
    return;
}

main(int argc, const char * argv[]) {

    while(~scanf("%d", &n) && n){

        while(scanf("%d", &x) && x){
            while(scanf("%d", &y) && y){
                v[x].push_back(y);
            }
        }

        DI(h);

        FL(i,0,h) {
            DI(b);
            cnt=0;
            CLR(vis);
            DFS(b);
            FL(i1,1,n+1) if(!vis[i1]) cnt++;
            printf("%d", cnt);
            FL(j,1,n+1) if(!vis[j]) printf(" %d", j);
            nl;
        }

        FL(k,1,n+1) v[k].clear();

    }


}
