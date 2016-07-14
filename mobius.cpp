long long mob[MAXN];
void getMob() {
	for (int i = 1; i <= 100000; i++) {
		int target = (i == 1 ? 1 : 0);
		int delta = target - mob[i];
		mob[i] = delta;
		for (int j = i + i; j <= 100000; j += i)
			mob[j] += delta;
	}
}