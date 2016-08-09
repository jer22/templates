#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MOD = 1000000007;

int p[100005], ans[100005];
void init() {
	p[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		int j = 1;
		while (1) {
			int a = i - (j * (3 * j - 1)) / 2;
			int b = i - (j * (3 * j + 1)) / 2;
			if (a < 0 && b < 0) break;
			int c = ((j & 1) << 1) - 1;

			if (a >= 0) p[i] += c * p[a];
			p[i] %= MOD;
			if (b >= 0) p[i] += c * p[b];
			p[i] %= MOD;
			j++;
		}
		p[i] += MOD;
		p[i] %= MOD;
	}
}

int getans(int n, int lim) {
	int ans = p[n];
	int j = 1;
	while (1) {
		int a = n - lim * ((j * (3 * j - 1)) / 2);
		int b = n - lim * ((j * (3 * j + 1)) / 2);
		if (a < 0 && b < 0) break;
		int c = ((j & 1) << 1) - 1;
		if (a >= 0) ans -= c * p[a];
		ans %= MOD;
		if (b >= 0) ans -= c * p[b];
		ans %= MOD;
		j++;
	}
	ans += MOD;
	ans %= MOD;
	return ans;
}

int T, n, lim;
int main() {
	freopen("c.in", "r", stdin);
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &lim);
		int ans = getans(n, lim);
		printf("%d\n", ans);
	}


	return 0;
}
