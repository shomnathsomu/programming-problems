#include <bits/stdc++.h>
#define ll long long int
#define mx 100000
using namespace std;

struct lazyprop{
    ll prop, sum;
}tree[mx*3];

int arr[mx], n;

void segtree(int node, int b, int e)
{
    if(b == e){
        tree[node].sum += arr[b];
        return ;
    }

    segtree(node<<1, b, (b+e)>>1);
    segtree((node<<1)+1, ((b+e)>>1)+1, e);

    tree[node].sum = tree[node<<1].sum + tree[(node<<1)+1].sum;
}

int query(int node, int b, int e, int i, int j, int carry)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[node].sum + carry*(e-b+1);

    int q1 = query(node<<1, b, (b+e)>>1, i, j, carry+tree[node].prop);
    int q2 = query((node<<1)+1, ((b+e)>>1)+1, e, i, j, carry+tree[node].prop);

    return q1+q2;
}

void update(int node, int b, int e, int i, int j, int x)
{
    if(i > e || j < b) return ;
    if(b >= i && e <= j){
        tree[node].prop += x;
        tree[node].sum += (x*(e-b+1));
        return ;
    }

    update(node<<1, b, (b+e)>>1, i, j, x);
    update((node<<1)+1, ((b+e)>>1)+1, e, i, j, x);

    tree[node].sum = tree[node<<1].sum + tree[(node<<1)+1].sum + tree[node].prop * (e-b+1);
}

main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    segtree(1, 1, n);

    cout << query(1, 1, n, 2, 5, 0) << endl;

    update(1, 1, n, 2, 5, 3);

    cout << query(1, 1, n, 2, 5, 0) << endl;

    update(1, 1, n, 1, 3, 5);

    cout << query(1, 1, n, 1, 6, 0) << endl;

    return 0;
}

/*

6
1 2 3 4 5 6

*/
