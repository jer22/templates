void init() {
	phi[1] = 1;
	for (int i = 2; i < MAXN - 1; i++) {
		if (!vis[i]) {
			minfac[i] = i;
			prime[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot; j++) {
			if(i * prime[j] > MAXN) break;
			vis[i * prime[j]] = 1;
			minfac[prime[j] * i] = prime[j];
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	for (int i = 2; i < MAXN - 1; i++) {
		int x = i;
		while (x > 1) {
			long long t = minfac[x];
			fac[i].push_back(t);
			while (!(x % t)) x /= t;
		}
	}
}