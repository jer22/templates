#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 250005;

	// int p, q, np, nq;
int cnt, last;
int tr[MAXN << 1][26], maxlen[MAXN << 1], slink[MAXN << 1], minlen[MAXN << 1];

void extend(int c) {
	int p = last;
	int np = last = ++cnt;
	maxlen[np] = maxlen[p] + 1;
	while (!tr[p][c] && p) tr[p][c] = np, p = slink[p];
	if (!p) slink[np] = 1, minlen[np] = 1;
	else {
		int q = tr[p][c];
		if (maxlen[p] + 1 == maxlen[q]) slink[np] = q, minlen[np] = maxlen[q] + 1;
		else {
			int nq = ++cnt;
			maxlen[nq] = maxlen[p] + 1;
			memcpy(tr[nq], tr[q], sizeof(tr[q]));
			slink[nq] = slink[q];
			slink[np] = slink[q] = nq;
			minlen[np] = minlen[q] = maxlen[nq] + 1;
			while (tr[p][c] == q) tr[p][c] = nq, p = slink[p];
			minlen[nq] = maxlen[slink[nq]] + 1;
		}
	}
}

void build(char *str) {
	int ll = strlen(str);
	for (int i = 0; i < ll; i++)
		extend(str[i] - 'a');
}

char a[MAXN], b[MAXN];
int main() {
	freopen("a.in", "r", stdin);
	scanf("%s", a);
	scanf("%s", b);
	cnt = last = 1;
	build(a);

	return 0;
}
