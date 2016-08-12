struct matrix {
	int n, m;
	int a[MAXN][MAXN];
	inline void init(const int &tn, const int &tm) {
		n = tn;
		m = tm;
		memset(a, 0, sizeof(a));
	}
}origin;

inline matrix operator * (matrix a, matrix b) {
	if (a.m != b.n) {
		printf("error");
	}
	matrix c;
	c.init(a.n, b.m);
	int i, j, k;
	for (i = 0; i < a.n; i++) {
		for (k = 0; k < a.m; k++) {
			if (!a.a[i][k]) continue;
			for (j = 0; j < b.m; j++) {
				c.a[i][j] += a.a[i][k] * b.a[k][j];
			}
		}
	}
	return c;
}

inline matrix pow(matrix a, int x) {
	matrix res;
	res.init(a.n, a.m);
	for (int i = 0; i < a.n; i++) {
		res.a[i][i] = 1;
	}
	while (x) {
		if (x & 1) {
			res = res * a;
		}
		x >>= 1;
		a = a * a;
	}
	return res;
}
