void extend_kmp() {
	int p, r = nex[0] = lent;
	for (int i = 1, j = -1; i < lent; ++i, --j) {
		if (j == -1 || i + nex[i - p] >= r) {
			if (j == -1) r = i, j = 0;
			while (r < lent && t[r] == t[j]) ++r, ++j;
			nex[i] = j;
			p = i;
		} else nex[i] = nex[i - p];
	}
	for (int i = 0, j = -1; i < lens; ++i, --j) {
		if (j == -1 || i + nex[i - p] >= r) {
			if (j == -1) r = i, j = 0;
			while (r < lens && j < lent && s[r] == t[j]) ++r, ++j;
			ext[i] = j;
			p = i;
		} else ext[i] = nex[i - p];
	}
}