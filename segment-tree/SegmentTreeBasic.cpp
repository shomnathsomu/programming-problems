#include <bits/stdc++.h>
using namespace std;

#define mx 100008

int arr[mx];
int tree[mx*3];

void segtree(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    int Left = 2*node;
    int Right = 2*node+1;
    int mid = (b+e)/2;

    segtree(Left, b, mid);
    segtree(Right, mid+1, e);

    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if(b >= i && e <= j) return tree[node];
    if(i > e || j < b) return 0;

    int Left = 2*node;
    int Right = 2*node+1;
    int mid = (b+e)/2;

    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid+1, e, i, j);

    return p1+p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if(i > e || i < b) return;
    if(b >= i && e <= i) /// or if(b == e)
    {
        tree[node] = newvalue;
        return;
    }

    int Left = 2*node;
    int Right = (2*node)+1;
    int mid = (b+e)/2;

    update(Left, b, mid, i, newvalue);
    update(Right, mid+1, e, i, newvalue);

    tree[node] = tree[Left] + tree[Right];
}

main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) cin >> arr[i];

    segtree(1, 1, n);

    cout << query(1, 1, n, 1, 6) << endl;
    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 5, 3);
    cout << query(1, 1, n, 2, 5) << endl;

    return 0;
}

/*

6
1 2 3 4 5 6

*/
