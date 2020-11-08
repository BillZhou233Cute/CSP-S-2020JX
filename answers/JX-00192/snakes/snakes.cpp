#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull t, n, k, a[1000005], hp[1000005], xx, yy;

ull jaja()
{
    ull id1 = 1;
    if (hp[2] > hp[1]) id1 = 2;
    if (hp[3] > hp[id1]) id1 = 3;
    ull id2 = 3;
    if (hp[2] < hp[3]) id2 = 2;
    if (hp[1] < hp[id2]) id2 = 1;
    bool have[4];
    have[0] = true;
    have[id1] = true;
    have[id2] = true;
    ull id3 = 0;
    while(have[id3]) ++id3;
    if (hp[id1] - hp[id2] > hp[id3]) return 1;
    else return 3;
}

int main()
{
    // This is CSP-S 2020 T4 by BillZhou233
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    cin >> t >> n;
    for (register ull i = 1; i <= n; ++i) {cin >> a[i]; hp[i] = a[i];}
    cout << jaja() << endl;
    for (register ull i = 1; i < t; ++i)
    {
        cin >> k;
        for (register ull j = 1; j <= n; ++j) hp[j] = 0;
        for (register ull j = 0; j < k; ++j)
        {
            cin >> xx >> yy;
            hp[xx] = yy;
        }
        for (register ull j = 1; j <= n; ++j) hp[j] = (hp[j])? hp[j]: a[j];
        cout << jaja() << endl;
    }
    fclose(stdin); fclose(stdout);
    return 0;
}
