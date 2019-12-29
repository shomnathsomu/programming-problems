efine MAXN 121
vector<vii > g;
vii used;
vii pl, pr;
bool kuhn(int v) {
	int k;
	if(used[v]) return false;
	used[v] = true;

	forall(i, 0, g[v].size()) {
		k = g[v][i]- MAXN;
		if(pr[k] == -1 || kuhn(pr[k])){
			pr[k] = v;
			pl[v] = k;
			return true;
		}
	}
	return false;
}
int match() {
	bool pathFound;
	pl = vii(MAXN, -1);
	pr = vii(MAXN, -1);
	used.resize(MAXN);

	do {
		pathFound = false;
		fill(used.begin(), used.end(),  0);

		forall(i, 0, MAXN) {
			if(!used[i] && pl[i] <0){
				pathFound |= kuhn(i);

			}
		}

	}while(pathFound);

	int cnt = 0;
	forall(i, 0, MAXN)
		if(pl[i] != -1)
			cnt++;

	printf("%d\n", cnt);
	return cnt;
}
