void dfs(int u) {
	s.push(u);
	vis[u] = 1;
	dfn[u] = low[u] = ++cnt;
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		num++;
		do {
			t = s.top();
			s.pop();
			vis[t] = 0;
			col[t] = num;
		} while (t != u);
	}
}

bool tarjan() {
	cnt = num = 0;
	while (!s.empty()) s.pop();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));
	memset(col, 0, sizeof(col));
	for (int i = 0; i < n << 1; i++)
		if (!dfn[i]) dfs(i);
	for (int i = 0; i < n; i++)
		if (col[i] == col[i + n]) return false;
	return true;
}