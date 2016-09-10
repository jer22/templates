int fa[MAXN][21], deep[MAXN];
void dfs(int x) {
	deep[x] = deep[fa[x][0]] + 1;
	for (int i = 1; i <= 16; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (int i = 0; i < edges[x].size(); i++) {
		int nex = edges[x][i];
		if (nex == fa[x][0]) continue;
		fa[nex][0] = x;
		dfs(nex);
	}
}

int LCA(int x, int y) {
	if (deep[x] < deep[y]) swap(x, y);
	int tmp = deep[x] - deep[y];
	for (int i = 0; i <= 16; i++)
		if ((1 << i) & tmp) x = fa[x][i];
	for (int i = 16; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	if (x == y) return x;
	return fa[x][0];
}