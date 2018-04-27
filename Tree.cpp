#include<bits/stdc++.h>
using namespace std;

struct HTREEITEM{
    int id, pid;
    string name;
}node[1007];

map<int, HTREEITEM> mp;

int main()
{
    for(int i=1; i <= n; i++){
        if(node[i].pid == -1){
            HTREEITEM f = TreeViewControl.insertNode(node[i].name);
            mp[node[i].id] = f;
        }
        else{
            int idx = node[i].pid;
            HTREEITEM f = mp[idx].insertNode(node[i].name);
            mp[node[i].id] = f;
        }
    }
    return 0;
}
