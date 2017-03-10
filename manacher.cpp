char ss[MAXN << 1];
int p[MAXN << 1];
int manacher(char s[MAXN], int n) {
	int re = 0;
	ss[0] = '$', ss[1] = '#';
	for (int i = 1; i <= n; i++)
		ss[i << 1] = s[i], ss[i << 1 | 1] = '#';
	n = n << 1 | 1;
	int mx = 1, id = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = min(p[id + id - i], mx - i);
		while (ss[i + p[i]] == ss[i - p[i]])
			p[i]++;
		if (p[i] + i > mx)
			mx = p[i] + i, id = i;
		re += p[i] >> 1, re %= MOD;
	}
	return re;
}