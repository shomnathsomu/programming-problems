///===========================///
///                           ///
///    UserID : L1nK1n        ///
///    Institution : CSE, JU  ///
///                           ///
///===========================///
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>

#define P   printf
#define S   scanf
#define D   double
#define ll  long long
#define ull unsigned long long

///...Input...///
#define S1(a)      scanf("%d",&a)
#define S2(a,b)    scanf("%d%d",&a,&b)
#define S3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
#define SL1(a)     scanf("%lld",&a)
#define SL2(a,b)   scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

///...Declared Input...///
#define DI(X)          int X;      scanf("%d", &X)
#define DII(X, Y)      int X,Y;    scanf("%d%d", &X, &Y)
#define DIII(X, Y, Z)  int X,Y,Z;  scanf("%d%d%d", &X, &Y, &Z)
#define DLI(X)         ll X;       scanf("%lld", &X)
#define DLII(X, Y)     ll X,Y;     scanf("%lld%lld", &X, &Y)
#define DLIII(X, Y, Z) ll X,Y,Z;   scanf("%lld%lld%lld", &X, &Y, &Z)

///...Loop...///
#define fl(i, a, b)      for(int i=a; i<b; i++)
#define rfl(i, a)        for(int i=a; i>=0; i--)
#define fli(i,a,b,inc)   for(int i=a; i<=b; i+=inc)
#define fld(i,a,b,dec)   for(int i=a; i>=b; i-=dec)
#define FS(x)            for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x)            for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) cout << *it << " "; cout << endl;

///...Minimum/Maximum...///
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mxe(a,n)   (*max_element(a,a+n))
#define mne(a,n)   (*min_element(a,a+n))

///...PrintCase...///
#define PC(a)      printf("Case %d: ",a)
#define PCN(a)     printf("Case %d:\n",a)
#define PCH(a)     printf("Case #%d: ",a)

///...Pair...///
#define xx  first
#define yy  second
#define MP  make_pair
#define vi  vector< int >
#define vii vector< vi >
#define vll vector< ll >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define vpi vector< pii >

///...Reseting Array...///
#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a)     memset(a,-1,sizeof a)
#define CLR(a)     memset(a,0,sizeof a)

///...Binary Search...///
#define ub       upper_bound
#define lb       lower_bound
#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())

///...Other Operations...///
#define PI(x)      printf("%d\n", x)
#define PL(x)      printf("%lld\n", x)
#define pi         2.0*acos(0.0)
#define eps        1e-11
#define sqr(n)     n*n
#define all(a)     a.begin(),a.end()
#define nl         P("\n")
#define check      P("here\n")
#define gch        getchar()
#define pb         push_back
#define pp         pop_back
#define PF(x)      push_front(x)
#define PPF(x)     pop_front()
#define ps(x)      push(x)
#define sz()       size()
#define SUM(a,n)   accumulate(a,a+n,0)
#define countbit(x) __builtin_popcount(x)
#define dbug(n)    P("Done %d\n",n);
#define READ(f)    freopen(f, "r", stdin)
#define WRITE(f)   freopen(f, "w", stdout)

using namespace std;

///...Mathematics...///
template <typename T> T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod(T b,T p,T m){if(p==0) return 1;if(p%2==0){T s=BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;} //linKin//
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return sqr(POW(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b){if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T ModInv(T b,T m){ return BigMod(b,m-2,m); }

///...Geometry...///
double DEG(double x) { return (180.0*x)/(pi); }
double RAD(double x) { return (x*(double)pi)/(180.0); }
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( sqr(abs(x1-x2)) + sqr(abs(y1-y2)) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }

///...Bit Operation...///
template< class T, class X > inline bool checkbit(T a, X pos)   { T t=1;return ((a&(t<<pos))>0); }
template< class T, class X > inline  T   onbit(T a, X pos)      { T t=1;return (a|(t<<pos));     }
template< class T, class X > inline  T   offbit(T a, X pos)     { T t=1;return (a&(~(t<<pos)));  }
template< class T, class X > inline  T   togglebit(T a, X pos)  { T t=1;return (a^(t<<pos));     }

///...String Operation...///
int cdigittoint(char ch){ return ch-'0'; }
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
ll toLlint(string s) { ll sm; stringstream ss(s); ss>>sm; return sm; }
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false; }
bool isConst(char ch){ if (isalpha(ch) && !isVowel(ch)) return true; return false; }
template <class T> string NTS ( T Number ){stringstream ss;ss << Number;return ss.str();}
bool isprime(int w){if(w == 0) return false;if(w == 1) return false;int sqrtw = int(sqrt((double)w));for(int q = 2; q <= sqrtw; q++){if(w % q == 0) return false;}return true;}

///...Debuging...///
template <typename T> T iArray(T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> T pArray(T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9') break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9') break;}return (ng?-n:n);}

///...Derection...///
//int dx[]={0,1,0,-1};int dy[]={1,0,-1,0};                       //4 Direction//
//int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};           //Year Derection//
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2};     //Hexagonal Direction//
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};   //8 Direction//
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction//

void solution()
{
    ///ios_base::sync_with_stdio(0); cin.tie(0);
    ///READ("input.txt");
    ///WRITE("output.txt");
}

const ll MOD = 1000000007;
const int MX = 1000007;
const int INF = INT_MAX;
const ll LINF = LONG_LONG_MAX;

///.............End Of Template..............////

ll prm[80000], vis[MX+9];
int idx=1, i, j, k, cnt, temp;
void sieve()
{
    prm[0] = 2;
    for(i = 3; (ll)i*i <= MX; i+=2){
        if(!vis[i]){
            prm[idx++] = i;
            for(j = i+i; j <= MX; j+=i){
                vis[j] = 1;
            }
        }
    }
    for(; i <= MX; i+=2) if(!vis[i]) prm[idx++] = i;
}

main(int argc, char const* argv[])
{
    sieve();
    DI(n);

    for(k = 0; (ll)prm[k] <= n; k++){
        temp = n;
        cnt = 0;
        while(temp){
            cnt += (temp / prm[k]);
            temp /= prm[k];
        }
        cout << prm[k] << ' ' << cnt << endl;
    }
}
