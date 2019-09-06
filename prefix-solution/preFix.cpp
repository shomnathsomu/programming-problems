/**____________________________________________________ |
|                                                       |
|            Email:shomnathcse22@gmail.com              |
|    Codeforces == L1nKin && Topcoder == L1nK1n         |
|_______________________________________________________**/
///#pragma warning (disable: 4786)
///#pragma comment (linker, "/STACK:16777216")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
#include <valarray>

#define ll             long long int
#define ULL            unsigned long long int

#define S1(A)          scanf("%d",&A)
#define S2(A,B)        scanf("%d%d",&A,&B)
#define S3(A,B,C)      scanf("%d%d%d",&A,&B,&C)
#define SL1(A)         scanf("%lld",&A)
#define SL2(A,B)       scanf("%lld%lld",&A,&B)
#define SL3(A,B,C)     scanf("%lld%lld%lld",&A,&B,&C)

#define DI(X)          int X;     scanf("%d", &X)
#define DII(X,Y)       int X,Y;   scanf("%d%d", &X, &Y)
#define DIII(X,Y,Z)    int X,Y,Z; scanf("%d%d%d", &X, &Y, &Z)
#define DLI(X)         ll X;      scanf("%lld", &X)
#define DLII(X,Y)      ll X,Y;    scanf("%lld%lld", &X, &Y)
#define DLIII(X,Y,Z)   ll X,Y,Z;  scanf("%lld%lld%lld", &X, &Y, &Z)

#define FL(i,a,b)      for(int i=a-1; ++i<b;)
#define RFL(i,a,b)     for(int i=a; i>=b; i--)
#define FLI(i,a,b,inc) for(int i=a; i<b; i+=inc)
#define FLD(i,a,b,dec) for(int i=a; i>=b; i-=dec)
#define FLS(x)         for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)

#define PC(a)          printf("Case %d: ",a)
#define PCN(a)         printf("Case %d:\n",a)
#define PCH(a)         printf("Case #%d: ",a)

#define xx             first
#define yy             second
#define MP             make_pair

#define FILL(a,val)    memset(a,val,sizeof a)
#define SET(a)         FILL(a,-1)
#define CLR(a)         FILL(a,0)

#define LB(a,x)        lower_bound(ALL(a),x)-a.begin()
#define UB(a,x)        upper_bound(ALL(a),x)-a.begin()

#define PI(x)          printf("%d\n", x)
#define PL(x)          printf("%lld\n", x)
#define PU(x)          printf("%llu\n", x)
#define pi             2.0*acos(0.0)
#define EPS            1e-11
#define ALL(a)         a.begin(),a.end()
#define NL             printf("\n")
#define PB             push_back
#define PP             pop_back
#define PF(x)          push_front(x)
#define PPF(x)         pop_front()
#define PS(x)          push(x)
#define SZ(w)          w.size()
#define IN(a,x,y)      (a>=x && a<=y)
#define OUT(a,x,y)     (!in(a,x,y))
#define SUM(a,n)       accumulate(a,a+n,0)
#define CountBit(x)    __builtin_popcount(x)
#define Time()         printf("%lf\n", (double) clock()/CLOCKS_PER_SEC);
#define __cin_cout     ios_base::sync_with_stdio(false);cin.tie(NULL)

#define _MAX(a,b,c)    max(a,max(b,c))
#define _MIN(a,b,c)    min(a,min(b,c))
#define MXE(a,n)       *max_element(a,a+n)
#define MNE(a,n)       *min_element(a,a+n)
#define MXEV(a)        *max_element(ALL(a))
#define MNEV(a)        *min_element(ALL(a))

using namespace std;

template <typename T> T ExEuclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;} if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod(T p,T e,T m)          {ll ret=1LL;for(;e>0;e>>=1){if(e&1)ret=(ret*p)%m;p=(p*p)%m;}return (T)ret;}
template <typename T> T POW(T N,T P)                 {return (P==0)?1:N*POW(N,P-1);}
template <typename T> T GCD(T a,T b)                 {if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template <typename T> T LCM(T a,T b)                 {if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template <typename T> T ModInv(T b,T m)              {return BigMod(b,m-2,m);}
template <typename T> T DIS(T x1,T y1,T x2, T y2)    {return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
template <typename T> T Angle(T x1,T y1,T x2, T y2)  {return atan(double(y1-y2)/double(x1-x2));}
template <typename T> ll IsLeft(T a,T b,T c)         {return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }
template <typename T> T NextInt()                    {char ch;T n=0;bool ng=false;while(1){ch=getchar();if(ch=='-'){ng=true;ch = getchar();break;}if(ch>='0'&&ch<='9')break;}while(1){n=n*10+(ch-'0');ch=getchar();if(ch<'0'||ch>'9')break;}return (ng?-n:n);}

template < class T, class X > inline bool CheckBit(T a, X pos)  { T t=1;return (a&(t<<pos));     }
template < class T, class X > inline  T   OnBit(T a, X pos)     { T t=1;return (a|(t<<pos));     }
template < class T, class X > inline  T   OffBit(T a, X pos)    { T t=1;return (a&(~(t<<pos)));  }
template < class T, class X > inline  T   ToggleBit(T a, X pos) { T t=1;return (a^(t<<pos));     }

double DEG(double x)        { return (180.0*x)/(pi); }
double RAD(double x)        { return (x*(double)pi)/(180.0); }
string NTS(ll Number)       { stringstream ss;ss << Number;return ss.str();}
int ToInt(string s)         { int sm; stringstream ss(s); ss>>sm; return sm; }
long long ToLLInt(string s) { ll sm; stringstream ss(s); ss>>sm; return sm; }
bool IsVowel(char ch)       { ch=toupper(ch); if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return true; return false;}
bool IsConst(char ch)       { if (isalpha(ch) && !IsVowel(ch)) return true; return false; }
bool IsPrime(int w)         { if(w%2 == 0) return false;for(int q=3; q*q<=w; q+=2){ if(w%q==0) return false;} return true;}

///int dx[]={0,1,0,-1};int dy[]={1,0,-1,0};                       // 4 Direction
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};          // Year Derection
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2};     // Hexagonal Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};   // 8 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1}; // Knight Direction

typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<VI> VVI;
typedef vector<PII> VPI;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int inf = (1<<31)-1;
const ll INF = (1LL<<63)-1LL;

/**********************************************************************/
/// ////////////////////   LET'S START CODE    ///////////////////// ///
/**********************************************************************/

stack<double> sk;

double preFix(string s)
{
    double res=0.0;
    int len = s.size();

    for(int i=len-1; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9'){
            sk.push(s[i]-'0');
        }
        else{
            double op1, op2;

            op1 = sk.top();
            sk.pop();
            op2 = sk.top();
            sk.pop();

            if(s[i] == '+') res = op1+op2;
            else if(s[i] == '-') res = op1-op2;
            else if(s[i] == '*') res = op1*op2;
            else if(s[i] == '/') res = op1/op2;

            sk.push(res);
        }
    }


    return res;
}

int main(int argc, const char *argv[]) {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string p = "-9+*132";
    printf("%0.2lf\n", preFix(p));


    //fclose(stdout);
    return 0;
}


/*


*/
