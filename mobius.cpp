long long mob[MAXN], p[1000000], check[MAXN], tot;
void getMob() {
	mob[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (!check[i]) {
			p[++tot] = i;
			mob[i] = -1;
		}
		for (int j = 1; j <= tot; j++) {
			if (i * p[j] > 1000000) break;
			check[i * p[j]] = 1;
			if (i % p[j] == 0) {
				mob[i * p[j]] = 0;
				break;
			}
			else mob[i * p[j]] = -mob[i];
		}
	}
}