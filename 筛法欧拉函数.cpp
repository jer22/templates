int phi[1005];

void getPhi() {
	phi[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (phi[i]) continue;
		for (int j = i; j <= 1000; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
	}
}