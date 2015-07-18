#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int n;
int arr[MAXN];
int tot = 0;
int v[MAXN], tr[MAXN][2], dist[MAXN], siz[MAXN];
int root[MAXN];
int l[MAXN], r[MAXN];

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (v[x] < v[y]) swap(x, y);
    tr[x][1] = merge(tr[x][1], y);
    siz[x] = siz[tr[x][0]] + siz[tr[x][1]] + 1;
    if (dist[tr[x][1]] > dist[tr[x][0]]) swap(tr[x][0], tr[x][1]);
    dist[x] = dist[tr[x][1]] + 1;
    return x;
}

int top(int x) {
    return v[x];
}

int size(int x) {
    return siz[x];
}

void pop(int &x) {
    x = merge(tr[x][0], tr[x][1]);
}

int newNode(int x) {
    v[++tot] = x;
    siz[tot] = 1;
    tr[tot][0] = tr[tot][1] = dist[tot] = 0;
    return tot;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] -= i;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt++;
        root[cnt] = newNode(arr[i]);
        l[cnt] = r[cnt] = i;
        while (cnt > 1 && top(root[cnt]) < top(root[cnt - 1])) {
            cnt--;
            root[cnt] = merge(root[cnt], root[cnt + 1]);
            r[cnt] = r[cnt + 1];
            while (size(root[cnt]) * 2 > r[cnt] - l[cnt] + 2)
                pop(root[cnt]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
        int t = top(root[i]);
        for (int j = l[i]; j <= r[i]; j++) {
            ans += abs(t - arr[j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}