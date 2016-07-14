long long CRT(long long a[], long long m[], int n) {
	long long MOD = 1;
	for(int i = 0;i < n; i++) MOD *= m[i];
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		long long x, y;
		long long tm = MOD / m[i];
		extend_gcd(tm, m[i], x, y);
		ans=(ans + tm * x * a[i]) % MOD;
	}
	return (ans + MOD) % MOD;
}