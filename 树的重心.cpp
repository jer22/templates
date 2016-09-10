struct E{
    int to, v;
    E() {}
    E(int a, int b) : to(a), v(b) {}
};
vector<E> edges[MAXN];
bool vis[MAXN];
int sz_down[MAXN];
void dfs(int x, int pre) {
	sz_down[x] = 1;
	for (int i = 0; i < edges[x].size(); i++) {
		int nex = edges[x][i].to;
		if (nex == pre) continue;
		if (vis[nex]) continue;
		dfs(nex, x);
		sz_down[x] += sz_down[nex];
	}
}
void dfs1(int x, int pre, int &max_num, int &idx, int root) {
	int cnt = 0;
	for (int i = 0; i < edges[x].size(); i++) {
		int nex = edges[x][i].to;
		if (nex == pre) continue;
		if (vis[nex]) continue;
		dfs1(nex, x, max_num, idx, root);
		cnt = max(cnt, sz_down[nex]);
	}
	cnt = max(cnt, sz_down[root] - sz_down[x]);
	if (cnt < max_num) {
		max_num = cnt;
		idx = x;
	}
}
int getroot(int x) {
	int max_num = 0x3f3f3f3f, idx;
	dfs(x, x);
	dfs1(x, x, max_num, idx, x);
	return idx;
}