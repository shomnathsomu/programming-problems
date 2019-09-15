#include<bits/stdc++.h>
using namespace std;

long long bigmod ( long long a, long long p, long long m ) /// (a^p)%m
{
    long long res = 1;
    long long x = a;

    while(p){
        if(p&1) { //p is odd
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}

int main(int argc, const char * argv[]) {

    cout << bigmod(10,9,1000000007) << endl;

    return 0;
}
