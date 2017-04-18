template <class T>
T exgcd(T a, T b, T &x, T &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	T t, ret;
	ret = exgcd(b, a % b, x, y);
	t = x, x = y, y = t - a / b * y;
	return ret;
}