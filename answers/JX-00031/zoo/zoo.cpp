#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
int n, m, z, k, cnt = 0, cptr = 0;
ull a[100050];
int h[70];
int c[100050];
struct guide {
    int q, nxt;
}g[100050];
ull l=0;
int read() {
    int n = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') if (ch == '-') {f = -1;ch = getchar();}
    while (ch >= '0' && ch <= '9') {n *= 10;n += (ch-'0');ch = getchar();}
    return f * n;
}
void build(int i, int j) {
    g[++cnt].q = j;
    g[cnt].nxt = h[i];
    h[i] = cnt;
}
bool half_search(int i) {
    int l = 1, r = cptr+1, mid;
    while (l+1 < r) {
        mid = (l+r+1) >> 1;
        if (c[mid] > i) r = mid;
        else if (c[mid] == i) return 1;
        else l = mid;
    }
    return c[l] == i;
}
int main() {
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
    n = read();m = read();z = read();k = read();
    for (int i = 1;i <= n;i++) a[i] = read();
    for (int i = 1;i <= m;i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        build(t1, t2);
    }
    for (int i = 1;i <= n;i++) l = l | a[i];
    int ptr = 0;
    while (l > 0) {
        if (l & 1)
            for (int j = h[ptr];j;j = g[j].nxt) c[++cptr] = g[j].q;
        l = l >> 1;ptr++;
    }
    sort(c+1, c+1+cptr);
    int t = k;
    for (int i = 0;i < k;i++) {
        for (int j = h[i];j;j = g[j].nxt) {
            if (!half_search(g[j].q)) {t--;break;}
        }
    }
    if (t == 64) cout << 0xFFFFFFFFFFFFFFFF - n + 1;
    else cout << ull(pow(2, t)) - n;
    fclose(stdin);fclose(stdout);
    return 0;
}
/*3 3 5 4
1 4 6
0 3
2 4
2 5*/
