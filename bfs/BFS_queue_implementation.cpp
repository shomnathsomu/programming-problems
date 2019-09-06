#include <stdio.h>
#define MAX 520000

struct Queue
{
    int arr[MAX],rear,Front;
    Queue()
    {
        for(int i=0; i<MAX; i++) arr[i]=0;
        rear = Front = - 1;
    }
    void push(int item)
    {
        if(Front == -1) Front = 0;
        arr[++rear] = item;
    }
    void pop()
    {
        Front++;
    }
    int front(){
        return arr[Front];
    }
    bool empty()
    {
        if(Front == -1 || Front > rear || (rear == MAX-1)) return true;
        return false;
    }
    void display()
    {
        int i;
        if(Front == - 1)
            printf("Queue is empty \n");
        else
        {
            printf("Queue is : \n");
            for (i = Front; i <= rear; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
    }
};

int node[1000][1000];
int vis[1000];

int BFS(int Start, int End)
{
    Queue q;
    q.push(Start);

    vis[Start] = 0;

    while(!q.empty())
    {
        int nxt = q.front();
        q.pop();

        for(int j = 0; j < 1000; j++)
        {
            if(!node[nxt][j]) continue;

            int temp = j;
            if(!vis[temp])
            {
                vis[temp] = vis[nxt] + 1;
                q.push(temp);
                if(temp == End) return vis[temp];
            }
        }
    }

    return 0;
}

int main()
{
    int num_edge;
    scanf("%d", &num_edge);

    for(int i = 0; i < num_edge; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        node[x][y]=1;
        node[y][x]=1;
    }

    int st, en;
    scanf("%d %d", &st, &en);

    int ans;
    ans = BFS(st, en);

    printf("%d\n", ans);

    return 0;
}

/*

14
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
1 11

*/

