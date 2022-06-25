
const int MX  = 1e6 + 7;
int vis[MX], prm[MX];
int i, j, p;

void sieve()
{
    prm[p++] = 2;
    for(i = 3; i*i <= MX; i+=2){
        if(!vis[i]){
            prm[p++] = i;
            for(j = i*i; j <= MX; j += (i<<1)) vis[j] = 1; /// i<<1 equivalent to 2*i
        }
    }
    for(; i < MX; i+=2) if(!vis[i]) prm[p++] = i;

}


