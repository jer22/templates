int fac[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(int s[], int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		int num = 0;
		for (int j = i + 1; j < len; j++)
		if (s[j] < s[i]) num++;
		sum += (num * fac[9 - i - 1]);
	}
	return sum + 1;
}