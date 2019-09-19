int parent[100007];

int unionfind(int i) 
{
    if (parent[i] == i) return i;
    return unionfind(parent[i]);
}