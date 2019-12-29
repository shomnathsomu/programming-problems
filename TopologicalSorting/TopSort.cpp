  int n, m;
set<int> g[10001];
int indeg[10001];
int o[10001];
set<int> se;
inline 
void solve() {
	int idx = 0;
	int cur;
	int k;
	forall(i, 0, n) {
		if(indeg[i] == 0)
			se.insert(i);
	}
	while(!se.empty()) {
		cur = *se.begin(); 
		se.erase(se.begin());

		o[idx++] = cur;
		while(!g[cur].empty()) {
			k = *g[cur].begin();
			// cout<<idx<<endl;
			g[cur].erase(g[cur].begin());
			indeg[k]--;
			if(indeg[k] == 0)
				se.insert(k);
		
		}
	}


	forall(i, 0, n)
		printf("%d ", o[i]+1);
	printf("\n");
}
