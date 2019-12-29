/*
	Max Flow Algorithm
	Dinics Algo
	O(V^2*E)
*/
vii g[MAXN];
int cst[MAXN][MAXN];
int sink, src;
int dis[MAXN];
int bfs() {
	queue<int> q;
	int k,cur;
	
	q.push(src);	dis[src] = 0;
	while(!q.empty()) {
		cur = q.front();	q.pop();
		if(cur == sink)
			return true;
		forall(i, 0, g[cur].size()) {
			k = g[cur][i];
			if(cst[cur][k] > 0 && dis[k] == -1){
				dis[k] = dis[cur] +1;
				q.push(k);
			}
		}
	}
	return false;
}
ill dfs(int u, int fl) {

	int k;
	int mn;

	if(u == sink) return fl;
	forall(i, 0, g[u].size()) {
		k = g[u][i];
		if(cst[u][k] >0 && dis[k] == dis[u]+1) {
			mn = dfs(k, min(fl, cst[u][k]));
			if(mn > 0) {
				cst[u][k] -= mn;
				cst[k][u] += mn;
				return mn;
			}
		}
	}
	return 0;
}


ill dinics() {
	ill res = 0;
	ill df;
	while(bfs()) {
		while(true) {
			df = dfs(src, 2*(1e9) );
			// cout <<df <<endl;
			if(df > 0) res+= df;
			else break;
		}
		fill(dis, -1);
	}
	return res;
}
