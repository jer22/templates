int n;
int cnt, last;
int tr[MAXN << 1][26], maxlen[MAXN << 1], slink[MAXN << 1];
int siz[MAXN << 1];

void extend(int c) {
	int p = last;
	int np = last = ++cnt;
	maxlen[np] = maxlen[p] + 1;
	siz[np] = 1;
	while (!tr[p][c] && p) tr[p][c] = np, p = slink[p];
	if (!p) slink[np] = 1;
	else {
		int q = tr[p][c];
		if (maxlen[p] + 1 == maxlen[q]) slink[np] = q;
		else {
			int nq = ++cnt;
			maxlen[nq] = maxlen[p] + 1;
			memcpy(tr[nq], tr[q], sizeof(tr[q]));
			slink[nq] = slink[q];
			slink[np] = slink[q] = nq;
			while (tr[p][c] == q) tr[p][c] = nq, p = slink[p];
		}
	}
}
int tp[MAXN << 1], c[MAXN];

void build(char *str) {
	cnt = last = 1;
	n = strlen(str);
	for (int i = 0; i < n; i++)
		extend(str[i] - 'a');
	for (int i = 1; i <= cnt; i++) c[maxlen[i]]++;
	for (int i = 1; i <= n; i++) c[i] += c[i - 1];
	for (int i = cnt; i; i--) tp[c[maxlen[i]]--] = i;
	for (int i = cnt; i; --i) {
		int t = tp[i];
		siz[slink[t]] += siz[t];
	}
}
