const int MAX = 30000 + 10;
const int maxn = 50000 + 10;
const int N = 12 + 10;
int n, m, index, size[2], bit[N];
int head[MAX], next[maxn];
long long dp[2][maxn], state[2][maxn], sum;
char mp[N][N];

void HashCalState(long long s, long long num){
    int pos = s % MAX;
    for (int i = head[pos]; i != -1; i = next[i]) {
        if (state[index][i] == s) {
            dp[index][i] += num;
            return;
        }
    }
    state[index][size[index]] = s;
    dp[index][size[index]] = num;
    //头插法
    next[size[index]] = head[pos];
    head[pos] = size[index]++;
}

void DP() {
    sum = 0;
    index = 0;
    size[index] = 1;
    state[index][0] = 0;
    dp[index][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int k = 0; k < size[index]; ++k) state[index][k] <<= 2;
        for (int j = 1; j <= m; ++j) {
            index = index ^ 1;
            memset(head, -1, sizeof head);
            size[index] = 0;
            for (int k = 0; k < size[index ^ 1]; ++k) {
                long long s = state[index ^ 1][k];
                long long num = dp[index ^ 1][k];
                int p = (s >> bit[j - 1]) % 4;
                int q = (s >> bit[j]) % 4;
                if (mp[i][j] == 'X') {//需要绕过
                    if (!p && !q) HashCalState(s, num);
                } else if (!p && !q) {
                    if (mp[i][j] == '*') HashCalState(s, num);
                    if (mp[i][j + 1] == 'X' || mp[i + 1][j] == 'X') continue;
                    s = s + (1 << bit[j - 1]) + 2 * (1 << bit[j]);
                    HashCalState(s, num);
                } else if (!p && q) {
                    if (mp[i][j + 1] != 'X') HashCalState(s, num);
                    if (mp[i + 1][j] != 'X'){
                        s = s + q * (1 << bit[j -1]) – q * (1 << bit[j]);
                        HashCalState(s, num);
                    }
                } else if (p && !q) {
                    if (mp[i + 1][j] != 'X') HashCalState(s, num);
                    if (mp[i][j + 1] != 'X'){
                        s = s – p * (1 << bit[j - 1]) + p * (1 << bit[j])
                        HashCalState(s, num);
                    }
                } else if (p == 1 && q == 1) {
                    int b = 1;
                    for (int t = j + 1; t <= m; ++t) {
                        int v = (s >> bit[t]) % 4;
                        if (v == 1) ++b;
                        if (v == 2) --b;
                        if (!b) {
                            s = s + (1 << bit[t]) – 2 * (1 << bit[t]);
                            break;
                        }
                    }
                    s = s - (1 << bit[j - 1]) - (1 << bit[j]);
                    HashCalState(s, num);
                } else if (p == 2 && q == 2) {
                    int b = 1;
                    for (int t = j - 2; t >= 0; --t) {
                        int v = (s >> bit[t]) % 4;
                        if (v == 2) ++b;
                        if (v == 1) --b;
                        if (!b) {
                            s = s - (1 << bit[t]) + 2 * (1 << bit[t]);
                            break;
                        }
                    }
                    s = s – 2 * (1 << bit[j - 1]) – 2 * (1 << bit[j]);
                    HashCalState(s, num);
                } else if (p == 1 && q == 2) {//成环
                    if (i == ex && j < ey) continue;
                    if (i < ex) continue;
                    s = s - (1 << bit[j - 1]) – 2 * (1 << bit[j]);
                    if (!s) sum += num;
                } else if (p == 2 && q == 1) {
                    s = s – 2 * (1 << bit[j - 1]) - (1 << bit[j]);
                    HashCalState(s, num);
                }
            }
        }
    }
}
