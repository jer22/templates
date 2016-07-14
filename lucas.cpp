long long power(long long a,long long i,long long p) {
	if (i == 0) return 1 % p;
	long long ans = 1;
	long long base = a;
	while (i) {
		if (i & 1) (ans *= base) %= p;
		(base *= base) %= p;
		i >>= 1;
	}
	return ans;
}

long long Comb(long long a, long long b, long long p) {
	if (a < b) return 0;
	if (a == b) return 1;
	if (b > a - b) b = a - b;
	long long ans = 1, ca = 1, cb = 1;
	for (long long i = 0; i < b; ++i) {
		ca = (ca * (a - i)) % p;
		cb = (cb * (b - i)) % p;
	}
	ans = (ca * power(cb, p - 2, p)) % p;
	return ans;
}

long long Lucas(int n, int m, int p) {
	long long ans = 1;
	while(n!=0 && m!=0) {
		ans = (ans * Comb(n % p, m % p, p)) % p;
		 n /= p;
		 m /= p;
	}
	return ans;
}


