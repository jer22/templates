const int MAXN = 270005;
const long long G = 3;
const long long P = 4179340454199820289LL; // 29 * (2 ^ 57), 4e18, g = 3
// const long long P = 50000000001507329LL; //190734863287 * 2 ^ 18 + 1, g = 3
//const long long P = 1945555039024054273LL; // 27 * (2 ^ 56), 1e18, g = 5
// const long long P = 1004535809; // 479 * 2 ^ 21 + 1, g = 3
//const long long P = 998244353; // 119 * 2 ^ 23 + 1, g = 3
//const long long P = 104857601; //g = 3

int T, n;
long long mul(long long x, long long y) {
	return (x * y - (long long)(x / (long double)P * y + 1e-3) * P + P) % P;
}
long long qpow(long long x, long long k, long long p){
	long long ret = 1;
	while (k) {
		if (k & 1) ret = mul(ret, x);
		k >>= 1;
		x = mul(x, x);
	}
	return ret;
}
long long wn[25];
void getwn(){
	for (int i = 1; i <= 18; i++) {
		int t = 1 << i;
		wn[i] = qpow(G, (P - 1) / t, P);
	}
}
int len;
int rev[MAXN];
long long w[MAXN];
void set(){
    for(int i = 0; i < len; i++){
        int cur=0;
        for(int j=1,x=i;j<len;j<<=1,x>>=1)cur=(cur<<1)+(x&1);
        rev[i]=cur;
    }
    w[0]=1;w[1]=qpow(G,(P-1)/len, P);
    for(int i = 2; i <= len; i++)w[i]=mul(w[i-1], w[1])%P;
}
long long v[MAXN];
void NTT(long long *y,int sig){
    for(int i=0; i < len; i++)v[rev[i]]=y[i];
    for(int i=2,tot=len,hal,cur;i<=len;i<<=1){
        tot>>=1,cur=sig?len:0,hal=i>>1;
        for(int j=0;j<hal;j++){
            for(int k=j,wi=w[cur];k<len;k+=i){
                long long u=v[k],r=mul(v[k+hal],wi)%P;
                v[k]=(u+r)%P;
                v[k+hal]=(u+P-r)%P;
            }
            sig?cur-=tot:cur+=tot;
        }
    }
    for(int i=0;i < len; i++)y[i]=v[i];
    if (sig == 1) {
		long long inv = qpow(len, P - 2, P);
		for (int i = 0; i < len; i++) y[i] = mul(y[i], inv);
	}
}
void Convolution(long long A[], long long B[], int n){
	for(len = 1; len < (n << 1); len <<= 1);
	for(int i = n; i < len; i++)
		A[i] = B[i] = 0;
	
	NTT(A, 0); NTT(B, 0);
	for(int i = 0; i < len; i++){
		A[i] = mul(A[i], B[i]);
	}
	NTT(A, 1);
}
