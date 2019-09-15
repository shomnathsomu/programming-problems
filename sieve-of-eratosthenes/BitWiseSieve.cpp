template < class T, class X > inline bool checkbit(T a, X pos)  { T t=1;return (a&(t<<pos));     }
template < class T, class X > inline  T   onbit(T a, X pos)     { T t=1;return (a|(t<<pos));     }

const int MAX = 46342;

int i,j,p;
int vis[(MAX/32) + 2], prm[4795];

void sieve(){

    prm[p++] = 2;
    for(i = 3; i*i <= MAX; i += 2){
        if(CheckBit(vis[i>>5], i&31)==0){
            prm[p++] = i;
            for(j = i*i; j <= MAX; j += (i<<1)) vis[j>>5] = OnBit(vis[j>>5], j&31);
        }
    }
    for(; i <= MAX; i+=2) if(CheckBit(vis[i>>5], i&31)==0) prm[p++] = i;

}
