void getphi() {
	phi = M;
	int a = M;
	for(int i = 2; i * i <= a; i++){
		if (!(a % i)){
			phi = phi / i * (i - 1);
			while(!(a % i)) a /= i;
		}
	}
	if (a > 1) phi = phi / a * (a - 1);
}