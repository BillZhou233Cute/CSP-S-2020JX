#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull n, m, c, k, a[1000005], p, q, haveBit[64], usedBit[64], tmp1, tmp2;

int main()
{
    // This is CSP-S 2020 T2 by BillZhou233
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
    cin >> n >> m >> c >> k;
    for (register ull i = 0; i < n; ++i)
    {
        cin >> a[i];
        tmp1 = a[i];
        tmp2 = 0;
        while (tmp1)
        {
            if (tmp1 % 2) haveBit[tmp2] = 1;
            tmp1 = (tmp1 >> 1);
            ++tmp2;
        }
    }
    for (register ull i = 0; i < m; ++i)
    {
        cin >> p >> q;
        usedBit[p] = 1;
    }
    tmp1 = 0;
    for (register ull i = 0; i < k; ++i)
    {
        if (haveBit[i] || !(usedBit[i])) ++tmp1;
    }
    tmp2 = (1 << tmp1);
    cout << tmp2 - n << endl;
    fclose(stdin); fclose(stdout);
    return 0;
}
